#include <stdio.h>
#include <stdlib.h>
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
	TREE *left;
	TREE *right;
};


struct tree *createTree(int data, TREE *left, TREE *right){
	TREE *root;
	root = malloc(sizeof(TREE));
	assert(root != NULL);
	root->count = 0;
	root->right = malloc(sizeof(TREE));
	assert(root->right != NULL);
	root->left = malloc(sizeof(TREE));
	assert(root->left != NULL);
	dp->head->next = dp->head;
	dp->head->prev = dp->head;
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
void destroyTree(struct tree *root){

}
/*
 * Funtion:	
 *
 * Complexity:
 *
 * Description:	
 *
 */
int getData(struct tree *root){

}
/*
 * Funtion:	
 *
 * Complexity:
 *
 * Description:	
 *
 */
struct tree *getLeft(struct tree *root){

}
/*
 * Funtion:	
 *
 * Complexity:
 *
 * Description:	
 *
 */
struct tree *getRight(struct tree *root){

}
/*
 * Funtion:	
 *
 * Complexity:
 *
 * Description:	
 *
 */
struct tree *getParent(struct tree *root){

}
/*
 * Funtion:	
 *
 * Complexity:
 *
 * Description:	
 *
 */
void setLeft(struct tree *root, struct tree *left){

}
/*
 * Funtion:	
 *
 * Complexity:
 *
 * Description:	
 *
 */
void setRight(struct tree *root, struct tree *right){

}