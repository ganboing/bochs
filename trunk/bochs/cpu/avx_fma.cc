/////////////////////////////////////////////////////////////////////////
// $Id$
/////////////////////////////////////////////////////////////////////////
//
//   Copyright (c) 2011 Stanislav Shwartsman
//          Written by Stanislav Shwartsman [sshwarts at sourceforge net]
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
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA B 02110-1301 USA
//
/////////////////////////////////////////////////////////////////////////

#define NEED_CPU_REG_SHORTCUTS 1
#include "bochs.h"
#include "cpu.h"
#define LOG_THIS BX_CPU_THIS_PTR

#if BX_SUPPORT_AVX && BX_CPU_LEVEL >= 6

extern void mxcsr_to_softfloat_status_word(float_status_t &status, bx_mxcsr_t mxcsr);

#include "simd_pfp.h"

// FMADDPD
BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMADD132PD_VpdHpdWpdR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fmaddpd(&op1.avx128(n), &op3.avx128(n), &op2.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op1, len);

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMADD213PD_VpdHpdWpdR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fmaddpd(&op2.avx128(n), &op1.avx128(n), &op3.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op2, len);

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMADD231PD_VpdHpdWpdR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fmaddpd(&op2.avx128(n), &op3.avx128(n), &op1.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op2, len);

  BX_NEXT_INSTR(i);
}

// FMADDPS
BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMADD132PS_VpsHpsWpsR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fmaddps(&op1.avx128(n), &op3.avx128(n), &op2.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op1, len);

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMADD213PS_VpsHpsWpsR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fmaddps(&op2.avx128(n), &op1.avx128(n), &op3.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op2, len);

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMADD231PS_VpsHpsWpsR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fmaddps(&op2.avx128(n), &op3.avx128(n), &op1.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op2, len);

  BX_NEXT_INSTR(i);
}

// FMADDSD
BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMADD132SD_VpdHsdWsdR(bxInstruction_c *i)
{
  float64 op1 = BX_READ_XMM_REG_LO_QWORD(i->nnn());
  float64 op2 = BX_READ_XMM_REG_LO_QWORD(i->vvv());
  float64 op3 = BX_READ_XMM_REG_LO_QWORD(i->rm());

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);
  op1 = float64_muladd(op1, op3, op2, 0, status);
  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_XMM_REG_LO_QWORD(i->nnn(), op1);
  BX_CLEAR_AVX_HIGH(i->nnn());

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMADD213SD_VpdHsdWsdR(bxInstruction_c *i)
{
  float64 op1 = BX_READ_XMM_REG_LO_QWORD(i->nnn());
  float64 op2 = BX_READ_XMM_REG_LO_QWORD(i->vvv());
  float64 op3 = BX_READ_XMM_REG_LO_QWORD(i->rm());

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);
  op1 = float64_muladd(op2, op1, op3, 0, status);
  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_XMM_REG_LO_QWORD(i->nnn(), op1);
  BX_CLEAR_AVX_HIGH(i->nnn());

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMADD231SD_VpdHsdWsdR(bxInstruction_c *i)
{
  float64 op1 = BX_READ_XMM_REG_LO_QWORD(i->nnn());
  float64 op2 = BX_READ_XMM_REG_LO_QWORD(i->vvv());
  float64 op3 = BX_READ_XMM_REG_LO_QWORD(i->rm());

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);
  op1 = float64_muladd(op2, op3, op1, 0, status);
  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_XMM_REG_LO_QWORD(i->nnn(), op1);
  BX_CLEAR_AVX_HIGH(i->nnn());

  BX_NEXT_INSTR(i);
}

// FMADDSS
BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMADD132SS_VpsHssWssR(bxInstruction_c *i)
{
  float32 op1 = BX_READ_XMM_REG_LO_DWORD(i->nnn());
  float32 op2 = BX_READ_XMM_REG_LO_DWORD(i->vvv());
  float32 op3 = BX_READ_XMM_REG_LO_DWORD(i->rm());

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);
  op1 = float32_muladd(op1, op3, op2, 0, status);
  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_XMM_REG_LO_DWORD(i->nnn(), op1);
  BX_CLEAR_AVX_HIGH(i->nnn());

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMADD213SS_VpsHssWssR(bxInstruction_c *i)
{
  float32 op1 = BX_READ_XMM_REG_LO_DWORD(i->nnn());
  float32 op2 = BX_READ_XMM_REG_LO_DWORD(i->vvv());
  float32 op3 = BX_READ_XMM_REG_LO_DWORD(i->rm());

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);
  op1 = float32_muladd(op2, op1, op3, 0, status);
  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_XMM_REG_LO_DWORD(i->nnn(), op1);
  BX_CLEAR_AVX_HIGH(i->nnn());

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMADD231SS_VpsHssWssR(bxInstruction_c *i)
{
  float32 op1 = BX_READ_XMM_REG_LO_DWORD(i->nnn());
  float32 op2 = BX_READ_XMM_REG_LO_DWORD(i->vvv());
  float32 op3 = BX_READ_XMM_REG_LO_DWORD(i->rm());

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);
  op1 = float32_muladd(op2, op3, op1, 0, status);
  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_XMM_REG_LO_DWORD(i->nnn(), op1);
  BX_CLEAR_AVX_HIGH(i->nnn());

  BX_NEXT_INSTR(i);
}

