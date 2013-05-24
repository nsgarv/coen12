#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"
/*
 * Funtion:	
 *
 * Complexity:
 *
 * Description:	
 *
 */
typedef struct tree TREE;

struct tree{
	int data;
	TREE *parent;
	TREE *leftChild;
	TREE *rightChild;
};


TREE *createTree(int data, TREE *left, TREE *right)
{
	TREE *root;
	root = malloc(sizeof(TREE));
	assert(root != NULL);
	root->data = data;
	root->rightChild = malloc(sizeof(TREE));
	assert(root->rightChild != NULL);
	root->leftChild = malloc(sizeof(TREE));
	assert(root->leftChild != NULL);

	if (left->parent != NULL){
		if(left->data < data)
			root->leftChild = left;
		else if(left->data > data)
			root->rightChild = left;
	}
	if (right->parent != NULL){
		if(right->data < data)
			root->leftChild = right;
		else if(right->data > data)
			root->rightChild = left;
	}

	return root;
}
/*
 * Funtion:	
 *
 * Complexity:
 *
 * Description:	
 *
 */
void destroyTree(TREE *root)
{
	if(root == NULL)
		return;
	destroyTree(root->leftChild);
	destroyTree(root->rightChild);
	free(root);
}
/*
 * Funtion:	
 *
 * Complexity:
 *
 * Description:	
 *
 */
int getData(TREE *root)
{
	assert(root != NULL);
	return root->data;
}
/*
 * Funtion:	
 *
 * Complexity:
 *
 * Description:	
 *
 */
TREE *getLeft(TREE *root)
{
	assert(root != NULL);
	return root->leftChild;	
}
/*
 * Funtion:	
 *
 * Complexity:
 *
 * Description:	
 *
 */
TREE *getRight(TREE *root)
{
	assert(root != NULL);
	return root->rightChild;
}
/*
 * Funtion:	
 *
 * Complexity:
 *
 * Description:	
 *
 */
TREE *getParent(TREE *root)
{
	assert(root != NULL);
	return root->parent;
}
/*
 * Funtion:	
 *
 * Complexity:
 *
 * Description:	
 *
 */
void setLeft(TREE *root, TREE *left)
{
	assert(root != NULL);
	root->leftChild = left;
}
/*
 * Funtion:	
 *
 * Complexity:
 *
 * Description:	
 *
 */
void setRight(TREE *root, TREE *right)
{
	assert(root != NULL);
	root->rightChild = right;
}