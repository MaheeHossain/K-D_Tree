#ifndef READTREE
#define READTREE

#include "linkedlist.h"
#include "kdtree.h"
#include "point.h"
#include "readdata.h"
#include "readtree.h"

#define MAX_DISTANCE 300

tdata_t search_tree(tree_t *tree, point_t key);

void check_node(tnode_t *node, point_t key, double *lowest, tdata_t *data);

#endif