// FMADDSUBPD
BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMADDSUB132PD_VpdHpdWpdR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fmaddsubpd(&op1.avx128(n), &op3.avx128(n), &op2.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op1, len);

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMADDSUB213PD_VpdHpdWpdR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fmaddsubpd(&op2.avx128(n), &op1.avx128(n), &op3.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op2, len);

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMADDSUB231PD_VpdHpdWpdR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fmaddsubpd(&op2.avx128(n), &op3.avx128(n), &op1.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op2, len);

  BX_NEXT_INSTR(i);
}

// FMADDSUBPS
BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMADDSUB132PS_VpsHpsWpsR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fmaddsubps(&op1.avx128(n), &op3.avx128(n), &op2.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op1, len);

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMADDSUB213PS_VpsHpsWpsR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fmaddsubps(&op2.avx128(n), &op1.avx128(n), &op3.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op2, len);

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMADDSUB231PS_VpsHpsWpsR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fmaddsubps(&op2.avx128(n), &op3.avx128(n), &op1.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op2, len);

  BX_NEXT_INSTR(i);
}

// FMSUBADDPD
BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMSUBADD132PD_VpdHpdWpdR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fmasubaddpd(&op1.avx128(n), &op3.avx128(n), &op2.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op1, len);

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMSUBADD213PD_VpdHpdWpdR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fmasubaddpd(&op2.avx128(n), &op1.avx128(n), &op3.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op2, len);

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMSUBADD231PD_VpdHpdWpdR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fmasubaddpd(&op2.avx128(n), &op3.avx128(n), &op1.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op2, len);

  BX_NEXT_INSTR(i);
}

// FMSUBADDPS
BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMSUBADD132PS_VpsHpsWpsR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fmasubaddps(&op1.avx128(n), &op3.avx128(n), &op2.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op1, len);

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMSUBADD213PS_VpsHpsWpsR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fmasubaddps(&op2.avx128(n), &op1.avx128(n), &op3.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op2, len);

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMSUBADD231PS_VpsHpsWpsR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fmasubaddps(&op2.avx128(n), &op3.avx128(n), &op1.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op2, len);

  BX_NEXT_INSTR(i);
}

// FMSUBPD
BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMSUB132PD_VpdHpdWpdR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fmsubpd(&op1.avx128(n), &op3.avx128(n), &op2.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op1, len);

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMSUB213PD_VpdHpdWpdR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fmsubpd(&op2.avx128(n), &op1.avx128(n), &op3.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op2, len);

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMSUB231PD_VpdHpdWpdR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fmsubpd(&op2.avx128(n), &op3.avx128(n), &op1.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op2, len);

  BX_NEXT_INSTR(i);
}

// FMSUBPS
BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMSUB132PS_VpsHpsWpsR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fmsubps(&op1.avx128(n), &op3.avx128(n), &op2.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op1, len);

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMSUB213PS_VpsHpsWpsR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fmsubps(&op2.avx128(n), &op1.avx128(n), &op3.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op2, len);

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMSUB231PS_VpsHpsWpsR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fmsubps(&op2.avx128(n), &op3.avx128(n), &op1.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op2, len);

  BX_NEXT_INSTR(i);
}

