#ifndef _LINUX_TNUM_H
#define _LINUX_TNUM_H

#include "types.h"

struct tnum {
  u64 value;
  u64 mask;
};

struct tnum tnum_cast(struct tnum a, u8 size);
struct tnum tnum_subreg(struct tnum a);
u64 tnum_step(struct tnum t, u64 z);

#endif /* _LINUX_TNUM_H */
