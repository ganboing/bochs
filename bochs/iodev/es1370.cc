/////////////////////////////////////////////////////////////////////////
// $Id$
/////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) 2011  The Bochs Project
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
/////////////////////////////////////////////////////////////////////////

// ES1370 soundcard support ported from Qemu

// Define BX_PLUGGABLE in files that can be compiled into plugins.  For
// platforms that require a special tag on exported symbols, BX_PLUGGABLE
// is used to know when we are exporting symbols and when we are importing.
#define BX_PLUGGABLE

#include "iodev.h"
#if BX_SUPPORT_PCI && BX_SUPPORT_ES1370

#include "pci.h"
#include "es1370.h"
#include "soundmod.h"
#include "soundlnx.h"
#include "soundwin.h"
#include "soundosx.h"

#define LOG_THIS theES1370Device->

bx_es1370_c* theES1370Device = NULL;

const Bit8u es1370_iomask[64] = {7, 1, 3, 1, 7, 1, 3, 1, 1, 3, 1, 0, 7, 0, 0, 0,
                                 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
                                 7, 1, 3, 1, 6, 0, 2, 0, 6, 0, 2, 0, 6, 0, 2, 0,
                                 4, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0};

#define ES1370_CTL            0x00
#define ES1370_STATUS         0x04
#define ES1370_UART_DATA      0x08
#define ES1370_UART_STATUS    0x09
#define ES1370_UART_CTL       0x09
#define ES1370_UART_TEST      0x0a
#define ES1370_MEMPAGE        0x0c
#define ES1370_CODEC          0x10
#define ES1370_SCTL           0x20
#define ES1370_DAC1_SCOUNT    0x24
#define ES1370_DAC2_SCOUNT    0x28
#define ES1370_ADC_SCOUNT     0x2c

#define ES1370_DAC1_FRAMEADR  0xc30
#define ES1370_DAC1_FRAMECNT  0xc34
#define ES1370_DAC2_FRAMEADR  0xc38
#define ES1370_DAC2_FRAMECNT  0xc3c
#define ES1370_ADC_FRAMEADR   0xd30
#define ES1370_ADC_FRAMECNT   0xd34
#define ES1370_PHA_FRAMEADR   0xd38
#define ES1370_PHA_FRAMECNT   0xd3c

#define STAT_INTR       0x80000000
#define STAT_DAC1       0x00000004
#define STAT_DAC2       0x00000002
#define STAT_ADC        0x00000001

#define SCTRL_R1INTEN     0x00000400
#define SCTRL_P2INTEN     0x00000200
#define SCTRL_P1INTEN     0x00000100

#define DAC1_CHANNEL 0
#define DAC2_CHANNEL 1
#define ADC_CHANNEL  2

const char chan_name[3][5] = {"DAC1", "DAC2", "ADC"};
const Bit16u dac1_freq[4] = {5512, 11025, 22050, 44100};
const Bit16u ctl_ch_en[3] = {0x0040, 0x0020, 0x0010};
const Bit16u sctl_ch_pause[3] = {0x0800, 0x1000, 0x0000};
const Bit16u sctl_loop_sel[3] = {0x2000, 0x4000, 0x8000};

int libes1370_LTX_plugin_init(plugin_t *plugin, plugintype_t type, int argc, char *argv[])
{
  theES1370Device = new bx_es1370_c();
  BX_REGISTER_DEVICE_DEVMODEL(plugin, type, theES1370Device, BX_PLUGIN_ES1370);
  return 0; // Success
}

void libes1370_LTX_plugin_fini(void)
{
  delete theES1370Device;
}

bx_es1370_c::bx_es1370_c()
{
  put("E1370");

  s.dac1_timer_index = BX_NULL_TIMER_HANDLE;
  s.dac2_timer_index = BX_NULL_TIMER_HANDLE;
  s.adc_timer_index = BX_NULL_TIMER_HANDLE;
}

bx_es1370_c::~bx_es1370_c()
{
  if (s.dac2_outputinit) {
    soundmod->closewaveoutput();
  }
  delete soundmod;

  BX_DEBUG(("Exit"));
}

