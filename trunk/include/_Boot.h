#ifndef __ASM_SYSCALL__
#define __ASM_SYSCALL__

#include "Structs.h"

void ksyscall_handler(registers_t* reg);
void syscall_die();
void syscall_display_c(uint8_t v, uint8_t pos);
void syscall_display_number(uint32_t v);
void syscall_put(BFifo* bfifo, char c);
void syscall_puts(BFifo* bfifo, char* str);
void syscall_schedule();
void syscall_block();
void syscall_unblock();
void syscall_kill(uint32_t pid);
void syscall_sleep(uint32_t pid, uint32_t sleepTime);
void syscall_prio(uint32_t pid, uint32_t prio);

#endif
