//
//  unsorted.c
//  project2.c
//
//  Created by Nathan Garvey on 4/12/13.
//  Copyright (c) 2013 Nathan Garvey. All rights reserved.
//

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include "set.h"

struct set {
    int count;
    int lenght;
    char* *elts;
};

SET *createSet(int maxElts)
{
    SET *sp; //number of used slots
    sp = malloc(sizeof(SET));  //total number of slots
    assert(sp! = NULL);   //did malloc allocate memory?
    sp->count = 0;
    sp->lenght = maxElts;
    sp->elts = malloc(sizeof(char*)*maxElts);
    assert(sp->elts != NULL);
    return sp;
}

void destroySet(SET *sp) //Freeing the memory allocated in create set
{
    int i;
    for (i=0; i < sp->count; i++){
        free(sp->elts[i]);
    }
    free(sp->elts);
    free(sp);
}

int numElements(SET *sp) //eturns the number of elements in the array
{
    return sp->count;
}

bool hasElement(SET *sp, char *elt) 
{
   if (findElement(sp,elt)==-1)
            return false;
        return true;
}

bool addElement(SET *sp, char *elt)
{
    if (hasElement(sp , elt) == false)
        sp->elts[sp->count] = malloc(sizeof(char)*(strlen(elt) + 1));
    strcpy(sp->elts[sp->count] , elt);
}

bool removeElement(SET *sp, char *elt)
{
    if (hasElement != -1){
        free(sp->elts[hasElement]);
        return true;
    }

    return false;
}

static int findElement(SET *sp, char *elt)
{
    int i;
    for (i = 0; i < sp->count; i++){
        if(strcmp(sp->elts[i], elt) == 0)
        return (i);
        }
    return (-1);
}