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
	int count;
	int length;
	char* *elts;
	char *flags;
};

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

void destroySet(SET *sp)
{
    int i;
    for (i=0; i < sp->length; i++){
        if(sp->flags[i] == FILLED) 
        	free(sp->elts[i]);
    }
    free(sp->flags);
    free(sp->elts);
    free(sp);
}

unsigned hashString(char *s) {
         unsigned hash = 0;
         while (*s != '\0')
             hash = 31 * hash + *s++;
         return hash;
}

static int findElement(SET *sp, char *elt, bool *found)
{
	int avail = -1;
	int i;
	int locn, init; 
	init = hashString(elt)%sp->length;
	for(i=0; i<sp->length; i++){
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
			if(avail == -1)
				avail = locn;
			}

		}
	*found = false;
	return locn;
}

int numElements(SET *sp)
{
	return sp->count;
}

bool hasElement(SET *sp, char *elt)
{
	bool found;
	findElement(sp, elt, &found);
	return found;
}

bool addElement(SET *sp, char *elt)
{
	if (sp->count == Max_Unique)
		return false;
	bool found;
	int locn = findElement(sp, elt, &found);
	if (found)
		return false;
	if(!found)
		sp->elts[locn] = strdup(elt);
	sp->flags[locn] = FILLED;
	sp->count++;
	return true;
}
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