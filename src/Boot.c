#include "Boot.h"
static registers_t regs;

/**
 * main()
 * The main function takes no arguments and is the function that initiate the
 * first essential functions of the OS
 * This function will never reach its end, since run is a non terminating function.
 */
int OS(int memoryMin) {
	// Initiate spot for registers to be saved
 	kset_registers(&regs);
	
	// Initiate the I/O-devices needed
	// Module: IOHandler
	initIO();
		
	// Initiate the OS essentials (including the first process/PCB)
	// Module: Process
	initOS(memoryMin);
	
	initScheduler(&regs, memoryMin);
	
	// Enable the interrupt bit and the interrupt handler
	// Module: Interrupt
	enableInterrupt();

	// Test of 
	//my_system_call(0x61);
	
	while (1);
	
	// Run the scheduler
	// Module: Scheduler
	//HelloWorld();
	//run(memoryMin);
	
	return memoryMin;
}