// FMSUBSD
BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMSUB132SD_VpdHsdWsdR(bxInstruction_c *i)
{
  float64 op1 = BX_READ_XMM_REG_LO_QWORD(i->nnn());
  float64 op2 = BX_READ_XMM_REG_LO_QWORD(i->vvv());
  float64 op3 = BX_READ_XMM_REG_LO_QWORD(i->rm());

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);
  op1 = float64_muladd(op1, op3, op2, float_muladd_negate_c, status);
  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_XMM_REG_LO_QWORD(i->nnn(), op1);
  BX_CLEAR_AVX_HIGH(i->nnn());

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMSUB213SD_VpdHsdWsdR(bxInstruction_c *i)
{
  float64 op1 = BX_READ_XMM_REG_LO_QWORD(i->nnn());
  float64 op2 = BX_READ_XMM_REG_LO_QWORD(i->vvv());
  float64 op3 = BX_READ_XMM_REG_LO_QWORD(i->rm());

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);
  op1 = float64_muladd(op2, op1, op3, float_muladd_negate_c, status);
  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_XMM_REG_LO_QWORD(i->nnn(), op1);
  BX_CLEAR_AVX_HIGH(i->nnn());

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMSUB231SD_VpdHsdWsdR(bxInstruction_c *i)
{
  float64 op1 = BX_READ_XMM_REG_LO_QWORD(i->nnn());
  float64 op2 = BX_READ_XMM_REG_LO_QWORD(i->vvv());
  float64 op3 = BX_READ_XMM_REG_LO_QWORD(i->rm());

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);
  op1 = float64_muladd(op2, op3, op1, float_muladd_negate_c, status);
  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_XMM_REG_LO_QWORD(i->nnn(), op1);
  BX_CLEAR_AVX_HIGH(i->nnn());

  BX_NEXT_INSTR(i);
}

// FMSUBSS
BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMSUB132SS_VpsHssWssR(bxInstruction_c *i)
{
  float32 op1 = BX_READ_XMM_REG_LO_DWORD(i->nnn());
  float32 op2 = BX_READ_XMM_REG_LO_DWORD(i->vvv());
  float32 op3 = BX_READ_XMM_REG_LO_DWORD(i->rm());

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);
  op1 = float32_muladd(op1, op3, op2, float_muladd_negate_c, status);
  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_XMM_REG_LO_DWORD(i->nnn(), op1);
  BX_CLEAR_AVX_HIGH(i->nnn());

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMSUB213SS_VpsHssWssR(bxInstruction_c *i)
{
  float32 op1 = BX_READ_XMM_REG_LO_DWORD(i->nnn());
  float32 op2 = BX_READ_XMM_REG_LO_DWORD(i->vvv());
  float32 op3 = BX_READ_XMM_REG_LO_DWORD(i->rm());

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);
  op1 = float32_muladd(op2, op1, op3, float_muladd_negate_c, status);
  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_XMM_REG_LO_DWORD(i->nnn(), op1);
  BX_CLEAR_AVX_HIGH(i->nnn());

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFMSUB231SS_VpsHssWssR(bxInstruction_c *i)
{
  float32 op1 = BX_READ_XMM_REG_LO_DWORD(i->nnn());
  float32 op2 = BX_READ_XMM_REG_LO_DWORD(i->vvv());
  float32 op3 = BX_READ_XMM_REG_LO_DWORD(i->rm());

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);
  op1 = float32_muladd(op2, op3, op1, float_muladd_negate_c, status);
  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_XMM_REG_LO_DWORD(i->nnn(), op1);
  BX_CLEAR_AVX_HIGH(i->nnn());

  BX_NEXT_INSTR(i);
}

// FNMADDPD
BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFNMADD132PD_VpdHpdWpdR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fnmaddpd(&op1.avx128(n), &op3.avx128(n), &op2.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op1, len);

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFNMADD213PD_VpdHpdWpdR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fnmaddpd(&op2.avx128(n), &op1.avx128(n), &op3.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op2, len);

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFNMADD231PD_VpdHpdWpdR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fnmaddpd(&op2.avx128(n), &op3.avx128(n), &op1.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op2, len);

  BX_NEXT_INSTR(i);
}

// FNMADDPS
BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFNMADD132PS_VpsHpsWpsR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fnmaddps(&op1.avx128(n), &op3.avx128(n), &op2.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op1, len);

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFNMADD213PS_VpsHpsWpsR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fnmaddps(&op2.avx128(n), &op1.avx128(n), &op3.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op2, len);

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFNMADD231PS_VpsHpsWpsR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fnmaddps(&op2.avx128(n), &op3.avx128(n), &op1.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op2, len);

  BX_NEXT_INSTR(i);
}

