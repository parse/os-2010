#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "types.h"
#include "Process.h"
#include "IOHandler.h"
#include "Settings.h"

typedef struct _Priority {
	PCB* current; // First process
	//char ; // Stores the number of iterations
} Priority;

Priority PriorityArray[PRIORITIES+1];
//PCB* lastPCB;

void run();
void copyRegisters(registers_t *target, registers_t *source);
int insertPCB(PCB* entry);
PCB* getPCB(int PID);
Process getProcess(int PID);
void freePID(int PID);
void freePCB(PCB* entry);
void initScheduler(registers_t *regs, int mem);
// TODO: ProcessTable* getProcessTable();

#endif
