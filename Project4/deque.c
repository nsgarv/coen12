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
 *  NODE.
 */
typedef struct node NODE;

struct node{
	int data;
	NODE *next;
	NODE *prev;
};
 /*
  *
  *
  */
/*  Function: The structure for the list. It contains the struct node
 *  		  that make up the linked list, where each node points to 
 *            the next and previous.
 *  DEQUE.
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

 /*
  *
  *
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
			//dp->count--;
			free(pdel);
		}
		return;
	}
 /*
  *
  *
  */
int numItems(DEQUE *dp)
{
	return dp->count;
}

 /*
  *
  *
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

 /*
  *
  *
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

 /*
  *
  *
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

 /*
  *
  *
  */
int removeLast(DEQUE *dp)
{
	assert(dp != NULL);
	int num;
	NODE *pdel;
	NODE *newlast;
	pdel = dp->head->prev; /*see above for algorithm concept. 
						same except deleting from last instead of first. */
	newlast = dp->head->prev->prev;
	num = pdel->data;
	dp->head->prev = pdel->prev;
	newlast->next = dp->head;
	dp->head->prev = newlast;

	free(pdel);
	dp->count--;
	return num;
}

 /*
  *
  *
  */
int getFirst(DEQUE *dp)
{
	assert(dp != NULL);
	return(dp->head->next->data);
}

 /*
  *
  *
  */
int getLast(DEQUE *dp)
{
	assert(dp != NULL);
	return(dp->head->prev->data);
}

