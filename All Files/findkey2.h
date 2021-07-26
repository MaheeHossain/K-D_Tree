#ifndef FINDKEY
#define FINDKEY

#include "linkedlist.h"
#include "readdata.h"
#include "kdtree.h"
#include "point.h"

#define PRINT_OUTPUT "Census year: %s || Block ID: %s || Property ID: %s || Base Property ID: %s || CLUE \
small area: %s || Industry (ANZSIC4) code: %s || Industry (ANZSIC4) \
description: %s || x coordinate: %s || y coordinate: %s || Location: %s ||\n"

void traverse_dictionary(char* argv[], list_t *datas, point_t key);


#endif