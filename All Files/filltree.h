#ifndef FILLTREE
#define FILLTREE

#include "linkedlist.h"
#include "kdtree.h"
#include "point.h"

#define TR_NAME 5
#define X_COORD 8
#define Y_COORD 9
#define LOC 10

#define X 0
#define Y 1
#define COORD_NUM 2

void fill_tree(list_t *datas, tree_t *tree);

void print_tree(char* argv[], tree_t *tree);

void print_tree_roots(tnode_t *root, FILE *output);

point_t find_location(node_t *curr);

void print_data_linked_list_new(FILE *output_file, list_t *datas);

#endif