/*
    This defines implementations for linked-list-related functions.
*/

#include "data.h"
#include <stdlib.h>
#include <assert.h>

struct ll {
    struct key *key;
    struct data *data;
    struct ll *next;
};

/* Create a new empty linked list node. */
struct ll *newNode();

struct ll *newList(char *header){
    return NULL;
}

struct ll *newNode(){
    struct ll *returnNode = (struct ll *) malloc(sizeof(struct ll));
    assert(returnNode);
    returnNode->key = NULL;
    returnNode->data = NULL;
    returnNode->next = NULL;
    return returnNode;
}

struct ll *prependToList(struct ll *ll, struct dataMapping *mapping, char *row){
    struct ll *newHead = newNode();
    getData(row, mapping, &(newHead->key), &(newHead->data));
    newHead->next = ll;
    return newHead;
}

void searchLL(struct ll *ll, struct dataMapping *mapping, struct key *key, 
    struct data ***data){
    struct ll *current = ll;
    int foundMatches = 0;
    /* NULL terminated array. */
    *data = (struct data **) malloc(sizeof(struct data *));
    **data = NULL;
    while(current != NULL){
        while(current != NULL && compareKeys(current->key, key, mapping) != 0){
            current = current->next;
        }
        if(current && compareKeys(current->key, key, mapping) == 0){
            *data = realloc(*data, sizeof(struct data *) * (foundMatches + 2));
            assert(*data);
            (*data)[foundMatches] = current->data;
            (*data)[foundMatches + 1] = NULL;
            foundMatches++;
            /* We're done with this one, so move to next node. */
            current = current->next;
        }
    }
}

void freeLL(struct ll *ll, struct dataMapping *mapping){
    if(! ll){
        return;
    }
    struct ll *current = ll;
    struct ll *next;
    while(current){
        next = current->next;
        freeKeyPair(&(current->data), &(current->key), mapping);
        free(current);
        current = next;
    }
}
