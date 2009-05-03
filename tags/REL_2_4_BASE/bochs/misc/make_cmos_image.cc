/////////////////////////////////////////////////////////////////////////
// $Id: make_cmos_image.cc,v 1.5 2009-02-08 09:05:52 vruppert Exp $
/////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) 2001  MandrakeSoft S.A.
//
//    MandrakeSoft S.A.
//    43, rue d'Aboukir
//    75002 Paris - France
//    http://www.linux-mandrake.com/
//    http://www.mandrakesoft.com/
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


// Program which generates sample CMOS image files



extern "C" {
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
}


#if 1
unsigned char cmos[] = {
  0x29, 0x2b, 0x30, 0x2b, 0x16, 0x0b, 0x00, 0x01,
  0x01, 0x96, 0x26, 0x02, 0x50, 0x80, 0x00, 0x00,
  0x40, 0x8f, 0xf0, 0xc0, 0x3f, 0x80, 0x02, 0x00,
  0x3c, 0x2f, 0x00, 0x4c, 0x0c, 0x10, 0x00, 0x00,
  0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x48, 0x2b, 0x03, 0x03, 0x03, 0x04, 0xce,
  0x00, 0x3c, 0x19, 0xff, 0xff, 0xf0, 0x00, 0xf0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x7b
  };

#else
unsigned char cmos[] = {
  0x29, 0x2b, 0x30, 0x2b, 0x16, 0x0b, 0x00, 0x01,
  0x01, 0x96, 0x26, 0x02, 0x50, 0x80, 0x00, 0x00,
  0x40, 0x8f, 0xf0, 0xc0, 0x0f, 0x80, 0x02, 0x00,
  0x3c, 0x2f, 0x00, 0x1e, 0x00, 0x04, 0xff, 0xff,
  0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x08, 0x08, 0x03, 0x03, 0x03, 0x05, 0xc5,
  0x00, 0x3c, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x10,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x21,  // 0x21

  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x10,  // 50
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 60
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 70
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };
#endif

  int
main(int argc, char *argv[])
{
  int fd, ret;

  if (argc != 2) {
    fprintf(stderr, "usage: %s pathname\n", argv[0]);
    exit(1);
    }

  fd = open(argv[1], O_WRONLY | O_CREAT
#ifdef O_BINARY
                                    | O_BINARY
#endif
           , S_IRUSR | S_IWUSR
           );
  if (fd < 0) {
    perror("trying to open cmos image file to write.\n");
    exit(1);
    }

  ret = write(fd, cmos, sizeof(cmos));
  if (ret != sizeof(cmos)) {
    perror("write() did not write all CMOS data.\n");
    exit(1);
    }
  printf("CMOS data successfuly written to file '%s'.\n", argv[1]);
}