void bx_es1370_c::init(void)
{
  BX_ES1370_THIS s.devfunc = 0x00;
  DEV_register_pci_handlers(this, &BX_ES1370_THIS s.devfunc, BX_PLUGIN_ES1370,
                            "Experimental ES1370 soundcard");

  for (unsigned i=0; i<256; i++) {
    BX_ES1370_THIS s.pci_conf[i] = 0x0;
  }
  BX_ES1370_THIS s.base_ioaddr = 0;

  DEV_sound_init_module("default", &BX_ES1370_THIS soundmod, BX_ES1370_THIS_PTR);
  BX_ES1370_THIS s.dac2_outputinit = 0;

  if (BX_ES1370_THIS s.dac1_timer_index == BX_NULL_TIMER_HANDLE) {
    BX_ES1370_THIS s.dac1_timer_index = bx_pc_system.register_timer
      (BX_ES1370_THIS_PTR, es1370_timer_handler, 1, 1, 0, "es1370.dac1");
    // DAC1 timer: inactive, continuous, frequency variable
  }
  if (BX_ES1370_THIS s.dac2_timer_index == BX_NULL_TIMER_HANDLE) {
    BX_ES1370_THIS s.dac2_timer_index = bx_pc_system.register_timer
      (BX_ES1370_THIS_PTR, es1370_timer_handler, 1, 1, 0, "es1370.dac2");
    // DAC2 timer: inactive, continuous, frequency variable
  }
  if (BX_ES1370_THIS s.adc_timer_index == BX_NULL_TIMER_HANDLE) {
    BX_ES1370_THIS s.adc_timer_index = bx_pc_system.register_timer
      (BX_ES1370_THIS_PTR, es1370_timer_handler, 1, 1, 0, "es1370.adc");
    // ADC timer: inactive, continuous, frequency variable
  }

  BX_INFO(("ES1370 initialized"));
}

void bx_es1370_c::reset(unsigned type)
{
  unsigned i;

  static const struct reset_vals_t {
    unsigned      addr;
    unsigned char val;
  } reset_vals[] = {
    { 0x00, 0x74 }, { 0x01, 0x12 },
    { 0x02, 0x00 }, { 0x03, 0x50 },
    { 0x04, 0x05 }, { 0x05, 0x00 },	// command_io
    { 0x06, 0x00 }, { 0x07, 0x04 },	// status
    { 0x08, 0x00 },                 // revision number
    { 0x09, 0x00 },                 // interface
    { 0x0a, 0x01 },                 // class_sub
    { 0x0b, 0x04 },                 // class_base Multimedia Audio Device
    { 0x0e, 0x00 },                 // header type generic
    // address space 0x10 - 0x13
    { 0x10, 0x01 }, { 0x11, 0x00 },
    { 0x12, 0x00 }, { 0x13, 0x00 },
    { 0x2c, 0x42 }, { 0x2d, 0x49 }, // subsystem vendor
    { 0x2e, 0x4c }, { 0x2f, 0x4c }, // subsystem id
    { 0x3c, 0x00 },                 // IRQ
    { 0x3d, BX_PCI_INTA },          // INT
    { 0x3e, 0x0c },                 // min_gnt
    { 0x3f, 0x80 },                 // max_lat

  };
  for (i = 0; i < sizeof(reset_vals) / sizeof(*reset_vals); ++i) {
      BX_ES1370_THIS s.pci_conf[reset_vals[i].addr] = reset_vals[i].val;
  }

  BX_ES1370_THIS s.ctl = 1;
  BX_ES1370_THIS s.status = 0x60;
  BX_ES1370_THIS s.mempage = 0;
  BX_ES1370_THIS s.codec = 0;
  BX_ES1370_THIS s.sctl = 0;
  for (i = 0; i < 3; i++) {
    BX_ES1370_THIS s.chan[i].scount = 0;
    BX_ES1370_THIS s.chan[i].leftover = 0;
  }

  // Deassert IRQ
  set_irq_level(0);
}

