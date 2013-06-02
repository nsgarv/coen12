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
static TREE *nodes[END + 1];

int getrc (int x);
int getlc(int x);
int getp(int x);
void insert(TREE *heap[], int count, TREE *x);
void printHuf(TREE *leaf);
TREE *delete(TREE *heap[], int count);
/*
int main(int argc, char *argv[])
{
		
	if (argc != 3) {                //check if a text file is specified
	printf ("failed arguements\n");
	return (0);
	}
		 
	int count = 0;
	FILE *fp = fopen(argv[1] , "r");  
	if (fp == NULL){                  //check if the file has anything in it
		printf("cant open file\n");
	return(0);
	 }

	char word[MAX_WORD_LENGTH];

	while (fscanf(fp, "%s" , word) == 1){ //scnning letters into array word until fstanf returns interger 1
		count++;
	}
	printf("%d total words\n", count);
}
*/
int main(int argc, char *argv[])
{
	FILE *fp;
	char *infile, *outfile;
	int c; //Holds the values for the characters to be read into.
	int i; 
	int counts[END+1] = {0}; //Used to hold the numbers of frequencies of arrays in the tree.
	

	TREE*left;		
	TREE*right;
	TREE*newTree;

	infile = argv[1];
	outfile = argv[2];
	if (argc != 3) {                //check if a text file is specified
		printf ("failed arguements\n");
		return (0);
	}

	fp = fopen(infile , "r");  
	if (fp == NULL){                  //check if the file has anything in it
		printf("Can't open file\n");
	return(0);
	}
	while((c = getc(fp))!=EOF){
		counts[c]++;
	}
	fclose(fp);

	//TREE *createTree(int data, TREE *left, TREE *right)
	for (i=0; i <END; i++){
		if (counts[i] != 0)
			nodes[i] = createTree(counts[i], NULL, NULL);  
	}
	nodes[END] = createTree(0,NULL,NULL);

	for(i=0; i<=END+1; i++){
		if(nodes[i] != NULL){
			insert(heap,count,nodes[i]);
		}
	}

	while(count > 1){
		left = delete(heap,count);
		right = delete(heap,count);
		newTree = createTree(getData(left) + getData(right), left, right);
		insert(heap, count, newTree);
	}

	for(i=0; i<END; i++){
		if(counts[i] > 0){
			if(isprint(i) != 0){
				printf(":'%c' : %d", i, counts[i]);
				printHuf(nodes[i]);
				printf("\n");
			}else{
				printf("%03o : %d ", i, counts[i]);
				printHuf(nodes[i]);
				printf("\n");
			}
		}
	}
	printf("%03o : %d", END, counts[END]);
	printHuf(nodes[END]);
	printf("\n");
	pack(infile, outfile, nodes);
	return(0);
}



/*
 * Funtion: 
 *
 * Complexity:
 *
 * Description: 
 *
 */
int getr(int x)
{
	return r(x);
}

/*
 * Funtion: 
 *
 * Complexity:
 *
 * Description: 
 *
 */
int getl(int x)
{
	return l(x);
}

/*
 * Funtion: 
 *
 * Complexity:
 *
 * Description: 
 *
 */
int getp(int x)
{
	return p(x);
}

/*
 * Funtion: 
 *
 * Complexity:
 *
 * Description: 
 *
 */
TREE *delete(TREE *heap[], int count)// This delete of struct tree deletes the values from the heap.
{
	int i = 0;
	TREE *x;
	TREE *min;
	int child; //heap index location of child
	
		
	min = heap[0];
	x = heap[ -- count];
	while(getr(i) < count) 
	{
		child = getr(i);
		if(getl(i) < count && getData(heap[getr(i)]) > getData(heap[getl(i)]))
		{
			child = getl(i);
		}
		if(getData(x) > getData(heap[child]))
		{
			heap[i] = heap[child];
			i = child;
		}
		else
		{
			break;
		}
	}
	heap[i] = x;
	return min;
}

/*
 * Funtion: 
 *
 * Complexity:
 *
 * Description: 
 *
 */
void insert(TREE *heap[], int count, TREE *x)
{
	int i;
	i = count++;
	while( i>0 &&  getData(heap[getp(i)]) > getData(x))/* While the i of the loop is greater 
															   than zero and the data of the parent 
															   of i is greater then the input of the 
															   tree from which is being passed into. */
	{
		heap[i] = heap[getp(i)];/* this switches the parent with the data 
										in the tree until the node with the smalles
										value in the root. */
		i = getp(i);
	}
	heap[i] = x;
}

/*
 * Funtion: 
 *
 * Complexity:
 *
 * Description: 
 *
 */
void printHuf(TREE *leaf)//this function prints out the huffman code 
						 //of the amount of times a character appears in the tree by using recursion.
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