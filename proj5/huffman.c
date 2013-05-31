#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "tree.h"
#include "pack.h"
#define END = 256
#define p(x) (((x)-1)/2)
#define l(x) ((x)*2 + 1);
#define r(x) ((x)*2 + 2)

typedef struct tree TREE;

int getrc (int i);
int getlc(int i);
int getp(int i);
void insert(TREE *heap[], int *count, TREE *x);
void printHuf(TREE*leaf);
TREE *delete(TREE *heap[], int *count);
static int count;
static TREE *heap[END + 1];
static TREE *nodes[END + 1];
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
	char *infile, *outfile , *mode = "r";
	int c; //Holds the values for the characters to be read into.
	int count = 0; //Number of nodes in the heap
	int i; 
	int counts[END+1] = {0}; //Used to hold the numbers of frequencies of arrays in the tree.
	TREE *leaves[END+1] = {NULL}; //Holds the leaves for each character with a nonzero count.
	TREE *heap[END+1] = {NULL}; // Priority queue used to hold binary trees created in Huffman coding.

	infile = argv[1];
	outfile = argv[2];
	if (argc != 3) {                //check if a text file is specified
    	printf ("failed arguements\n");
    	return (0);
    }

    FILE *fp = fopen(argv[1] , "r");  
    if (fp == NULL){                  //check if the file has anything in it
    	printf("cant open file\n");
    return(0);
     }
     while 
	fp = fopen(argv[1] , "r");
	while((c = getc(fp))!=EOF))
		counts[c]++;


}

/*
 * Funtion:	
 *
 * Complexity:
 *
 * Description:	
 *
 */
int getrc(int i)
{
	return (2*i + 2);
}

/*
 * Funtion:	
 *
 * Complexity:
 *
 * Description:	
 *
 */
int getlc(int i)
{
	return (2*i + 1);
}

/*
 * Funtion:	
 *
 * Complexity:
 *
 * Description:	
 *
 */
int getparent(int i)
{
	return ((i-1)/2);
}

/*
 * Funtion:	
 *
 * Complexity:
 *
 * Description:	
 *
 */
TREE *delete(TREE *heap[], int *count)// This delete of struct tree deletes the values from the heap.
{
	int i = 0;
	TREE *x;
	TREE *min;
	int child; //heap index location of child
	
		
	min = heap[0];
	x = heap[--(*count)];
	while(getrc(i)<*count) //While the right child of i is not greater then the count, 
	{
		child = getrc(i);// this balances the min heap and makes sure it is a heap of min trees.
		if(getleftChild(i) < *count && getData(heap[getrc(i)]) > getData(heap[getlc(i)]))
		{
			child = getlc(i);
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
void insert(TREE *heap[], int *count, TREE *x)
{
	int i;
	i = (*count)++;
	while( i>0 &&  getData(heap[getParent(i)]) > getData(x))/* While the i of the loop is greater 
															   than zero and the data of the parent 
															   of i is greater then the input of the 
		   													   tree from which is being passed into. */
	{
		heap[i] = heap[getParent(i)];/* this switches the parent with the data 
										in the tree until the node with the smalles
										value in the root. */
		i = getParent(i);
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
		printHuffmanCode(getParent(leaf));
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