void bx_es1370_c::register_state(void)
{
  unsigned i;
  char chname[6];

  bx_list_c *list = new bx_list_c(SIM->get_bochs_root(), "es1370", "ES1370 State", 9);
  for (i = 0; i < 3; i++) {
    sprintf(chname, "chan%d", i);
    bx_list_c *chan = new bx_list_c(list, chname, "", 5);
    BXRS_HEX_PARAM_FIELD(chan, shift, BX_ES1370_THIS s.chan[i].shift);
    BXRS_HEX_PARAM_FIELD(chan, leftover, BX_ES1370_THIS s.chan[i].leftover);
    BXRS_HEX_PARAM_FIELD(chan, scount, BX_ES1370_THIS s.chan[i].scount);
    BXRS_HEX_PARAM_FIELD(chan, frame_addr, BX_ES1370_THIS s.chan[i].frame_addr);
    BXRS_HEX_PARAM_FIELD(chan, frame_cnt, BX_ES1370_THIS s.chan[i].frame_cnt);
  }
  BXRS_HEX_PARAM_FIELD(list, ctl, BX_ES1370_THIS s.ctl);
  BXRS_HEX_PARAM_FIELD(list, status, BX_ES1370_THIS s.status);
  BXRS_HEX_PARAM_FIELD(list, mempage, BX_ES1370_THIS s.mempage);
  BXRS_HEX_PARAM_FIELD(list, codec, BX_ES1370_THIS s.codec);
  BXRS_HEX_PARAM_FIELD(list, sctl, BX_ES1370_THIS s.sctl);

  register_pci_state(list, BX_ES1370_THIS s.pci_conf);
}

void bx_es1370_c::after_restore_state(void)
{
  if (DEV_pci_set_base_io(BX_ES1370_THIS_PTR, read_handler, write_handler,
                          &BX_ES1370_THIS s.base_ioaddr,
                          &BX_ES1370_THIS s.pci_conf[0x10],
                          64, &es1370_iomask[0], "ES1370")) {
    BX_INFO(("new base address: 0x%04x", BX_ES1370_THIS s.base_ioaddr));
  }
}

// static IO port read callback handler
// redirects to non-static class handler to avoid virtual functions

Bit32u bx_es1370_c::read_handler(void *this_ptr, Bit32u address, unsigned io_len)
{
#if !BX_USE_ES1370_SMF
  bx_es1370_c *class_ptr = (bx_es1370_c *) this_ptr;
  return class_ptr->read(address, io_len);
}

Bit32u bx_es1370_c::read(Bit32u address, unsigned io_len)
{
#else
  UNUSED(this_ptr);
#endif // !BX_USE_ES1370_SMF
  Bit32u val = 0x0, shift;
  Bit16u offset;
  unsigned i;

  BX_DEBUG(("register read from address 0x%04x - ", address));

  offset = address - BX_ES1370_THIS s.base_ioaddr;
  if (offset >= 0x30) {
    offset |= (BX_ES1370_THIS s.mempage << 8);
  }
  shift = (offset & 3) << 3;

  switch (offset & ~3) {
    case ES1370_CTL:
      val = BX_ES1370_THIS s.ctl >> shift;
      break;
    case ES1370_STATUS:
      val = BX_ES1370_THIS s.status >> shift;
      break;
    case ES1370_UART_DATA:
    case ES1370_UART_STATUS:
    case ES1370_UART_TEST:
      BX_ERROR(("reading from UART not supported yet"));
      break;
    case ES1370_MEMPAGE:
      val = BX_ES1370_THIS s.mempage;
      break;
    case ES1370_CODEC:
      val = BX_ES1370_THIS s.codec;
      break;
    case ES1370_SCTL:
      val = BX_ES1370_THIS s.sctl >> shift;
      break;
    case ES1370_DAC1_SCOUNT:
    case ES1370_DAC2_SCOUNT:
    case ES1370_ADC_SCOUNT:
      i = (offset - ES1370_DAC1_SCOUNT) / 4;
      val = BX_ES1370_THIS s.chan[i].scount >> shift;
      break;
    case ES1370_DAC1_FRAMEADR:
      val = BX_ES1370_THIS s.chan[0].frame_addr;
      break;
    case ES1370_DAC2_FRAMEADR:
      val = BX_ES1370_THIS s.chan[1].frame_addr;
      break;
    case ES1370_ADC_FRAMEADR:
      val = BX_ES1370_THIS s.chan[2].frame_addr;
      break;
    case ES1370_DAC1_FRAMECNT:
      val = BX_ES1370_THIS s.chan[0].frame_cnt;
      break;
    case ES1370_DAC2_FRAMECNT:
      val = BX_ES1370_THIS s.chan[1].frame_cnt;
      break;
    case ES1370_ADC_FRAMECNT:
      val = BX_ES1370_THIS s.chan[2].frame_cnt;
      break;
    case ES1370_PHA_FRAMEADR:
      BX_ERROR(("reading from phantom frame address"));
      val = ~0U;
      break;
    case ES1370_PHA_FRAMECNT:
      BX_ERROR(("reading from phantom frame count"));
      val = ~0U;
      break;
    default:
      val = ~0U; // keep compiler happy
      BX_ERROR(("unsupported io read from offset=0x%04x!", offset));
      break;
  }

  BX_DEBUG(("val =  0x%08x", val));

  return(val);
}

