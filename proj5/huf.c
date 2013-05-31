/*	
 * File:	huffman.c
 *
 * Description:	This program is an ADT for the files tree.h and pack.h. 
 *	It compresses a file and prints out the characters in the file, 
 *	how many times they appear, and the bit encoding assigned to them.
 *			
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "tree.h"
#include "pack.h"
#define END 256


typedef struct tree TREE;

int getrightChild (int i);
int getleftChild(int i);
int getparent(int i);
void insert(TREE*heap[], int*count, TREE*x);
void printHuffmanCode(TREE*leaf);
TREE*delete(TREE*heap[], int*count);

/*
 * Function:    main()
 *
 * Description: Prints out the Huffman code with the the amount of time a specific letter is counted while doing the binary heap.
 */
int main(int argc, char*argv[])
{
	FILE*fp;
	char *infile,*outfile,*mode ="rb";
	int c; //Holds the values for the characters to be read into.
	int count = 0; //Number of nodes in the heap
	int i; 
	int char_freq[END+1] = {0};//Used to hold the numbers of frequencies of arrays in the tree.
	TREE*leaves[END+1] = {NULL}; //Holds the leaves for each character with a nonzero count.
	TREE*heap[END+1] = {NULL};// Priority queue used to hold binary trees created in Huffman coding.

//These values are used to hold the tree taking from the priority queue and to hold the final tree constructed for bit coding.
	TREE*left;		
	TREE*right;
	TREE*newTree;

	if(argc!=3)//If all the arguments are not passed, print an error message and exit.
	{
		fprintf(stderr,"usage: %s infile outfile\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	infile = argv[1];
	outfile = argv[2];
	fp = fopen(infile, mode);
	if(fp == NULL)// if the file did not open or is empty, it will use the exit failure and say there is no file
	{
	printf("Either there is no file to open, it did not open successfully, or the file is empty. The program is now exiting.\n");
	exit(EXIT_FAILURE);
	}
	while((c = getc(fp))!=EOF)
	{
		char_freq[c]=char_freq[c]+1;//count the frequency that the letters are being read into the program from the file.
	}
	fclose(fp);

	for(i=0; i<END; i++)//traverses till it reaches the end of the tree array.
	{
		if(char_freq[i] != 0)
		{
			leaves[i] = createTree(char_freq[i], NULL, NULL); /* creating a new trees with a left 
																and right of null and setting that the data of 
																the leaves is the characters count 
																and create a tree with a zero count for the end 
																of the file marker. */
		} 
	}
	leaves[END] = createTree(0, NULL, NULL);//initializing the leaves at the end to 0.
	
	for(i=0; i<=END+1; i++)
	{
		if(leaves[i] != NULL) /* as long as we have the new tree with a zero 
								count for the end of the file marker, we will 
								enter the values into a priority que. */
		{
			insert(heap,&count,leaves[i]);	
		}	
	}
	
	while(count > 1)//While the pririty queue has more than 1 tree it will keep looping.
	{
		left = delete(heap, &count);
		right = delete(heap, &count);
		newTree = createTree(getData(left) + getData(right), left,right); //This adds the last two trees in the binary heap.
		insert(heap, &count, newTree);// This places the two last trees that were added into a priority queue.
	}

	for(i=0; i<END; i++)//This loop prints out the bits that were encodedm the character it is assinged to, and the amount of occurances of that character
	{
		if(char_freq[i] > 0)//leaves!=0
		{
			if(isprint(i) !=0)// if the values being passed in are not equal to 0, we will print out each line of the i.
			{
				printf(":'%c' : %d ", i, char_freq[i]);
				printHuffmanCode(leaves[i]);
				printf("\n");
			}
			else// if the values being passed are in fact equal to 0, then we will print out the octal, then the number of bits.
			{
				printf("%03o : %d ", i, char_freq[i]);
				printHuffmanCode(leaves[i]);
				printf("\n");
			}
		}
	}	
	printf("%03o : %d ", END, char_freq[END]);
	printHuffmanCode(leaves[END]);
	printf("\n");
	pack(infile, outfile, leaves);
	exit(EXIT_SUCCESS);
}

/*
 * Function:    rightChild()
 *
 * Description: fucntion to calculate where the right child values are supposed to go and passes it in.
 */
int getrightChild(int i)//fucntion to calculate where the right child values are supposed to go and passes it in.
{
	return (2*i + 1);
}

/*
 * Function:   leftChild()
 *
 * Description: function to calculate where the left child values are supposed to go and passes it in.
 */
int getleftChild(int i)//function to calculate where the right child values are supposed to go and passes it in.
{
	return (2*i + 2);
}

/*
 * Function:    parent()
 *
 * 
 * 
 *
 * Description: function to calculate where the parent values are suppsoed to go and passes it in.
 */
int getparent(int i)//function to calculate where the parent values are suppsoed to go and passes it in.
{
	return ((i-1)/2);
}

/*
 * Function:   delete()
 *
 * 
 * 
 *
 * Description: This delete of struct tree deletes the values from the heap.
 */
TREE*delete(TREE *heap[], int *count)// This delete of struct tree deletes the values from the heap.
{
	int i = 0;
	TREE *x;
	TREE *min;
	int child;
	
		
	min = heap[0];
	x = heap[--(*count)];
	while(getrightChild(i)<*count) //While the right child of i is not greater then the count, 
	{
		child = getrightChild(i);// this balances the min heap and makes sure it is a heap of min trees.
		if(getleftChild(i) < *count && getData(heap[getrightChild(i)]) > getData(heap[getleftChild(i)]))
		{
			child = getleftChild(i);
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
 * Function:    insert()
 *
 * Description: switches the parent with the data in the tree until the node with the smallest value in the root.
 */
void insert(TREE *heap[], int *count, TREE *x)
{
	int i;
	i = (*count)++;
	while( i>0 &&  getData(heap[getParent(i)]) > getData(x))// While the i of the loop is greater than zero and the data of the parent of i is greater then the input of the tree from which is being passed into.
	{
		heap[i] = heap[getParent(i)];//this switches the parent with the data in the tree until the node with the smallest value in the root.
		i = getParent(i);
	}
	heap[i] = x;
}

/*
 * Function:    printHuffmanCode()
 *
 * Description: function prints out the huffman code of the amount of times a character appears in the tree  by using recursion.
 */


void printHuffmanCode(TREE *leaf)// this function prints out the huffman code of the amount of times a character appears in the tree  by using recursion.
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
	
		

	


		