// FNMADDSD
BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFNMADD132SD_VpdHsdWsdR(bxInstruction_c *i)
{
  float64 op1 = BX_READ_XMM_REG_LO_QWORD(i->nnn());
  float64 op2 = BX_READ_XMM_REG_LO_QWORD(i->vvv());
  float64 op3 = BX_READ_XMM_REG_LO_QWORD(i->rm());

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);
  op1 = float64_muladd(op1, op3, op2, float_muladd_negate_product, status);
  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_XMM_REG_LO_QWORD(i->nnn(), op1);
  BX_CLEAR_AVX_HIGH(i->nnn());

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFNMADD213SD_VpdHsdWsdR(bxInstruction_c *i)
{
  float64 op1 = BX_READ_XMM_REG_LO_QWORD(i->nnn());
  float64 op2 = BX_READ_XMM_REG_LO_QWORD(i->vvv());
  float64 op3 = BX_READ_XMM_REG_LO_QWORD(i->rm());

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);
  op1 = float64_muladd(op2, op1, op3, float_muladd_negate_product, status);
  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_XMM_REG_LO_QWORD(i->nnn(), op1);
  BX_CLEAR_AVX_HIGH(i->nnn());

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFNMADD231SD_VpdHsdWsdR(bxInstruction_c *i)
{
  float64 op1 = BX_READ_XMM_REG_LO_QWORD(i->nnn());
  float64 op2 = BX_READ_XMM_REG_LO_QWORD(i->vvv());
  float64 op3 = BX_READ_XMM_REG_LO_QWORD(i->rm());

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);
  op1 = float64_muladd(op2, op3, op1, float_muladd_negate_product, status);
  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_XMM_REG_LO_QWORD(i->nnn(), op1);
  BX_CLEAR_AVX_HIGH(i->nnn());

  BX_NEXT_INSTR(i);
}

// FNMADDSS
BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFNMADD132SS_VpsHssWssR(bxInstruction_c *i)
{
  float32 op1 = BX_READ_XMM_REG_LO_DWORD(i->nnn());
  float32 op2 = BX_READ_XMM_REG_LO_DWORD(i->vvv());
  float32 op3 = BX_READ_XMM_REG_LO_DWORD(i->rm());

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);
  op1 = float32_muladd(op1, op3, op2, float_muladd_negate_product, status);
  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_XMM_REG_LO_DWORD(i->nnn(), op1);
  BX_CLEAR_AVX_HIGH(i->nnn());

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFNMADD213SS_VpsHssWssR(bxInstruction_c *i)
{
  float32 op1 = BX_READ_XMM_REG_LO_DWORD(i->nnn());
  float32 op2 = BX_READ_XMM_REG_LO_DWORD(i->vvv());
  float32 op3 = BX_READ_XMM_REG_LO_DWORD(i->rm());

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);
  op1 = float32_muladd(op2, op1, op3, float_muladd_negate_product, status);
  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_XMM_REG_LO_DWORD(i->nnn(), op1);
  BX_CLEAR_AVX_HIGH(i->nnn());

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFNMADD231SS_VpsHssWssR(bxInstruction_c *i)
{
  float32 op1 = BX_READ_XMM_REG_LO_DWORD(i->nnn());
  float32 op2 = BX_READ_XMM_REG_LO_DWORD(i->vvv());
  float32 op3 = BX_READ_XMM_REG_LO_DWORD(i->rm());

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);
  op1 = float32_muladd(op2, op3, op1, float_muladd_negate_product, status);
  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_XMM_REG_LO_DWORD(i->nnn(), op1);
  BX_CLEAR_AVX_HIGH(i->nnn());

  BX_NEXT_INSTR(i);
}

// FNMADDPD
BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFNMSUB132PD_VpdHpdWpdR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fnmsubpd(&op1.avx128(n), &op3.avx128(n), &op2.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op1, len);

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFNMSUB213PD_VpdHpdWpdR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fnmsubpd(&op2.avx128(n), &op1.avx128(n), &op3.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op2, len);

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFNMSUB231PD_VpdHpdWpdR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fnmsubpd(&op2.avx128(n), &op3.avx128(n), &op1.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op2, len);

  BX_NEXT_INSTR(i);
}

// FNMSUBPS
BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFNMSUB132PS_VpsHpsWpsR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fnmsubps(&op1.avx128(n), &op3.avx128(n), &op2.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op1, len);

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFNMSUB213PS_VpsHpsWpsR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fnmsubps(&op2.avx128(n), &op1.avx128(n), &op3.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op2, len);

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFNMSUB231PS_VpsHpsWpsR(bxInstruction_c *i)
{
  BxPackedAvxRegister op1 = BX_READ_AVX_REG(i->nnn());
  BxPackedAvxRegister op2 = BX_READ_AVX_REG(i->vvv());
  BxPackedAvxRegister op3 = BX_READ_AVX_REG(i->rm());
  unsigned len = i->getVL();

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);

  for (unsigned n=0; n < len; n++)
    fnmsubps(&op2.avx128(n), &op3.avx128(n), &op1.avx128(n), status);

  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_AVX_REGZ(i->nnn(), op2, len);

  BX_NEXT_INSTR(i);
}