// static IO port write callback handler
// redirects to non-static class handler to avoid virtual functions

void bx_es1370_c::write_handler(void *this_ptr, Bit32u address, Bit32u value, unsigned io_len)
{
#if !BX_USE_ES1370_SMF
  bx_es1370_c *class_ptr = (bx_es1370_c *) this_ptr;

  class_ptr->write(address, value, io_len);
}

void bx_es1370_c::write(Bit32u address, Bit32u value, unsigned io_len)
{
#else
  UNUSED(this_ptr);
#endif // !BX_USE_ES1370_SMF
  Bit16u  offset;
  Bit32u shift, mask;
  unsigned i;

  BX_DEBUG(("register write to address 0x%04x - ", address));

  offset = address - BX_ES1370_THIS s.base_ioaddr;
  if (offset >= 0x30) {
    offset |= (BX_ES1370_THIS s.mempage << 8);
  }
  shift = (offset & 3) << 3;

  switch (offset & ~3) {
    case ES1370_CTL:
      mask = (0xffffffff >> ((4 - io_len) << 3)) << shift;
      value = (BX_ES1370_THIS s.ctl & ~mask) | ((value << shift) & mask);
      BX_ES1370_THIS update_voices(value, BX_ES1370_THIS s.sctl);
      break;
    case ES1370_UART_DATA:
    case ES1370_UART_CTL:
    case ES1370_UART_TEST:
      BX_ERROR(("writing to UART not supported yet"));
      break;
    case ES1370_MEMPAGE:
      BX_ES1370_THIS s.mempage = value & 0x0f;
      break;
    case ES1370_CODEC:
      BX_ES1370_THIS s.codec = value & 0xffff;
      BX_DEBUG(("writing to CODEC register 0x%02x, value = 0x%02x", (value >> 8) & 0xff, value & 0xff));
      break;
    case ES1370_SCTL:
      mask = (0xffffffff >> ((4 - io_len) << 3)) << shift;
      value = (BX_ES1370_THIS s.sctl & ~mask) | ((value << shift) & mask);
      BX_ES1370_THIS check_lower_irq(value);
      BX_ES1370_THIS update_voices(BX_ES1370_THIS s.ctl, value);
      break;
    case ES1370_DAC1_SCOUNT:
    case ES1370_DAC2_SCOUNT:
    case ES1370_ADC_SCOUNT:
      i = (offset - ES1370_DAC1_SCOUNT) / 4;
      value &= 0xffff;
      BX_ES1370_THIS s.chan[i].scount = value | (value << 16);
      break;
    case ES1370_DAC1_FRAMEADR:
      BX_ES1370_THIS s.chan[0].frame_addr = value;
      break;
    case ES1370_DAC2_FRAMEADR:
      BX_ES1370_THIS s.chan[1].frame_addr = value;
      break;
    case ES1370_ADC_FRAMEADR:
      BX_ES1370_THIS s.chan[2].frame_addr = value;
      break;
    case ES1370_DAC1_FRAMECNT:
      BX_ES1370_THIS s.chan[0].frame_cnt = value;
      break;
    case ES1370_DAC2_FRAMECNT:
      BX_ES1370_THIS s.chan[1].frame_cnt = value;
      break;
    case ES1370_ADC_FRAMECNT:
      BX_ES1370_THIS s.chan[2].frame_cnt = value;
      break;
    case ES1370_PHA_FRAMEADR:
      BX_ERROR(("writing to phantom frame address"));
      break;
    case ES1370_PHA_FRAMECNT:
      BX_ERROR(("writing to phantom frame count"));
      break;
    default:
      BX_ERROR(("unsupported io write to offset=0x%04x!", offset));
      break;
  }
}

