/**************************************************************************
 File name:		  pqueue.h
 Author:        CS, Pacific University
 Date:          10/18/17
 Class:         CS300
 Assignment:    Priority Queue Implementation
 Purpose:       This file defines the constants, data structures, and
                function prototypes for implementing a priority queue data
                structure.
 *************************************************************************/

#ifndef PQUEUE_H_
#define PQUEUE_H_

#include <stdbool.h>
#include <stdlib.h> // size_t
#include <stdio.h>

//*************************************************************************
// Error reporting functions
//*************************************************************************
extern void processError(const char* szFile, const int line);
// helper function to report errors

// macro to report error
#define reportError   processError(__FILE__, __LINE__)

//*************************************************************************
// User-defined types
//*************************************************************************

#define PQ_SIZE 127

typedef struct PriorityQueueElement
{
	int priority;
	void* pData;
} PriorityQueueElement;
typedef PriorityQueueElement* PriorityQueueElementPtr;


typedef struct PriorityQueue *PriorityQueuePtr;
typedef struct PriorityQueue
{
	PriorityQueueElement aTheList[PQ_SIZE];
	int currentNumberOfItems;
	size_t itemSize;
} PriorityQueue;

//*************************************************************************
//										Allocation and Deallocation
//*************************************************************************
extern void pqueueCreate (PriorityQueuePtr psQueue, size_t itemSize);
// results: If PQ can be created, then PQ exists and is empty


extern void pqueueTerminate (PriorityQueuePtr psQueue);
// results: If PQ can be terminated, then PQ no longer exists and is empty

//*************************************************************************
//									Checking number of elements in priority queue
//*************************************************************************

extern int pqueueCount (const PriorityQueuePtr psQueue);
// results: Returns the number of elements in the PQ

extern bool pqueueIsEmpty (const PriorityQueuePtr psQueue);
// results: If PQ is empty, return true; otherwise, return false
extern bool pqueueIsFull(const PriorityQueuePtr psQueue);

//*************************************************************************
//									Inserting and retrieving values
//*************************************************************************

extern bool pqueueEnqueue (PriorityQueuePtr psQueue, const void *pBuffer,
										 int priority);
// requires: psQueue is not full
// results: Insert the element into the priority queue based on the
//          priority of the element.

extern bool pqueueDequeue (PriorityQueuePtr psQueue, void *pBuffer,
														int  *pPriority);

// requires: psQueue is not empty
// results: Remove the element from the front of a non-empty queue

//*************************************************************************
//													Peek Operations
//*************************************************************************

extern bool pqueuePeek (PriorityQueuePtr psQueue, void *pBuffer,
								 int *priority);
// requires: psQueue is not empty
// results: The priority and value of the first element is returned through
//					the argument list
// IMPORTANT: Do not remove element from the queue

extern bool pqueueChangePriority (PriorityQueuePtr psQueue,
																	int change);
// results: The priority of all elements is increased by the amount in
// change. Change may be positive or negative.

#endif /* PQUEUE_H_ */
