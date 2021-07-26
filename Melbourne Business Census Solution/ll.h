/*
    This defines prototypes for linked-list-related functions.
*/

#include "data.h"

struct ll;

/* 
    Creates an empty linked list.
*/
struct ll *newList();

/*
    Prepend the item in the line to the given linked list.
*/
struct ll *prependToList(struct ll *ll, struct dataMapping *mapping, char *row);

/*
    Search for the key in the given list and put the data in the given location.
*/
void searchLL(struct ll *ll, struct dataMapping *mapping, struct key *key, 
    struct data ***data);

/*
    Frees all the memory in the given linked list.
*/
void freeLL(struct ll *ll, struct dataMapping *mapping);
