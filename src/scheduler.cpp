/**************************************************************************
 File name:  scheduler.c
 Author:     
 Date:
 Class:
 Assignment:
 Purpose:
 *************************************************************************/
#include "../include/pqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX 10

typedef struct Process
{
  int processID;
	char szName[NAME_MAX];
} Process;


/****************************************************************************
 Function:    	addProc

 Description: 	Add a process to the PQ

 Parameters:  	psPQ - the PQ to add to
                procID - the process ID of the process
                szName - the name of the process
                runtime - the initial runtime of the process
 
 Returned:    	None
 ****************************************************************************/
void addProc(PriorityQueuePtr psPQ, int procID, char szName[NAME_MAX],
int runtime)
{
  Process sProc;


}

/****************************************************************************
 Function:    	printProcess

 Description: 	Print a process to the screen

 Parameters:  	psProc - the process to print
                runtime - the runtime to print
 
 Returned:    	None
 ****************************************************************************/
void printProcess(Process *psProc, int runtime)
{
    // DO NOT EDIT THIS FUNCTION
  printf("ProcessID: %d Name: %s Runtime: %d", 
		psProc->processID, psProc->szName, runtime);
}

/****************************************************************************
 Function:    	printTop

 Description: 	Print the process on the top of the PQ

 Parameters:  	psPQ - the PQ 
 
 Returned:    	None
 ****************************************************************************/
void printTop(PriorityQueuePtr psPQ)
{
  Process sProc;
  int runtime;

}

/****************************************************************************
 Function:    	runProcess

 Description: 	Run the process on the top of the PQ for the specified time
                Reinsert the process into the PQ with the new runtime

 Parameters:  	psPQ - the Priority Queue
                runtime - the runtime to add
 
 Returned:    	None
 ****************************************************************************/
void runProcess(PriorityQueuePtr psPQ, int runtime)
{

}

/****************************************************************************
 Function:    	terminateProcess

 Description: 	Terminate the process on the top of the PQ
                Remove the process from the PQ

 Parameters:  	psPQ - the Priority Queue

 Returned:    	None
 ****************************************************************************/
void terminateProcess(PriorityQueuePtr psPQ)
{
}

/****************************************************************************
 Function:    	boost

 Description: 	Subtract the specified runtime from all processes in the PQ

 Parameters:  	psPQ - the Priority Queue
                value - the runtime to subtract from all processes
 
 Returned:    	None
 ****************************************************************************/
void boost(PriorityQueuePtr psPQ, int value)
{
}

/****************************************************************************
 Function:    	emptyPQ

 Description: 	Call terminateProcess() for each process in the PQ

 Parameters:  	psPQ - the Priority Queue
 
 Returned:    	None
 ****************************************************************************/
void emptyPQ(PriorityQueuePtr psPQ)
{
}

/****************************************************************************
 Function:    	loadProcesses

 Description: 	Load processes from a file into the PQ.

 Parameters:  	psPQ - the PQ to add to
 
 Returned:    	None
 ****************************************************************************/
void loadProcesses(PriorityQueuePtr psPQ)
{
  FILE *pFile;
  int runtime;
  Process sProc;

  pFile = fopen("data/processes.dat","r");
	while(EOF != fscanf(pFile, "%d %s %d",
		&sProc.processID, sProc.szName, &runtime))
	{
	  // TODO: Add the process to the PQ!
	}
	fclose(pFile);
}

/****************************************************************************
 Function:    	main

 Description: 	Simulate a process scheduler!

 Parameters:  	None
 
 Returned:    	None
 ****************************************************************************/
int main()
{
  PriorityQueue sPQ;
  int value;
  int runtime, procID;
  FILE *pActions;
  char action;
	char szName[NAME_MAX];
  
  pqueueCreate(&sPQ, sizeof(Process));
  loadProcesses(&sPQ);
  
  pActions = fopen("data/actions.dat","r");
	while(EOF != fscanf(pActions, "%c",&action))
	{
    switch(action)
    {
      case 'A':
        fscanf(pActions, "%d %s %d ", &procID, szName, &runtime);
        addProc(&sPQ, procID, szName, runtime);
        break;
      case 'B':
        fscanf(pActions, "%d", &value);
        boost(&sPQ, value);
        break;
      case 'P':
        printTop(&sPQ);
        break;
      case 'R':
        fscanf(pActions, "%d ", &runtime);
        runProcess(&sPQ, runtime);
        break;
      case 'T':
        terminateProcess(&sPQ);
        break;
    }
  }
  fclose(pActions);

  emptyPQ(&sPQ);

  return EXIT_SUCCESS;
  
}
