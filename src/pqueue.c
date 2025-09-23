#include "../include/pqueue.h"
#include <stdlib.h>
#include <string.h>
/**************************************************************************
 Function: 	 	processError - DO NOT EDIT


 Description: Print the filename and line number of an error

 Parameters:	szFile - filename
              line - the line number

 Returned:	 	None
 *************************************************************************/
void processError(const char* szFile, const int line)
{
  fprintf(stderr, "ERROR: %s: %d\n", szFile, line);
  fflush(NULL);
  exit(EXIT_FAILURE);
}
 void pqueueCreate (PriorityQueuePtr psQueue, size_t itemSize)
 {

 }
// results: If PQ can be created, then PQ exists and is empty


 void pqueueTerminate (PriorityQueuePtr psQueue)
 {
	
 }
// results: If PQ can be terminated, then PQ no longer exists and is empty

//*************************************************************************
//									Checking number of elements in priority queue
//*************************************************************************

int pqueueCount (const PriorityQueuePtr psQueue)
{
}
// results: Returns the number of elements in the PQ

bool pqueueIsEmpty (const PriorityQueuePtr psQueue)
{
  return false;
}

bool pqueueIsFull(const PriorityQueuePtr psQueue)
{
  return false;
}

// results: If PQ is empty, return true; otherwise, return false


//*************************************************************************
//									Inserting and retrieving values
//*************************************************************************

// requires: psQueue is not full
// results: Insert the element into the priority queue based on the
//          priority of the element.


bool pqueueEnqueue (PriorityQueuePtr psQueue, const void *pBuffer,
										int priority)
{
	bool bRetVal = false;
	return bRetVal;
}


bool pqueueDequeue (PriorityQueuePtr psQueue, void *pBuffer,
														int  *pPriority)
{
	bool bRetVal = false;
	return bRetVal;
}
// requires: psQueue is not empty
// results: Remove the element from the front of a non-empty queue

//*************************************************************************
//													Peek Operations
//*************************************************************************

bool pqueuePeek (PriorityQueuePtr psQueue, void *pBuffer, 
								 int *pPriority)
{
	bool bRetVal = false;

	return bRetVal;
}

// requires: psQueue is not empty
// results: The priority and value of the first element is returned through
//					the argument list
// IMPORTANT: Do not remove element from the queue

bool pqueueChangePriority (PriorityQueuePtr psQueue,
																	int change)
{
	bool bRetVal = false;
	return bRetVal;
}
// results: The priority of all elements is increased by the amount in
