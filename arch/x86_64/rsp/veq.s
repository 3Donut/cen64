//
// arch/x86_64/rsp/veq.s
//
// CEN64: Cycle-Accurate Nintendo 64 Simulator.
// Copyright (C) 2014, Tyler J. Stachecki.
//
// This file is subject to the terms and conditions defined in
// 'LICENSE', which is part of this source code package.
//

#
# xmm0 = vs
# xmm1 = vt
# xmm5 = acc_lo
# xmm11 = vcc_lo
# xmm12 = vcc_hi
# xmm13 = vco_lo
# xmm14 = vco_hi
#

.global RSP_VEQ
.type	RSP_VEQ, @function

RSP_VEQ:

.ifdef __AVX__
  vpcmpeqw %xmm1, %xmm0, %xmm11
  vpxor %xmm12, %xmm12, %xmm12
  vpandn %xmm11, %xmm14, %xmm11
  vpxor %xmm13, %xmm13, %xmm13
  vpblendvb %xmm11, %xmm0, %xmm1, %xmm0
  vpxor %xmm14, %xmm14, %xmm14
  movdqa %xmm0, %xmm5
  retq
.else
  movdqa %xmm0, %xmm3
  pcmpeqw %xmm1, %xmm3
  pxor %xmm12, %xmm12
  pandn %xmm3, %xmm14
  pxor %xmm13, %xmm13
  movdqa %xmm14, %xmm11
.ifdef __SSE_4_1__
  pblendvb %xmm14,%xmm0,%xmm1
  movdqa %xmm1, %xmm0
.else
  pand %xmm14, %xmm0
  pandn %xmm1, %xmm14
  por %xmm14, %xmm0
.endif
  pxor %xmm14, %xmm14
  movdqa %xmm0, %xmm5
  retq
.endif

.size RSP_VEQ,.-RSP_VEQ

