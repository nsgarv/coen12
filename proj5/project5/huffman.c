#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "tree.h"
#include "pack.h"
#define END 256
#define p(x) (((x) - 1) / 2)
#define l(x) ((x) * 2 + 1)
#define r(x) ((x) * 2 + 2)

typedef struct tree TREE;
static int count;
static TREE *heap[END + 1];
static TREE *leaves[END + 1];

void insert(TREE *heap[], int count, TREE *x);
void printHuf(TREE *leaves);
TREE *delete(TREE *heap[], int count);


int main(int argc, char *argv[])
{
	FILE *fp;
	int c; //Holds the values for the characters to be read into.
	int i; 
	int charcount[END+1] = {0}; //Used to hold the numbers of frequencies of arrays in the tree.
	

	TREE *left;		
	TREE *right;
	TREE *node;

	if (argc != 3) {                //check if a text file is specified
		printf ("failed arguements\n");
		return (1);
	}

	fp = fopen(argv[1] , "r");  
	if (fp == NULL){                  //check if the file has anything in it
		printf("Can't open file\n");
		return(1);
	}

	/* count the number of occurances of each character in the file */
	while((c = getc(fp))!=EOF){
		charcount[c]++;
	}
	fclose(fp);

	//TREE *createTree(int data, TREE *left, TREE *right)
	/* create a binary tree of leaves of each character with a non zero count.
	   Insert all trees into a priority queue. */
	for (i=0; i <END; i++){
		if (charcount[i] != 0)
			leaves[i] = createTree(charcount[i], NULL, NULL);  
	}
	leaves[END] = createTree(0,NULL,NULL); //End file marker

	for(i=0; i<=END+1; i++){
		if(leaves[i] != NULL){
			insert(heap,count,leaves[i]);
		}
	}
	/* while the priotiry queue has more than one tree in it, remove the two lowest priority trees.
	   Create a node with each of these trees as subtrees. 
	   The count for the new tree is the sum of the counts of the two subtrees. 
	   Insert the new tree into the priority queue. */
	while(count > 1){
		left = delete(heap,count);
		right = delete(heap,count);
		node = createTree(getData(left) + getData(right), left, right);
		insert(heap, count, node);
	}

	for(i=0; i<END; i++){
		if(charcount[i] > 0){
			if(isprint(i) != 0){
				printf("'%c' : %d", i, charcount[i]);
				printHuf(leaves[i]);
				printf("\n");
			}else{
				printf("%03o : %d ", i, charcount[i]);
				printHuf(leaves[i]);
				printf("\n");
			}
		}
	}
	printf("%03o : %d", END, charcount[END]);
	printHuf(leaves[END]);
	printf("\n");
	pack(argv[1], argv[2], leaves);
	return(0);
}
/*
 * Funtion: delete()
 *
 * Complexity: O(n)
 *
 * Description: 
 *
 */

 TREE *delete(TREE *heap[], int count)
{
	//Initialize variable, tree to delete (from front), tree to move (last)
	int i = 0;
	int child;
	TREE *temp, *del;
	del = heap[0];
	temp = heap[--count];
	//Perform Deletion
	while ((r(count)) < count)
	{
		int left = l(count);
		child = left;
		if (l(count) < count && (getData(heap[l(count)])) < getData(heap[r(count)])){
			child = left + 1;
		}
		if (getData(temp) > getData(heap[child])) {
			heap[i] = heap[child];
		}
		else
			break;	
			}
	//Decrement Count		
	count--;
	return del;
}
/*
 * Funtion: 
 *
 * Complexity:
 *
 * Description: 
 *
 */

void insert(TREE *heap[], int count, TREE *node)
{
	//Change the count initialize variables
	int i;
	//Perform swaps add the new node in the appropriate arranged location
	i = count++;
	while (i > 0) {
		if (getData(heap[p(i)]) > getData(node)) {
			heap[i] = heap[p(i)];
			i = p(i);
		}
	}
	heap[i] = node;
}

/*
 * Funtion: PrintHuf()
 *
 * Complexity: 
 *
 * Description: 
 *
 */
void printHuf(TREE *leaf)
						 
{
	if(getParent(leaf) != NULL)
	{
		printHuf(getParent(leaf));
		if(getLeft(getParent(leaf)) == leaf)
		{
			printf("0");
		}
		else
		{
			printf("1");
		}   
	}
}