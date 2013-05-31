#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"

/*
 * Funtion:	struct TREE
 *
 * Complexity: O(1) 
 *
 * Description:	the data structure for root/leaf/node.
 *				It contains pointers to the parent, 
 *				left and right children and a data value.
 */
typedef struct tree TREE;

struct tree{
	int data;
	TREE *parent;
	TREE *leftChild;
	TREE *rightChild;
};

/*
 * Funtion:	CreateTree
 *
 * Complexity: O(1)
 *
 * Description:	Creates a root and allocates memory for a structure of type tree
 * 				and determines if it is the left or right child of its parent.
 */
TREE *createTree(int data, TREE *left, TREE *right)
{
	TREE *root;
	root = malloc(sizeof(TREE));
	assert(root != NULL);
	root->data = data;

	root->leftChild = left;
	if (left != NULL){
		if (left->parent != NULL){
			if (left->parent->leftChild == left)
				left->parent->leftChild = NULL;
			if (left->parent->rightChild == left)
				left->parent->rightChild = NULL;
			left->parent = root;
		}
	}
	root->rightChild = right;
	if (right != NULL){
		if (right->parent != NULL){
			if (right->parent->leftChild == right)
				right->parent->leftChild = NULL;
			if (right->parent->rightChild == right)
				right->parent->rightChild = NULL;
			right->parent = root;
		}
	}
	return root;
}
/*
 * Funtion:	DestoryTree
 *
 * Complexity: O(n)
 *
 * Description:	Preforms a post order traversal of the root and deallocates 
 *				memory for each node until it frees the root.
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
 * Funtion:	getData
 *
 * Complexity: O(1)
 *
 * Description:	getData simply recieves a root and returns 
 *				the data field in struct tree
 *
 */
int getData(TREE *root)
{
	assert(root != NULL);
	return root->data;
}
/*
 * Funtion:	getLeft
 *
 * Complexity: O(1)
 *
 * Description:	Returns the leftChild field of TREE
 *
 */
TREE *getLeft(TREE *root)
{
	assert(root != NULL);
	return root->leftChild;	
}
/*
 * Funtion:	getRight
 *
 * Complexity: O(1)
 *
 * Description:	Returns the rightChild fild of TREE
 *
 */
TREE *getRight(TREE *root)
{
	assert(root != NULL);
	return root->rightChild;
}
/*
 * Funtion:	getParent
 *
 * Complexity: O(1)
 *
 * Description:	Returns Parent field of TREE
 *
 */
TREE *getParent(TREE *root)
{
	assert(root != NULL);
	return root->parent;
}
/*
 * Funtion:	setLeft
 *
 * Complexity: O(1)
 *
 * Description:	Adds a left child to the root passed in
 *
 */
void setLeft(TREE *root, TREE *left)
{
	assert(root != NULL);
	root->leftChild = left;
}
/*
 * Funtion:	setRight
 *
 * Complexity: O(1)
 *
 * Description:	Adds a right child to the root passed in 
 *
 */
void setRight(TREE *root, TREE *right)
{
	assert(root != NULL);
	root->rightChild = right;
}