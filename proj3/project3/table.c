# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <assert.h>
# include "set.h"
# define EMPTY 0
# define FILLED 1
# define DELETED 2

static int findElement(SET *sp, char *elt, bool *found);

struct set {
	int count;     /* number of elements in array */
	int length;    /* length of allocated array   */
	char* *elts;   /* allocated array of elements */
	char *flags;   /* array containing information about state of element array */
};
/*
 * Function:    createSet
 *
 * Complexity:  O(1)
 *
 * Description: Return a pointer to a new set with a maximum capacity of
 *		maxElts.
 */
SET *createSet(int maxElts)
{
	SET *sp;
	int i;

	sp = malloc(sizeof(SET));
	assert(sp != NULL);

	sp->count = 0;
	sp->length = maxElts;

	sp->elts = malloc(sizeof(char*)*maxElts);
	assert(sp->elts != NULL);

	sp->flags = malloc(sizeof(char)*maxElts);
	assert(sp->flags != NULL);

	for(i=0; i < sp->length; i++)
		sp->flags[i] = EMPTY;
	return sp;
}
/*
 * Function:    destroySet
 *
 * Complexity:  O(n)
 *
 * Description: Deallocate memory associated with the set pointed to by SP.
 */
void destroySet(SET *sp)
{
    int i;

    assert(sp != NULL);

    for (i=0; i < sp->length; i++){
        if(sp->flags[i] == FILLED) 
        	free(sp->elts[i]);
    }
    free(sp->flags);
    free(sp->elts);
    free(sp);
}

/*
 * Finction:   Hashfunction
 *
 * Complexity:  O(n) where n is the string length.
 *
 * Description: Retuns the index the character string hashes to.
 * 		
 */
unsigned hashString(char *s) {
         unsigned hash = 0;
         while (*s != '\0')
             hash = 31 * hash + *s++;
         return hash;
}

/*
 * Function:    findElement (private)
 *
 * Complexity:  O(1) best case. O(n) worst case.
 *
 * Description: Recieve initial hash location from hashString. 
 *      Use linear probing to check the state of flags array at the location
 *      elt hashes to. If flags is EMPTY, The element has never been contained in the array.
 *      findElement returns *FOUND as false and location of the initial hash.
 *		If present, its location is returned and *FOUND is true.
 *		If not present, the location where it would be inserted is
 *		returned and *FOUND is false.
 */

static int findElement(SET *sp, char *elt, bool *found)
{
	int avail = -1;
	int i;
	int locn, init; 

	init = hashString(elt)%sp->length;

	for(i=0; i < sp->length; i++){
		locn = (init + i)%sp->length;
		if(sp->flags[locn] == EMPTY){
			*found = false;
			if(avail == -1)
				return locn;
		return avail;
		}
		else if(sp->flags[locn] == FILLED){
			if (strcmp(sp->elts[locn], elt) == 0){
			*found = true;
			return locn;
		    }
		}
		else if(sp->flags[locn] == DELETED){
			if(avail == -1){
				avail = locn;
			}
		}

	}
	*found = false;
	return locn;
}

/*
 * Function:    numElements
 *
 * Complexity:  O(1)
 *
 * Description: Return the number of elements in the set pointed to by SP.
 */

int numElements(SET *sp)
{
	assert(sp != NULL);
	return sp->count;
}

/*
 * Function:    hasElement
 *
 * Complexity:  O(1) best case. O(n) worst case.
 *
 * Description: Check if elt is present in the set by a call to findElement.
 */

bool hasElement(SET *sp, char *elt)
{
	bool found;
	findElement(sp, elt, &found);
	return found;
}
/*
 * Function:    addElement
 *
 * Complexity:  O(1) best case. O(n) worst case.
 *
 * Description: Add elt to the set pointed to by SP, and return whether the
 *		set changed. A new element is inserted in its proper hash position
 *      found via findElement. If the number of elements in the set is Max_Unique,
 *      the array is alreafy full and addElement does not make changes.
 *
 *      
 */
bool addElement(SET *sp, char *elt)
{	
	bool found;
	int locn = findElement(sp, elt, &found);

	if (sp->count == Max_Unique)
		return false;

	if (found)
		return false;

	if(!found){
		sp->elts[locn] = strdup(elt);
	}

	sp->flags[locn] = FILLED;
	sp->count++;
	return true;
}
/*
 * Function:    removeElement
 *
 * Complexity:  O(1) bast case. O(n) worst case
 *
 * Description: Remove elt from the set by the location given be findElement.
 * 		
 *		
 */
bool removeElement(SET *sp, char *elt)
{
	bool found;
	int locn;
    locn = findElement(sp, elt, &found);
    if(found == false){
        return false;
    }else{
        sp->flags[locn] = DELETED;
        free(sp->elts[locn]);
    }
    sp->count--;
    return true;
}