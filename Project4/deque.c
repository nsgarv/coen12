/*
 * File:	deque.c
 *
 * Description:	This file contains the functions necessary to traverse maze
 * 				using linked list to store decisions
 */
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdbool.h>
 #include <assert.h>
 #include "deque.h"
 /*
  *
  *
  */

typedef struct node NODE;

/*  Function: The structure for each node in LL DEQUE.
 *            The node points to next node and previous.
 *  NODE.
 */

struct node{
	int data;
	NODE *next;
	NODE *prev;
};

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

extern void destroyDeque(DEQUE *dp)
{
	NODE *phead;
	NODE *pcur;
	NODE *pdel;

	pcur = dp->head;
 	pdel = pcur->next;

	while(pcur->next != phead){
		free(pdel);
	}
}

 /*
  *
  *
  */
extern int numItems(DEQUE *dp)
{
	return dp->count;
	/*
	int count = 0;
	NODE *pcur;
	pcur = dp->head;
	while(pcur != NULL){
		count++;
		pcur = pcur->next;
	}
	return count;	
	*/
}

 /*
  *
  *
  */
extern void addFirst(DEQUE *dp, int x)
{
	NODE *pnew; 
	NODE *pprev;
	pnew = malloc(sizeof(NODE));
	assert(pnew != NULL);
	
	pprev = dp->head->next;

	pnew->data = x;
	pnew->next = pprev;
	pnew->prev = dp->head;

	dp->head->next = pnew;
	pprev->prev = pnew;
	dp->count++;
}

 /*
  *
  *
  */
extern void addLast(DEQUE *dp, int x)
{
	NODE *pnew;
	NODE *pold;

	pnew = malloc(sizeof(NODE));
	assert(pnew != NULL);
	pold = dp->head->prev;

	pnew->data = x;
	pnew->next = dp->head;
	pnew->prev = pold;
	pold->next = pnew;
	dp->count++;
}

 /*
  *
  *
  */
extern int removeFirst(DEQUE *dp)
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
extern int removeLast(DEQUE *dp)
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
extern int getFirst(DEQUE *dp)
{
	assert(dp->count != 0);
	return(dp->head->next->data);
}

 /*
  *
  *
  */
extern int getLast(DEQUE *dp)
{
	assert(dp->count != 0);
	return(dp->head->prev->data);
}

