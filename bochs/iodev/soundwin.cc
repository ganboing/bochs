/////////////////////////////////////////////////////////////////////////
// $Id$
/////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) 2001-2011  The Bochs Project
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

// This file (SOUNDWIN.CC) written and donated by Josef Drexler

// Define BX_PLUGGABLE in files that can be compiled into plugins.  For
// platforms that require a special tag on exported symbols, BX_PLUGGABLE
// is used to know when we are exporting symbols and when we are importing.
#define BX_PLUGGABLE

#include "iodev.h"

#if defined(WIN32) && BX_SUPPORT_SOUNDLOW

#include "soundmod.h"
#include "soundwin.h"

#define LOG_THIS device->

bx_sound_windows_c::bx_sound_windows_c(logfunctions *dev)
  :bx_sound_lowlevel_c(dev)
{
  MidiOpen = 0;
  WaveOpen = 0;

  ismidiready = 1;
  iswaveready = 1;

  // size is the total size of the midi header and buffer and the
  // BX_SOUND_WINDOWS_NBUF wave header and buffers, all aligned
  // on a 16-byte boundary

#define ALIGN(size) ((size + 15) & ~15)

#define size   ALIGN(sizeof(MIDIHDR)) \
             + ALIGN(sizeof(WAVEHDR)) \
             + ALIGN(BX_SOUND_WINDOWS_MAXSYSEXLEN) * BX_SOUND_WINDOWS_NBUF \
             + ALIGN(BX_SOUNDLOW_WAVEPACKETSIZE) * BX_SOUND_WINDOWS_NBUF

  DataHandle = GlobalAlloc(GMEM_MOVEABLE | GMEM_SHARE, size);
  DataPointer = (Bit8u*) GlobalLock(DataHandle);

  if (DataPointer == NULL)
    BX_PANIC(("GlobalLock returned NULL-pointer"));

#define NEWBUFFER(size) &(DataPointer[offset]); offset += ALIGN(size)

  unsigned offset = 0;
  MidiHeader = (LPMIDIHDR) NEWBUFFER(sizeof(MIDIHDR));
  MidiData = (LPSTR) NEWBUFFER(BX_SOUND_WINDOWS_MAXSYSEXLEN);

  for (int bufnum=0; bufnum<BX_SOUND_WINDOWS_NBUF; bufnum++)
  {
      WaveHeader[bufnum] = (LPWAVEHDR) NEWBUFFER(sizeof(WAVEHDR));
      WaveData[bufnum] = (LPSTR) NEWBUFFER(BX_SOUNDLOW_WAVEPACKETSIZE+64);
  }

  if (offset > size)
    BX_PANIC(("Allocated memory was too small!"));

#undef size
#undef ALIGN
#undef NEWBUFFER

  BX_INFO(("Sound output module 'win' initialized"));
}

bx_sound_windows_c::~bx_sound_windows_c()
{
  GlobalUnlock(DataHandle);
  GlobalFree(DataHandle);
}

int bx_sound_windows_c::waveready()
{
  if (iswaveready == 0)
    checkwaveready();

  if (iswaveready == 1)
    return BX_SOUNDLOW_OK;
  else
    return BX_SOUNDLOW_ERR;
}
int bx_sound_windows_c::midiready()
{
  if (ismidiready == 0)
    checkmidiready();

  if (ismidiready == 1)
    return BX_SOUNDLOW_OK;
  else
    return BX_SOUNDLOW_ERR;
}

int bx_sound_windows_c::openmidioutput(const char *mididev)
{
  // could make the output device selectable,
  // but currently only the midi mapper is supported
  UNUSED(mididev);

  UINT deviceid = (UINT) MIDIMAPPER;

  MidiOpen = 0;

  UINT ret = midiOutOpen(&MidiOut, deviceid, 0, 0, CALLBACK_NULL);
  if (ret == 0)
    MidiOpen = 1;

  BX_DEBUG(("midiOutOpen() = %d, MidiOpen: %d", ret, MidiOpen));

  return (MidiOpen == 1) ? BX_SOUNDLOW_OK : BX_SOUNDLOW_ERR;
}

