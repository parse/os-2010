#include "Interrupt.h"

#include "UserPrograms.h"
#include "stdlib.h"
/**
 * enableInterrupt()
 * Enables interrupt handling in the registry
 */
void enableInterrupt() {
 	display_word(1);
	puts("\nSex\n");

 	/* Initialise timer to interrupt in 100 ms (simulated time). */
 	kload_timer(100 * timer_msec);

 	/* Update the status register to enable timer interrupts. */
 	kset_sr(0xFFBF00E8, 0x10008001);
	
	putsln("Interrupts are now enabled!");
}

/* kexception:
 *   Application-specific exception handler, called after registers
 *   have been saved.
 */
void kexception()
{
	cause_reg_t cause;
	
	putsln("Interrupt has arrived!");
	char buffer[10];
	putsln(itoa(&HelloWorld, buffer, 10));
	//Make sure that we are here because of a timer interrupt.
	cause.reg = kget_cause();
	
	kdebug_assert(cause.field.exc == 0);	/* External interrupt */
	kdebug_assert(cause.field.ip & 0x80);   /* Timer interrupt */
	
	run();
	
 	/* Reload timer for another 100 ms (simulated time) */
	kload_timer(1 * timer_msec);
}