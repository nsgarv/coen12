/*
 *  Function: tree.c
 *  
 *       Nathan Garvey. Project5
 */

#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include <assert.h>

typedef struct tree TREE;
/*
 * Funtion:	struct TREE
 *
 * Description:	the data structure for root/leaf/node.
 *				It contains pointers to the parent, 
 *				left and right children and a data value.
 */
struct tree {
	int data;
	struct tree *left;
	struct tree *right;
	struct tree *parent;
};

/*
 * Funtion:	CreateTree
 *
 * Complexity: O(1)
 *
 * Description:	Creates a root and allocates memory for a structure of type tree
 * 				and determines if it is the left or right child of its parent.
 */
struct tree *createTree(int data, struct tree *left, struct tree *right)
{
	TREE *root;
	
	root = malloc(sizeof(TREE));
	
	assert(root != NULL);
	
	root->left = left;
	root->right = right;
	root->data = data;
	root->parent = NULL;
	
	if (left != NULL){
		left->parent = root;
	}
	if (right != NULL){
		right->parent = root;
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
void destroyTree(struct tree *root)
{
	//If the root is already NULL you don't need to do anything
	if (root == NULL){
		return;
	}
	//If the left subtree != null then you need to traverse it 
	if (root->left != NULL) {
		destroyTree(root->left);
	}
	//If the right subtree != null then you need to traverse it
	if (root->right !=NULL) {
		destroyTree(root->right);
	}
	//When both the left and right subtrees equal null you can delete the subtree
	free(root);
}
//Get the data of the root given the root
int getData(struct tree *root)
{
	assert(root != NULL);
	return(root->data);
}
//Return the leftsubtree of the root
struct tree *getLeft(struct tree *root)
{
	assert(root != NULL);
	return (root->left);
}
//Return The right subtree of the root
struct tree *getRight(struct tree *root)
{
	assert(root != NULL);
	return (root->right);
}
//Assert the parent of the subtree
struct tree *getParent(struct tree *root)
{
	assert(root != NULL);
	return (root->parent);
	
}
//Set the left subtree of root equal to left
void setLeft(struct tree *root, struct tree *left)
{
	assert(root != NULL);
	root->left = left;
	if (left != NULL) {
		left->parent = root;
	}
	
}
//Set the right subtree of right equal to right
void setRight(struct tree *root, struct tree *right)
{
	assert(root != NULL);
	root->right = right;
	if (right != NULL) {
		right->parent = root;
	}
}