// FNMSUBSD
BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFNMSUB132SD_VpdHsdWsdR(bxInstruction_c *i)
{
  float64 op1 = BX_READ_XMM_REG_LO_QWORD(i->nnn());
  float64 op2 = BX_READ_XMM_REG_LO_QWORD(i->vvv());
  float64 op3 = BX_READ_XMM_REG_LO_QWORD(i->rm());

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);
  op1 = float64_muladd(op1, op3, op2, float_muladd_negate_result, status);
  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_XMM_REG_LO_QWORD(i->nnn(), op1);
  BX_CLEAR_AVX_HIGH(i->nnn());

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFNMSUB213SD_VpdHsdWsdR(bxInstruction_c *i)
{
  float64 op1 = BX_READ_XMM_REG_LO_QWORD(i->nnn());
  float64 op2 = BX_READ_XMM_REG_LO_QWORD(i->vvv());
  float64 op3 = BX_READ_XMM_REG_LO_QWORD(i->rm());

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);
  op1 = float64_muladd(op2, op1, op3, float_muladd_negate_result, status);
  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_XMM_REG_LO_QWORD(i->nnn(), op1);
  BX_CLEAR_AVX_HIGH(i->nnn());

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFNMSUB231SD_VpdHsdWsdR(bxInstruction_c *i)
{
  float64 op1 = BX_READ_XMM_REG_LO_QWORD(i->nnn());
  float64 op2 = BX_READ_XMM_REG_LO_QWORD(i->vvv());
  float64 op3 = BX_READ_XMM_REG_LO_QWORD(i->rm());

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);
  op1 = float64_muladd(op2, op3, op1, float_muladd_negate_result, status);
  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_XMM_REG_LO_QWORD(i->nnn(), op1);
  BX_CLEAR_AVX_HIGH(i->nnn());

  BX_NEXT_INSTR(i);
}

// FNMSUBSS
BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFNMSUB132SS_VpsHssWssR(bxInstruction_c *i)
{
  float32 op1 = BX_READ_XMM_REG_LO_DWORD(i->nnn());
  float32 op2 = BX_READ_XMM_REG_LO_DWORD(i->vvv());
  float32 op3 = BX_READ_XMM_REG_LO_DWORD(i->rm());

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);
  op1 = float32_muladd(op1, op3, op2, float_muladd_negate_result, status);
  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_XMM_REG_LO_DWORD(i->nnn(), op1);
  BX_CLEAR_AVX_HIGH(i->nnn());

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFNMSUB213SS_VpsHssWssR(bxInstruction_c *i)
{
  float32 op1 = BX_READ_XMM_REG_LO_DWORD(i->nnn());
  float32 op2 = BX_READ_XMM_REG_LO_DWORD(i->vvv());
  float32 op3 = BX_READ_XMM_REG_LO_DWORD(i->rm());

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);
  op1 = float32_muladd(op2, op1, op3, float_muladd_negate_result, status);
  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_XMM_REG_LO_DWORD(i->nnn(), op1);
  BX_CLEAR_AVX_HIGH(i->nnn());

  BX_NEXT_INSTR(i);
}

BX_INSF_TYPE BX_CPP_AttrRegparmN(1) BX_CPU_C::VFNMSUB231SS_VpsHssWssR(bxInstruction_c *i)
{
  float32 op1 = BX_READ_XMM_REG_LO_DWORD(i->nnn());
  float32 op2 = BX_READ_XMM_REG_LO_DWORD(i->vvv());
  float32 op3 = BX_READ_XMM_REG_LO_DWORD(i->rm());

  float_status_t status;
  mxcsr_to_softfloat_status_word(status, MXCSR);
  op1 = float32_muladd(op2, op3, op1, float_muladd_negate_result, status);
  check_exceptionsSSE(status.float_exception_flags);

  BX_WRITE_XMM_REG_LO_DWORD(i->nnn(), op1);
  BX_CLEAR_AVX_HIGH(i->nnn());

  BX_NEXT_INSTR(i);
}

#endif