int bx_sound_windows_c::sendmidicommand(int delta, int command, int length, Bit8u data[])
{
  UINT ret;

  if (MidiOpen != 1)
    return BX_SOUNDLOW_ERR;

  if ((command == 0xf0) || (command == 0xf7) || (length > 3))
  {
    BX_DEBUG(("SYSEX started, length %d", length));
    ismidiready = 0;   // until the buffer is done
    memcpy(MidiData, data, length);
    MidiHeader->lpData = MidiData;
    MidiHeader->dwBufferLength = BX_SOUND_WINDOWS_MAXSYSEXLEN;
    MidiHeader->dwBytesRecorded = 0;
    MidiHeader->dwUser = 0;
    MidiHeader->dwFlags = 0;
    ret = midiOutPrepareHeader(MidiOut, MidiHeader, sizeof(*MidiHeader));
    if (ret != 0)
      BX_ERROR(("midiOutPrepareHeader() = %d", ret));
    ret = midiOutLongMsg(MidiOut, MidiHeader, sizeof(*MidiHeader));
    if (ret != 0)
      BX_ERROR(("midiOutLongMsg() = %d", ret));
  }
  else
  {
    DWORD msg = command;

    for (int i = 0; i<length; i++)
      msg |= (data[i] << (8 * (i + 1)));

    ret = midiOutShortMsg(MidiOut, msg);
    BX_DEBUG(("midiOutShortMsg(%x) = %d", msg, ret));
  }

  return (ret == 0) ? BX_SOUNDLOW_OK : BX_SOUNDLOW_ERR;
}

int bx_sound_windows_c::closemidioutput()
{
  UINT ret;

  if (MidiOpen != 1)
    return BX_SOUNDLOW_ERR;

  ret = midiOutReset(MidiOut);
  if (ismidiready == 0)
    checkmidiready();   // to clear any pending SYSEX

  ret = midiOutClose(MidiOut);
  BX_DEBUG(("midiOutClose() = %d", ret));
  MidiOpen = 0;

  return (ret == 0) ? BX_SOUNDLOW_OK : BX_SOUNDLOW_ERR;
}

int bx_sound_windows_c::openwaveoutput(const char *wavedev)
{
  // could make the output device selectable,
  // but currently only the wave mapper is supported
  UNUSED(wavedev);

  BX_DEBUG(("openwaveoutput(%s)", wavedev));

#ifdef usewaveOut
  WaveDevice = (UINT) WAVEMAPPER;

  for (int i=0; i<BX_SOUND_WINDOWS_NBUF; i++)
    WaveHeader[i]->dwFlags = WHDR_DONE;

  head = 0;
  tailfull = 0;
  tailplay = 0;
  needreopen = 0;
#endif

  return BX_SOUNDLOW_OK;
}

