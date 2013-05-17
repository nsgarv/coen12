#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "deque.h"

int main(void)
{
	DEQUE *list;
	DEQUE *bucket[10];
	int x, i;
	list = createDeque();

	for(i=0; i<10; i++){
		bucket(i) = createDeque();
	}

	printf("Enter some numbers to radix sort\npress any key to continue\n>>");
	while (scanf("%d\n", &x) == 1)

}