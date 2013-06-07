# include <iostream>
# include "deque.h"

Deque::Deque()
{

    count = 0;
    head = new NODE;

    head->next = head;
    head->prev = head;

}


Deque::~Deque()
{
    NODE *np, *next;

    np = dp->head;

    do {
	next = np->next;
	delete[] np;
	np = next;
    } while (np != dp->head);

    delete[] dp;
}


void Deque::addFirst(int x)
{
    NODE *np, *sentinel;
    np->data = x;

    count ++;
    sentinel = head;

    np->prev = sentinel;
    np->next = sentinel->next;

    sentinel->next->prev = np;
    sentinel->next = np;
}


void Deque::addLast(int x)
{
    NODE *np, *sentinel;

    np = new NODE;
    np->data = x;

    sentinel = dp->head;
    dp->count ++;

    np->prev = sentinel->prev;
    np->next = sentinel;

    sentinel->prev->next = np;
    sentinel->prev = np;
}


int Deque::removeFirst()
{
    int x;
    struct node *np, *sentinel;


    assert(!NULL && dp->count > 0);
    sentinel = head;
    count --;

    np = sentinel->next;
    sentinel->next = np->next;
    np->next->prev = sentinel;

    x = np->data;
    delete[] np;
    return x;
}


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
    delete[] np;
    return x;
}


int Deque::getFirst()
{

    return head->next->data;
}


int Deque::getLast()
{

    return head->prev->data;
}


int Deque::size()
{
    return count;
}
