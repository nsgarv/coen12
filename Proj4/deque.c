/*
 * File:	deque.c
 *
 * Description:	This file contains the functions necessary to traverse maze
 * 				using linked list to store decisions
 */
 #include <stdio.h>
 #include <stdlib.h>
 #include <assert.h>
 #include "deque.h"

/*  Function: The structure for each node in LL DEQUE.
 *            The node points to next node and previous.
 *  Complexity: O(1). Does not allocate memory
 *  NODE
 */
typedef struct node NODE;

struct node{
	int data;
	NODE *next;
	NODE *prev;
};

/*  Function: The structure for the list. It contains the struct node
 *  		  that make up the linked list, where each node points to 
 *            the next and previous.
 *
 *  Complexity: O(1). Does not allocate memoryv
 *  DEQUE
 */
struct deque{ 
	int count;
	NODE *head;
};

DEQUE *createDeque(void){
	DEQUE *dp;
	dp = malloc(sizeof(DEQUE));
	assert(dp != NULL);
	dp->count = 0;
	dp->head = malloc(sizeof(NODE));
	assert(dp->head != NULL);
	dp->head->next = dp->head;
	dp->head->prev = dp->head;
	return dp;
}

 /*  Function: Deallocates memory for every node in the list. 
  *            The function must act on every element in the list.
  *
  *  Complexity: O(n).
  */
void destroyDeque(DEQUE *dp)
{
	assert(dp != NULL);
	NODE *pdel;

	int i;
	for(i=0; i<dp->count; i++)
	{
		pdel = dp->head->next;
		dp->head->next = pdel->next;
		free(pdel);
	}
	return;
}

 /* Function: Returns the number or items in the list. 
  * 		  This value is incrimented when elements are 
  * 		  added or removed and stored in the head node.
  *
  * Complexity: O(1)
  */
int numItems(DEQUE *dp)
{
	return dp->count;
}

 /* Function: Adds a new node after the head node.
  *
  * Complexity: O(1)
  */
void addFirst(DEQUE *dp, int x)
{
	assert(dp != NULL);
	NODE *pnew; 
	pnew = malloc(sizeof(NODE));
	assert(pnew != NULL);

	pnew->data = x;
	pnew->prev = dp->head;
	pnew->next = dp->head->next;
	dp->head->next->prev = pnew;
	dp->head->next = pnew;
	dp->count++;
	return;
}

 /* Function: Adds a new node to the end of the list. Since the list is circular,
  *			  the last node is accesed by the nide befre the head.
  *
  * Complexity: O(1)
  */
void addLast(DEQUE *dp, int x)
{
	assert(dp != NULL);
	NODE *pnew;
	pnew = malloc(sizeof(NODE));
	assert(pnew != NULL);

	pnew->data = x;
	pnew->next = dp->head;
	pnew->prev = dp->head->prev;
	dp->head->prev->next = pnew;
	dp->head->prev = pnew;
	dp->count++;
}

 /* Function: returns the vaue of the first node and deallocates memory.
  *
  * Complexity: O(1)
  */
int removeFirst(DEQUE *dp)
{
	assert(dp != NULL);
	int num;
	NODE *newnext;
	NODE *pdel; 
	pdel = dp->head->next; 
	num = pdel->data;
	newnext = pdel->next;
	dp->head->next = newnext;
	newnext->prev = dp->head;
	newnext->next = pdel->next->next;
	free(pdel);
	dp->count--;
	return num;
}

 /* Function: Returns the value of the last node and deallocates memory.
  *
  * Complexity: O(1)
  */
int removeLast(DEQUE *dp)
{
	assert(dp != NULL);
	int num;
	NODE *pdel;
	NODE *newlast;
	pdel = dp->head->prev;
	newlast = dp->head->prev->prev;
	num = pdel->data;
	dp->head->prev = pdel->prev;
	newlast->next = dp->head;
	dp->head->prev = newlast;

	free(pdel);
	dp->count--;
	return num;
}

 /* Function: Returns the value at the first node after the head.
  *
  * Complexity: O(1)
  */
int getFirst(DEQUE *dp)
{
	assert(dp != NULL);
	return(dp->head->next->data);
}

 /* Function: Returns the value at the last node.
  *
  * Complexity: O(1)
  */
int getLast(DEQUE *dp)
{
	assert(dp != NULL);
	return(dp->head->prev->data);
}