void bx_es1370_c::es1370_timer_handler(void *this_ptr)
{
  bx_es1370_c *class_ptr = (bx_es1370_c *) this_ptr;
  class_ptr->es1370_timer();
}

void bx_es1370_c::es1370_timer(void)
{
  int timer_id;
  unsigned i;
  Bit32u new_status = BX_ES1370_THIS s.status;
  Bit32u addr, sc, csc_bytes, cnt, size, left, transfered, temp;
  Bit8u tmpbuf[BX_SOUND_OUTPUT_WAVEPACKETSIZE];
  bx_bool irq = 0;

  timer_id = bx_pc_system.triggeredTimerID();
  if (timer_id == BX_ES1370_THIS s.dac1_timer_index) {
    i = 0;
  } else if (timer_id == BX_ES1370_THIS s.dac2_timer_index) {
    i = 1;
  } else {
    i = 2;
  }
  chan_t *d = &BX_ES1370_THIS s.chan[i];

  if (!(BX_ES1370_THIS s.ctl & ctl_ch_en[i]) || (BX_ES1370_THIS s.sctl & sctl_ch_pause[i])) {
    bx_pc_system.deactivate_timer(timer_id);
    return;
  }

  addr = d->frame_addr;
  sc = d->scount & 0xffff;
  csc_bytes = ((d->scount >> 16) + 1) << d->shift;
  cnt = d->frame_cnt >> 16;
  size = d->frame_cnt & 0xffff;
  left = ((size - cnt + 1) << 2) + d->leftover;
  transfered = 0;
  temp = BX_MIN(BX_SOUND_OUTPUT_WAVEPACKETSIZE, BX_MIN(left, csc_bytes));
  addr += (cnt << 2) + d->leftover;

  if (i == ADC_CHANNEL) {
    // TODO: audio input
    transfered = BX_SOUND_OUTPUT_WAVEPACKETSIZE;
    memset(tmpbuf, 0, transfered);
    DEV_MEM_WRITE_PHYSICAL_BLOCK(addr, transfered, tmpbuf);
  } else {
    // TODO: DAC1 audio output
    DEV_MEM_READ_PHYSICAL_BLOCK(addr, temp, tmpbuf);
    if ((i == DAC2_CHANNEL) && BX_ES1370_THIS s.dac2_outputinit) {
      BX_ES1370_THIS soundmod->sendwavepacket(temp, tmpbuf);
    }
    transfered = temp;
  }

  if (csc_bytes == transfered) {
    irq = 1;
    d->scount = sc | (sc << 16);
    BX_DEBUG(("%s: all samples played - signalling IRQ (if enabled)", chan_name[i]));
  } else {
    irq = 0;
    d->scount = sc | (((csc_bytes - transfered - 1) >> d->shift) << 16);
  }

  cnt += (transfered + d->leftover) >> 2;

  if (BX_ES1370_THIS s.sctl & sctl_loop_sel[i]) {
    BX_ERROR(("%s: non looping mode not supported", chan_name[i]));
  } else {
    d->frame_cnt = size;
    if (cnt <= d->frame_cnt) {
      d->frame_cnt |= cnt << 16;
    }
  }

  d->leftover = (transfered + d->leftover) & 3;

  if (irq) {
    if (BX_ES1370_THIS s.sctl & (1 << (8 + i))) {
      new_status |= (4 >> i);
    }
  }
  if (new_status != BX_ES1370_THIS s.status) {
    update_status(new_status);
  }
}

