#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "deque.h"

int main(void)
{
	/* creating list of type DEQUE and bucket of type DEQUE 
		to be uses in the intermediate steps of sorting. 
	*/

	DEQUE *list;
	DEQUE *bucket[10];
	int x, n, num, count;
	int k, i, j, r, f, l;
	r = 10;
	int numDigits;
	n = 0;

	/*  Only one list is required and createDeque() allocates memory for the list */
	list = createDeque();

	/*  there are 10 buckets used in this sorting algorithm 
		so an array of 10 is allocated */
	for(i=0; i<10; i++){
		bucket[i] = createDeque();
	}
	i = 0;
	printf("Enter some numbers to radix sort\n");
	printf("Hit return to store each number\n");
	printf("Press any key to execute sort\n");

	/*  Takeing in the values from user input and strogint hem in the initial list */
	while (scanf("%d", &x) == 1){
		if(x>n)
			n = x;
		addLast(list, x);
	}

	/*  getting the number of entries used later in loops */
	count = numItems(list);
	numDigits = ceil((log(n+1)/log(10)));


	/*  loops over for each decimal place using the largest number as the maximum. 
		The first while loop takes the numbers and places them into their buckets. */
	for(k=0; k<(numDigits+1); k++)
	{
		while(numItems(list) != 0){
			num = removeFirst(list);
			j = (int)(num/pow(10,k))%10;         /* j is the bucket index */
			addLast(bucket[j], num);
		}	
		i = 0;

		/*  this second while loop takes the numbers brom their buckets 
			and adds them back to the list.
			the process is repeaated until the number of digits is reached. 
		*/
		while(i <= count){
			for(f=0; f < r; f++){
				while(numItems(bucket[f]) != 0){
					num = removeFirst(bucket[f]);
					addLast(list,num);
				}
			}
			i++;
		}
	}
	printf("number of items in the list is %d\n", numItems(list));
	l = 0;
	while(numItems(list) != 0){
		num = removeFirst(list);
		printf("%d\n", num);
		l++;
	}
return 0;	
}