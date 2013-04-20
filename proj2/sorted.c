//
//  sorted.c.c
//  project2.c

//
//  Created by Nathan Garvey on 4/12/13.
//  Copyright (c) 2013 Nathan Garvey. All rights reserved.
//

# include <assert.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include "set.h"
/* Structure for the set used
 * Does not allocate memory O(1)
 */ 
struct set {
    int count;
    int length;
    char* *elts;
};
/*  function to creat initial SET structure
 *  O(1)
 */
SET *createSet(int maxElts)
{
    SET *sp; 
    sp = malloc(sizeof(SET));  
    assert(sp != NULL);   
    sp->count = 0;
    sp->length = maxElts;
    sp->elts = malloc(sizeof(char*)*maxElts);
    assert(sp->elts != NULL);
    return sp;
}
/*  Finds an element in the SET array via binary search
 *  O(logn)
 */
static int findElement(SET *sp, char *elt, bool *found)
{
    int lo, hi, mid;
    lo = 0;
    hi = sp->count -1;
    while (lo <= hi){
        mid = (lo + hi)/2;
        if (strcmp(sp->elts[mid], elt) > 0)
            hi = mid -1;
        else if (strcmp(sp->elts[mid], elt) < 0)
            lo = mid +1;
        else {
            *found = true;
            return mid;
        }
    }
    *found = false;
    return lo;
}
/*  Deallocates memeoy of the set
 *  O(n)
 */
void destroySet(SET *sp)
{
    int i;
    for (i=0; i < sp->count; i++){
        free(sp->elts[i]);
    }
    free(sp->elts);
    free(sp);
}
/*  returns the length of the array
 *  O(1) 
 */
int numElements(SET *sp)
{
    return sp->count;
}
/* calls findElement and returns bool if element
 * O(logn)
 */
bool hasElement(SET *sp, char *elt)
{
    bool found;
    findElement(sp, elt, &found);
    if (found == true)
        return true;
    return false;
}
/*  Determines where an element should be placed in the sorted array
 *  and shifts the rest of the array down O(nlogn)
 */
bool addElement(SET *sp, char *elt)
{
    assert(sp->count < Max_Unique)
   bool found;
    int i, j;
    i = findElement(sp, elt, &found);
    if (found == false){
        for (j=sp->count; j>i; j--){
            sp->elts[j] = sp->elts[j-1];
        }
        sp->elts[i] = strdup(elt);
        sp->count++;
        return true;
    }
    return false;

}
/* calls findElement to get index of element to remove.
 * frees the elt and shifts array O(nlogn)
 */
bool removeElement(SET *sp, char *elt)
{
    bool found;
    int i, j;
    i = findElement(sp, elt, &found);
    if (found == true){
        free(sp->elts[i]);
        for(j = i; j < sp->count -1; j++)
            sp->elts[j] = sp->elts[j+1];
        sp->count--;
        return true;
        }   
    return false;
}