void bx_es1370_c::set_irq_level(bx_bool level)
{
  DEV_pci_set_irq(BX_ES1370_THIS s.devfunc, BX_ES1370_THIS s.pci_conf[0x3d], level);
}

void bx_es1370_c::update_status(Bit32u new_status)
{
  Bit32u level = new_status & (STAT_DAC1 | STAT_DAC2 | STAT_ADC);

  if (level) {
    BX_ES1370_THIS s.status = new_status | STAT_INTR;
  } else {
    BX_ES1370_THIS s.status = new_status & ~STAT_INTR;
  }
  set_irq_level(level != 0);
}

void bx_es1370_c::check_lower_irq(Bit32u sctl)
{
  Bit32u new_status = BX_ES1370_THIS s.status;

  if (!(sctl & SCTRL_P1INTEN) && (BX_ES1370_THIS s.sctl & SCTRL_P1INTEN)) {
    new_status &= ~STAT_DAC1;
  }
  if (!(sctl & SCTRL_P2INTEN) && (BX_ES1370_THIS s.sctl & SCTRL_P2INTEN)) {
    new_status &= ~STAT_DAC2;
  }
  if (!(sctl & SCTRL_R1INTEN) && (BX_ES1370_THIS s.sctl & SCTRL_R1INTEN)) {
    new_status &= ~STAT_ADC;
  }
  if (new_status != BX_ES1370_THIS s.status) {
    update_status(new_status);
  }
}

void bx_es1370_c::update_voices(Bit32u ctl, Bit32u sctl)
{
  unsigned i;
  Bit32u old_freq, new_freq, old_fmt, new_fmt;
  int ret, timer_id;
  Bit64u timer_val;

  for (i = 0; i < 3; ++i) {
    chan_t *d = &BX_ES1370_THIS s.chan[i];

    old_fmt = (BX_ES1370_THIS s.sctl >> (i << 1)) & 3;
    new_fmt = (sctl >> (i << 1)) & 3;

    if (i == DAC1_CHANNEL) {
      old_freq = dac1_freq[(BX_ES1370_THIS s.ctl >> 12) & 3];
      new_freq = dac1_freq[(ctl >> 12) & 3];
    } else {
      old_freq = 1411200 / (((BX_ES1370_THIS s.ctl >> 16) & 0x1fff) + 2);
      new_freq = 1411200 / (((ctl >> 16) & 0x1fff) + 2);
    }

    if ((old_fmt != new_fmt) || (old_freq != new_freq)) {
      d->shift = (new_fmt & 1) + (new_fmt >> 1);
      if (new_freq) {
        if (i == DAC2_CHANNEL) {
          if (!BX_ES1370_THIS s.dac2_outputinit) {
            ret = BX_ES1370_THIS soundmod->openwaveoutput(SIM->get_param_string(BXPN_ES1370_WAVEDEV)->getptr());
            if (ret != BX_SOUND_OUTPUT_OK) {
              BX_ERROR(("could not open wave output device"));
            } else {
              BX_ES1370_THIS s.dac2_outputinit = 1;
            }
          }
          if (BX_ES1370_THIS s.dac2_outputinit) {
            ret = BX_ES1370_THIS soundmod->startwaveplayback(new_freq, (new_fmt >> 1) ? 16 : 8, (new_fmt & 1), (new_fmt >> 1));
            if (ret != BX_SOUND_OUTPUT_OK) {
              BX_ES1370_THIS soundmod->closewaveoutput();
              BX_ES1370_THIS s.dac2_outputinit = 0;
              BX_ERROR(("could not start wave playback"));
            }
          }
        }
      }
    }
    if (((ctl ^ BX_ES1370_THIS s.ctl) & ctl_ch_en[i]) ||
        ((sctl ^ BX_ES1370_THIS s.sctl) & sctl_ch_pause[i])) {
      bx_bool on = ((ctl & ctl_ch_en[i]) && !(sctl & sctl_ch_pause[i]));

      if (i == DAC1_CHANNEL) {
        timer_id = BX_ES1370_THIS s.dac1_timer_index;
      } else if (i == DAC2_CHANNEL) {
        timer_id = BX_ES1370_THIS s.dac2_timer_index;
      } else {
        timer_id = BX_ES1370_THIS s.adc_timer_index;
      }
      if (on) {
        BX_INFO(("%s: freq = %d, nchannels %d, fmt %d, shift %d",
                 chan_name[i], new_freq, 1 << (new_fmt & 1), (new_fmt & 2) ? 16 : 8, d->shift));
        if (i != DAC2_CHANNEL) {
          BX_ERROR(("channel %s not supported yet", chan_name[i]));
        }
        timer_val = (Bit64u)BX_SOUND_OUTPUT_WAVEPACKETSIZE * 1000000 / (new_freq << d->shift);
        bx_pc_system.activate_timer(timer_id, timer_val, 1);
      } else {
        if ((i == DAC2_CHANNEL) && BX_ES1370_THIS s.dac2_outputinit) {
          BX_ES1370_THIS soundmod->stopwaveplayback();
        }
        bx_pc_system.deactivate_timer(timer_id);
      }
    }
  }
  BX_ES1370_THIS s.ctl = ctl;
  BX_ES1370_THIS s.sctl = sctl;
}

