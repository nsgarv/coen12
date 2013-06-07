/*
 * File:    deque.cpp
 *
 * Description: This file contains the functions necessary to traverse maze 
 *              and radix sort
 */
# include <cassert>
# include "deque.h"

typedef struct node NODE;

struct node {
    int data;
    NODE *next;
    NODE *prev;
};
 /*  Function: Constructor. Allocates memory for a new node
  *
  *  Complexity: O(1)
  */
Deque::Deque()
{
    count = 0;
    head = new NODE;

    head->next = head;
    head->prev = head;
}

 /*  Function: destructor Deallocates memory for every node in the list. 
  *            The function must act on every element in the list.
  *
  *  Complexity: O(n).
  */
Deque::~Deque()
{
    NODE *np, *next;

    np = head;

    do {
	next = np->next;
	delete np;
	np = next;
    } while (np != head);

}

 /* Function: Adds a new node after the head node.
  *
  * Complexity: O(1)
  */
void Deque::addFirst(int x)
{
    NODE *np = new NODE; 
    NODE *sentinel;
    np->data = x;

    count ++;
    sentinel = head;

    np->prev = sentinel;
    np->next = sentinel->next;

    sentinel->next->prev = np;
    sentinel->next = np;
}

 /* Function: Adds a new node to the end of the list. Since the list is circular,
  *           the last node is accesed by the nide befre the head.
  *
  * Complexity: O(1)
  */
void Deque::addLast(int x)
{
    NODE *np = new NODE;
    NODE *sentinel;

    np = new NODE;
    np->data = x;

    sentinel = head;
    count ++;

    np->prev = sentinel->prev;
    np->next = sentinel;

    sentinel->prev->next = np;
    sentinel->prev = np;
}

 /* Function: returns the vaue of the first node and deallocates memory.
  *
  * Complexity: O(1)
  */
int Deque::removeFirst()
{
    int x;
    struct node *np, *sentinel;

    assert(!NULL && count > 0);
    sentinel = head;
    count --;

    np = sentinel->next;
    sentinel->next = np->next;
    np->next->prev = sentinel;

    x = np->data;
    delete np;
    return x;
}

 /* Function: Returns the value of the last node and deallocates memory.
  *
  * Complexity: O(1)
  */
int Deque::removeLast()
{
    int x;
    NODE *np, *sentinel;

    assert(!NULL && count > 0);
    sentinel = head;
    count --;

    np = sentinel->prev;
    sentinel->prev = np->prev;
    np->prev->next = sentinel;

    x = np->data;
    delete np;
    return x;
}

 /* Function: Returns the value at the first node after the head.
  *
  * Complexity: O(1)
  */
int Deque::getFirst()
{
    return head->next->data;
}

 /* Function: Returns the value at the last node.
  *
  * Complexity: O(1)
  */
int Deque::getLast()
{
    return head->prev->data;
}

 /* Function: Returns the number or items in the list. 
  *           This value is incrimented when elements are 
  *           added or removed and stored in the head node.
  *
  * Complexity: O(1)
  */
int Deque::size()
{
    return count;
}
