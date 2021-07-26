#ifndef KDTREE
#define KDTREE

#include "linkedlist.h"
#include "point.h"

#define MARGIN 0.0005
#define TRUE 0
#define FALSE 1

/* treeNode - A node of a KD tree. Contains a linked list filled with 
*  identical data, a point with the location of this data, and two 
*  pointers to other nodes to the left and to the right            */

typedef list_t tdata_t;

typedef struct treeNode tnode_t;

struct treeNode {
	tdata_t *tdata;
	point_t location;
	tnode_t *left, *right;
};

/* tree - A KD tree. Contains the root of the tree */

typedef struct {
	tnode_t *root;
} tree_t;

tree_t *make_empty_tree(void);

int is_empty_tree(tree_t *tree);

tree_t *insert_node(tree_t *tree, data_t value, point_t point, int is_x);

void tree_move_helper(tree_t *tree, data_t value, point_t point,
					  double diff, int is_y);

tdata_t *get_root_data(tree_t *tree);

point_t get_root_location(tree_t *tree);

tdata_t *get_data(tnode_t *node);

point_t get_location(tnode_t *node);

int check_children(tnode_t *node);

void free_tree(tree_t *tree);

void free_tree_node(tnode_t *root);

#endif