int bx_sound_windows_c::playnextbuffer()
{
  UINT ret;
  PCMWAVEFORMAT waveformat;
  int bufnum;

  // if the format is different, we have to reopen the device,
  // so reset it first
  if (needreopen != 0)
    if (WaveOpen != 0)
      ret = waveOutReset(WaveOut);

  // clean up the buffers and mark if output is ready
  checkwaveready();

  // do we have to play anything?
  if (tailplay == head)
    return BX_SOUNDLOW_OK;

  // if the format is different, we have to close and reopen the device
  // or, just open the device if it's not open yet
  if ((needreopen != 0) || (WaveOpen == 0))
  {
    if (WaveOpen != 0)
    {
      ret = waveOutClose(WaveOut);
      WaveOpen = 0;
    }

    // try three times to find a suitable format
    for (int tries = 0; tries < 3; tries++)
    {
      int frequency = WaveInfo.frequency;
      bx_bool stereo = WaveInfo.stereo;
      int bits = WaveInfo.bits;
//    int format = WaveInfo.format;
      int bps = (bits / 8) * (stereo + 1);

      waveformat.wf.wFormatTag = WAVE_FORMAT_PCM;
      waveformat.wf.nChannels = stereo + 1;
      waveformat.wf.nSamplesPerSec = frequency;
      waveformat.wf.nAvgBytesPerSec = frequency * bps;
      waveformat.wf.nBlockAlign = bps;
      waveformat.wBitsPerSample = bits;

      ret = waveOutOpen(&(WaveOut), WaveDevice, (LPWAVEFORMATEX)&(waveformat.wf), 0, 0, CALLBACK_NULL);
      if (ret != 0)
      {
        char errormsg[4*MAXERRORLENGTH+1];
        waveOutGetErrorTextA(ret, errormsg, 4*MAXERRORLENGTH+1);
        BX_DEBUG(("waveOutOpen: %s", errormsg));
        switch (tries) {
        case 0:        // maybe try a different frequency
          if (frequency < 15600)
            frequency = 11025;
          else if (frequency < 31200)
            frequency = 22050;
          else
            frequency = 44100;

          BX_DEBUG(("Couldn't open wave device (error %d), trying frequency %d", ret, frequency));
          break;

        case 1:        // or something else
          frequency = 11025;
          stereo = 0;
          bits = 8;
          bps = 1;

          BX_DEBUG(("Couldn't open wave device again (error %d), trying 11KHz, mono, 8bit", ret));
          break;

        case 2:        // nope, doesn't work
          BX_ERROR(("Couldn't open wave device (error %d)!", ret));
          return BX_SOUNDLOW_ERR;
        }

        BX_DEBUG(("The format was: wFormatTag=%d, nChannels=%d, nSamplesPerSec=%d,",
             waveformat.wf.wFormatTag, waveformat.wf.nChannels, waveformat.wf.nSamplesPerSec));
        BX_DEBUG(("                nAvgBytesPerSec=%d, nBlockAlign=%d, wBitsPerSample=%d",
             waveformat.wf.nAvgBytesPerSec, waveformat.wf.nBlockAlign, waveformat.wBitsPerSample));
      }
      else
      {
        WaveOpen = 1;
        needreopen = 0;
        break;
      }
    }
  }

  for (bufnum=tailplay; bufnum != head;
       bufnum++, bufnum &= BX_SOUND_WINDOWS_NMASK, tailplay=bufnum)
  {
    BX_DEBUG(("Playing buffer %d", bufnum));

    // prepare the wave header
    WaveHeader[bufnum]->lpData = WaveData[bufnum];
    WaveHeader[bufnum]->dwBufferLength = length[bufnum];
    WaveHeader[bufnum]->dwBytesRecorded = length[bufnum];
    WaveHeader[bufnum]->dwUser = 0;
    WaveHeader[bufnum]->dwFlags = 0;
    WaveHeader[bufnum]->dwLoops = 1;

    ret = waveOutPrepareHeader(WaveOut, WaveHeader[bufnum], sizeof(*WaveHeader[bufnum]));
    if (ret != 0)
    {
      BX_ERROR(("waveOutPrepareHeader = %d", ret));
      return BX_SOUNDLOW_ERR;
    }

    ret = waveOutWrite(WaveOut, WaveHeader[bufnum], sizeof(*WaveHeader[bufnum]));
    if (ret != 0)
    {
      char errormsg[4*MAXERRORLENGTH+1];
      waveOutGetErrorTextA(ret, errormsg, 4*MAXERRORLENGTH+1);
      BX_DEBUG(("waveOutWrite: %s", errormsg));
    }
  }

  return BX_SOUNDLOW_OK;
}

int bx_sound_windows_c::startwaveplayback(int frequency, int bits, bx_bool stereo, int format)
{
  BX_DEBUG(("startwaveplayback(%d, %d, %d, %x)", frequency, bits, stereo, format));

#ifdef usewaveOut
  // check if any of the properties have changed
  if ((WaveInfo.frequency != frequency) ||
      (WaveInfo.bits != bits) ||
      (WaveInfo.stereo != stereo) ||
      (WaveInfo.format != format))
  {
    needreopen = 1;

    // store the current settings to be used by sendwavepacket()
    WaveInfo.frequency = frequency;
    WaveInfo.bits = bits;
    WaveInfo.stereo = stereo;
    WaveInfo.format = format;
  }
#endif

#ifdef usesndPlaySnd
  int bps = (bits / 8) * (stereo + 1);
  LPWAVEFILEHEADER header = (LPWAVEFILEHEADER) WaveData[0];

  memcpy(header->RIFF, "RIFF", 4);
  memcpy(header->TYPE, "WAVE", 4);
  memcpy(header->chnk, "fmt ", 4);
  header->chnklen = 16;
  header->waveformat.wf.wFormatTag = WAVE_FORMAT_PCM;
  header->waveformat.wf.nChannels = stereo + 1;
  header->waveformat.wf.nSamplesPerSec = frequency;
  header->waveformat.wf.nAvgBytesPerSec = frequency * bps;
  header->waveformat.wf.nBlockAlign = bps;
  header->waveformat.wBitsPerSample = bits;
  memcpy(header->chnk2, "data", 4);
#endif

  return BX_SOUNDLOW_OK;
}

