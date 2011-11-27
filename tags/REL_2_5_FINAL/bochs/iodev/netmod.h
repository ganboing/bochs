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
//

// Peter Grehan (grehan@iprg.nokia.com) coded the initial version of the
// NE2000/ether stuff.

//  netmod.h  - see eth_null.cc for implementation details

#ifndef BX_NETMOD_H
#define BX_NETMOD_H

// Pseudo device that loads the lowlevel networking module
class bx_netmod_ctl_c : public bx_netmod_ctl_stub_c {
public:
  bx_netmod_ctl_c() {}
  virtual ~bx_netmod_ctl_c() {}
  virtual void* init_module(bx_list_c *base, void* rxh, bx_devmodel_c *dev);
};

#define BX_PACKET_BUFSIZE 2048 // Enough for an ether frame

typedef void (*eth_rx_handler_t)(void *arg, const void *buf, unsigned len);

typedef struct {
  Bit8u host_macaddr[6];
  Bit8u guest_macaddr[6];
  Bit8u host_ipv4addr[4];
  const Bit8u *default_guest_ipv4addr;
  Bit8u guest_ipv4addr[4];
  Bit8u dns_ipv4addr[4];
} dhcp_cfg_t;

static const Bit8u broadcast_macaddr[6] = {0xff,0xff,0xff,0xff,0xff,0xff};

int execute_script(bx_devmodel_c *netdev, const char *name, char* arg1);
void write_pktlog_txt(FILE *pktlog_txt, const Bit8u *buf, unsigned len, bx_bool host_to_guest);

Bit16u get_net2(const Bit8u *buf);
void put_net2(Bit8u *buf,Bit16u data);
Bit32u get_net4(const Bit8u *buf);
void put_net4(Bit8u *buf,Bit32u data);
Bit16u ip_checksum(const Bit8u *buf, unsigned buf_len);
int process_dhcp(bx_devmodel_c *netdev, const Bit8u *data, unsigned data_len, Bit8u *reply, dhcp_cfg_t *dhcp);

//
//  The eth_pktmover class is used by ethernet chip emulations
// to interface to the outside world. An instance of this
// would allow frames to be sent to and received from some
// entity. An example would be the packet filter on a Unix
// system, an NDIS driver in promisc mode on WinNT, or maybe
// a simulated network that talks to another process.
//
class eth_pktmover_c {
public:
  virtual void sendpkt(void *buf, unsigned io_len) = 0;
  virtual ~eth_pktmover_c () {}
protected:
  bx_devmodel_c *netdev;
  eth_rx_handler_t  rxh;   // receive callback
};


//
//  The eth_locator class is used by pktmover classes to register
// their name. Chip emulations use the static 'create' method
// to locate and instantiate a pktmover class.
//
class eth_locator_c {
public:
  static eth_pktmover_c *create(const char *type, const char *netif,
                                const char *macaddr,
                                eth_rx_handler_t rxh,
                                bx_devmodel_c *dev,
                                const char *script);
protected:
  eth_locator_c(const char *type);
  virtual ~eth_locator_c() {}
  virtual eth_pktmover_c *allocate(const char *netif,
                                   const char *macaddr,
                                   eth_rx_handler_t rxh,
                                   bx_devmodel_c *dev,
                                   const char *script) = 0;
private:
  static eth_locator_c *all;
  eth_locator_c *next;
  const char *type;
};

#endif
