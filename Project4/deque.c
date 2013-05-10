/*
 * File:	deque.c
 *
 * Description:	This file contains the functions necessary to traverse maze
 * using linked list to store decisions
 */
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdbool.h>
 #include <assert.h>
 #include "deque.h"

typedef struct deque DEQUE;
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
	dp->head = malloc(sieof(NODE));
	assert(dp->head != NULL);
	dp->head->next = dp->head;
	dp->head->prev = dp->head;
	return dp;
}


extern void destroyDeque(DEQUE *dp)
{

}

extern int numItems(DEQUE *dp)
{
	int count = 0;
	NODE *pcur;
	pcur = dp->head;
	while(pcur != NULL){
		count ++;
		pcur = pcur->next;
	}
	return count;	
}

extern void addFirst(DEQUE *dp, int x)
{
	
}

extern void addLast(DEQUE *dp, int x)
{

}

extern int removeFirst(DEQUE *dp)
{

}

extern int removeLast(DEQUE *dp)
{

}

extern int getFirst(DEQUE *dp)
{
	assert(dp->count != 0);
	return(dp->head->next);
}

extern int getLast(DEQUE *dp)
{
	assert(dp-count != 0);
	return(dp->head->prev);
}

