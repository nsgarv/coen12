#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "deque.h"

int main(void)
{
	DEQUE *list;
	DEQUE *bucket[10];
	int x, n, num, count;
	int k, i, j, r, f, l;
	r = 10;
	int numDigits;
	n = 0;
	list = createDeque();

	for(i=0; i<10; i++){
		bucket[i] = createDeque();
	}
	i = 0;
	printf("Enter some numbers to radix sort\n");
	printf("Hit return to store each number\n");
	printf("Press any key to execute sort\n");
	while (scanf("%d", &x) == 1){
		if(x>n)
			n = x;
		addLast(list, x);
	}
	count = numItems(list);
	printf("count is %d\n", count);
	numDigits = ceil((log(n+1)/log(10)));
	printf("numDigits is %d\n", numDigits);
//printf("---testprint---");
	for(k=0; k<=numDigits; k++)
	{
		while(numItems(list) != 0){
			num = removeFirst(list);
			printf("num is %d\n", num);
			j = (int)(num/pow(10,k))%10;         /* j is the bucket index */
			printf("bucket index is %d\n", j);
			addLast(bucket[j], num);
		}	
		while(i <= count){
			for(f=0; f < r; f++){
				while(numItems(bucket[f]) != 0){
					num = removeFirst(bucket[f]);
					printf("num2 is %d\n", num);
					addLast(list,num);
				}
			}
			i++;
		}
	}
	printf("number of items in the list is %d\n", numItems(list));
	l = 0;
	while(l <= numItems(list)){
		num = removeLast(list);
		printf("%d\n", num);
		l++;
	}
return 0;	
}