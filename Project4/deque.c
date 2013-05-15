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
	pnew->prev = dp->head->prev->prev;
	dp->head->prev = pnew;
	dp->count++;
}

 /*
  *
  *
  */
int removeFirst(DEQUE *dp)
{
	int num;
	NODE *phead;
	phead = dp->head; //the head node
	NODE *pdel;       //node after head we wish to delete
	pdel = phead->next; //setting the node to be deleted as the node after phead
	num = pdel->data;
	phead->next = pdel->next; /* node after the node after head is the new node after head.
							   aka phead next now becomes what was previously the third node */
	(pdel->next)->prev = phead;       //the node after the deleted node points back to head
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
	int num;
	NODE *phead;
	NODE *nplast;
	phead = dp->head;
	NODE *pdel;
	pdel = phead->prev; /*see above for algorithm concept. 
						same except deleting from last instead of first. */
	num = pdel->data;
	nplast = pdel->prev;
	nplast->next = phead;
	phead->prev = nplast;

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
	//assert(dp->count != 0);
	return(dp->head->next->data);
}

 /*
  *
  *
  */
int getLast(DEQUE *dp)
{
	//assert(dp->count != 0);
	return(dp->head->prev->data);
}

