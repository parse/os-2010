#ifndef __INTERRUPT__
#define __INTERRUPT__

#include "IOHandler.h"
#include "Process.h"
#include "types.h"
#include "mips/asm.h"
#include "mips/malta.h"
#include "mips/debug.h"

void enableInterrupt();
void kexception();
void my_system_call(uint32_t v);

#endif
