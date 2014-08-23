//
// arch/arm/rsp/rsp.c
//
// Declarations for host RSP functions.
//
// This file is subject to the terms and conditions defined in
// 'LICENSE', which is part of this source code package.
//

#include "common.h"
#include "arch/arm/rsp/rsp.h"

cen64_align(const uint8_t shuffle_keys[16][16], CACHE_LINE_SIZE) = {
  /* -- */ {0x0,0x8,0x1,0x9,0x2,0xA,0x3,0xB,0x4,0xC,0x5,0xD,0x6,0xE,0x7,0xF},
  /* -- */ {0x0,0x8,0x1,0x9,0x2,0xA,0x3,0xB,0x4,0xC,0x5,0xD,0x6,0xE,0x7,0xF},

  /* 0q */ {0x0,0x8,0x0,0x8,0x2,0xA,0x2,0xA,0x4,0xC,0x4,0xC,0x6,0xE,0x6,0xE},
  /* 1q */ {0x1,0x9,0x1,0x9,0x3,0xB,0x3,0xB,0x5,0xD,0x5,0xD,0x7,0xF,0x7,0xF},

  /* 0h */ {0x0,0x8,0x0,0x8,0x0,0x8,0x0,0x8,0x4,0xC,0x4,0xC,0x4,0xC,0x4,0xC},
  /* 1h */ {0x1,0x9,0x1,0x9,0x1,0x9,0x1,0x9,0x5,0xD,0x5,0xD,0x5,0xD,0x5,0xD},
  /* 2h */ {0x2,0xA,0x2,0xA,0x2,0xA,0x2,0xA,0x6,0xE,0x6,0xE,0x6,0xE,0x6,0xE},
  /* 3h */ {0x3,0xB,0x3,0xB,0x3,0xB,0x3,0xB,0x7,0xF,0x7,0xF,0x7,0xF,0x7,0xF},

  /* 0w */ {0x0,0x8,0x0,0x8,0x0,0x8,0x0,0x8,0x0,0x8,0x0,0x8,0x0,0x8,0x0,0x8},
  /* 1w */ {0x1,0x9,0x1,0x9,0x1,0x9,0x1,0x9,0x1,0x9,0x1,0x9,0x1,0x9,0x1,0x9},
  /* 2w */ {0x2,0xA,0x2,0xA,0x2,0xA,0x2,0xA,0x2,0xA,0x2,0xA,0x2,0xA,0x2,0xA},
  /* 3w */ {0x3,0xB,0x3,0xB,0x3,0xB,0x3,0xB,0x3,0xB,0x3,0xB,0x3,0xB,0x3,0xB},
  /* 4w */ {0x4,0xC,0x4,0xC,0x4,0xC,0x4,0xC,0x4,0xC,0x4,0xC,0x4,0xC,0x4,0xC},
  /* 5w */ {0x5,0xD,0x5,0xD,0x5,0xD,0x5,0xD,0x5,0xD,0x5,0xD,0x5,0xD,0x5,0xD},
  /* 6w */ {0x6,0xE,0x6,0xE,0x6,0xE,0x6,0xE,0x6,0xE,0x6,0xE,0x6,0xE,0x6,0xE},
  /* 7w */ {0x7,0xF,0x7,0xF,0x7,0xF,0x7,0xF,0x7,0xF,0x7,0xF,0x7,0xF,0x7,0xF},
};