// pci configuration space read callback handler
Bit32u bx_es1370_c::pci_read_handler(Bit8u address, unsigned io_len)
{
  Bit32u value = 0;

  for (unsigned i=0; i<io_len; i++) {
    value |= (BX_ES1370_THIS s.pci_conf[address+i] << (i*8));
  }

  if (io_len == 1)
    BX_DEBUG(("read  PCI register 0x%02x value 0x%02x", address, value));
  else if (io_len == 2)
    BX_DEBUG(("read  PCI register 0x%02x value 0x%04x", address, value));
  else if (io_len == 4)
    BX_DEBUG(("read  PCI register 0x%02x value 0x%08x", address, value));

  return value;
}


// pci configuration space write callback handler
void bx_es1370_c::pci_write_handler(Bit8u address, Bit32u value, unsigned io_len)
{
  Bit8u value8, oldval;
  bx_bool baseaddr_change = 0;

  if ((address >= 0x14) && (address < 0x34))
    return;

  for (unsigned i=0; i<io_len; i++) {
    value8 = (value >> (i*8)) & 0xFF;
    oldval = BX_ES1370_THIS s.pci_conf[address+i];
    switch (address+i) {
      case 0x04:
        value8 &= 0x05;
        BX_ES1370_THIS s.pci_conf[address+i] = value8;
        break;
      case 0x05:
        value8 &= 0x01;
        BX_ES1370_THIS s.pci_conf[address+i] = value8;
        break;
      case 0x3d: //
      case 0x06: // disallowing write to status lo-byte (is that expected?)
        break;
      case 0x3c:
        if (value8 != oldval) {
          BX_INFO(("new irq line = %d", value8));
          BX_ES1370_THIS s.pci_conf[address+i] = value8;
        }
        break;
      case 0x10:
        value8 = (value8 & 0xfc) | 0x01;
      case 0x11:
      case 0x12:
      case 0x13:
        baseaddr_change |= (value8 != oldval);
      default:
        BX_ES1370_THIS s.pci_conf[address+i] = value8;
    }
  }
  if (baseaddr_change) {
    if (DEV_pci_set_base_io(BX_ES1370_THIS_PTR, read_handler, write_handler,
                            &BX_ES1370_THIS s.base_ioaddr,
                            &BX_ES1370_THIS s.pci_conf[0x10],
                            64, &es1370_iomask[0], "ES1370")) {
      BX_INFO(("new base address: 0x%04x", BX_ES1370_THIS s.base_ioaddr));
    }
  }

  if (io_len == 1)
    BX_DEBUG(("write PCI register 0x%02x value 0x%02x", address, value));
  else if (io_len == 2)
    BX_DEBUG(("write PCI register 0x%02x value 0x%04x", address, value));
  else if (io_len == 4)
    BX_DEBUG(("write PCI register 0x%02x value 0x%08x", address, value));
}

#endif // BX_SUPPORT_PCI && BX_SUPPORT_ES1370