int bx_sound_windows_c::sendwavepacket(int length, Bit8u data[])
{
#ifdef usewaveOut
  int bufnum;
#endif
#ifdef usesndPlaySnd
  UINT ret;
#endif

  BX_DEBUG(("sendwavepacket(%d, %p)", length, data));

#ifdef usewaveOut
  bufnum = head;

  memcpy(WaveData[bufnum], data, length);
  this->length[bufnum] = length;

  // select next buffer to write to
  bufnum++;
  bufnum &= BX_SOUND_WINDOWS_NMASK;

  if (((bufnum + 1) & BX_SOUND_WINDOWS_NMASK) == tailfull)
  { // this should not actually happen!
    BX_ERROR(("Output buffer overflow! Not played. Iswaveready was %d", iswaveready));
    iswaveready = 0;          // stop the output for a while
    return BX_SOUNDLOW_ERR;
  }

  head = bufnum;

  // check if more buffers are available, otherwise stall the emulator
  if (((bufnum + 2) & BX_SOUND_WINDOWS_NMASK) == tailfull)
  {
    BX_DEBUG(("Buffer status: Head %d, TailFull %d, TailPlay %d. Stall.",
                head, tailfull, tailplay));
    iswaveready = 0;
  }

  playnextbuffer();
#endif

#ifdef usesndPlaySnd
  LPWAVEFILEHEADER header = (LPWAVEFILEHEADER) WaveData[0];

  header->length = length + 36;
  header->chnk2len = length;

  memcpy(&(header->data), data, length);

  ret = sndPlaySoundA((LPCSTR) header, SND_SYNC | SND_MEMORY);
  if (ret != 0)
  {
    BX_DEBUG(("sndPlaySoundA: %d", ret));
  }
#endif

  return BX_SOUNDLOW_OK;
}

int bx_sound_windows_c::stopwaveplayback()
{
  BX_DEBUG(("stopwaveplayback()"));

#ifdef usewaveOut
  // this is handled by checkwaveready() when closing
#endif

#ifdef usesndPlaySnd
  sndPlaySoundA(NULL, SND_ASYNC | SND_MEMORY);

  WaveOpen = 0;
#endif

  return BX_SOUNDLOW_OK;
}

int bx_sound_windows_c::closewaveoutput()
{
  BX_DEBUG(("closewaveoutput"));

#ifdef usewaveOut
  if (WaveOpen == 1)
  {
    waveOutReset(WaveOut);

    // let checkwaveready() clean up the buffers
    checkwaveready();

    waveOutClose(WaveOut);

    head = 0;
    tailfull = 0;
    tailplay = 0;
    needreopen = 0;
  }
#endif

  return BX_SOUNDLOW_OK;
}

void bx_sound_windows_c::checkmidiready()
{
  UINT ret;

  if ((MidiHeader->dwFlags & MHDR_DONE) != 0)
  {
    BX_DEBUG(("SYSEX message done, midi ready again"));
    ret = midiOutUnprepareHeader(MidiOut, MidiHeader, sizeof(*MidiHeader));
    ismidiready = 1;
  }
}
void bx_sound_windows_c::checkwaveready()
{
  int bufnum;
  UINT ret;

  // clean up all finished buffers and mark them as available
  for (bufnum=tailfull; (bufnum != tailplay) &&
       ((WaveHeader[bufnum]->dwFlags & WHDR_DONE) != 0);
           bufnum++, bufnum &= BX_SOUND_WINDOWS_NMASK)
  {
    BX_DEBUG(("Buffer %d done.", bufnum));
    ret = waveOutUnprepareHeader(WaveOut, WaveHeader[bufnum], sizeof(*WaveHeader[bufnum]));
  }

  tailfull = bufnum;

  // enable gathering data if a buffer is available
  if (((head + 2) & BX_SOUND_WINDOWS_NMASK) != tailfull)
  {
    BX_DEBUG(("Buffer status: Head %d, TailFull %d, TailPlay %d. Ready.",
             head, tailfull, tailplay));
    iswaveready = 1;
  }
}

#endif // defined(WIN32)
