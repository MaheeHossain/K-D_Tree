/* =========================================================================
* kdtree.c
*
* Created by Mahee Hossain 1080102 (mfhossain@student.unimelb.edu.au)
* 11/09/2020
*
* Creates and defines functions needed to help implement and use a K-D 
* binary search tree
*
==========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "kdtree.h"
#include "linkedlist.h"
#include "point.h"

tree_t *make_empty_tree(void) {
	// Create tree, check that malloc worked
	tree_t *tree;
	tree = (tree_t*)malloc(sizeof(*tree));
	assert(tree!=NULL);
	// Set the root node to NULL and height to 0
	tree->root = NULL;
	return tree;
}

int is_empty_tree(tree_t *tree) {
	/* Checks if tree has any nodes in it or not */
	assert(tree!=NULL);
	return tree->root==NULL;
}

tree_t *insert_node(tree_t *tree, data_t value, point_t point, int is_x) {
	/* Inserts node into the correct point of the tree */
	
	/* Inserts at root if tree has no data yet */
	if (tree->root->tdata == NULL) {
		list_t *datas = make_empty_list();
		insert_at_foot(datas, value);
		tree->root->tdata = datas; 
		tree->root->location = point;
		return tree;
	}
	
	/* Checks if the point is equal to the current point,
	* if so add to back of linked list                 */
	double x_diff = getDirection(point.x, tree->root->location.x, MARGIN);
	double y_diff = getDirection(point.y, tree->root->location.y, MARGIN);
	
	if (pointEquality(point, tree->root->location, MARGIN) == EQUALS) {
		insert_at_foot(get_root_data(tree), value);
	}
	/* Checks if point is bigger or smaller than the current point */
	else if (is_x == TRUE) {
		tree_move_helper(tree, value, point, x_diff, FALSE);
	}
	else {
		tree_move_helper(tree, value, point, y_diff, TRUE);
	}
	return tree;
}

void tree_move_helper(tree_t *tree, data_t value, point_t point,
					  double diff, int is_y) {
	/* Moves around the tree whether or not we're comparing x or y */
	
	/* If the current data point is smaller, go left */
	if (diff == SMALLER) {
		insert_node(tree->root->left, value, point, is_y);
	}
	/* If the current data point is smaller, go right */
	else if (diff == BIGGER) {
		insert_node(tree->root->right, value, point, is_y);
	}
}

tdata_t *get_root_data(tree_t *tree) {
	/* Returns the linked list attached to the root of the tree */
	assert(tree!=NULL && tree->root!=NULL);
	return tree->root->tdata;
}

point_t get_root_location(tree_t *tree) {
	/* Returns the point attached to the root of the tree */
	assert(tree!=NULL && tree->root!=NULL);
	return tree->root->location;
}

tdata_t *get_data(tnode_t *node) {
	/* Returns the linked list attached to the node */
	assert(node!=NULL);
	return node->tdata;
}

point_t get_location(tnode_t *node) {
	/* Returns the point attached to the node */
	assert(node!=NULL);
	return node->location;
}

int check_children(tnode_t *node) {
	/* Checks whether or not the node has any children */
	assert(node!=NULL);
	if ((node->left==NULL) && (node->right==NULL)) {
		return FALSE;
	}
	return TRUE;
} 

void free_tree(tree_t *tree) {
	/* Checks if tree exists */
	assert(tree!=NULL);
	
	/* Free the root node, and recursively free all its children nodes */
	free_tree_node(tree->root);
	
	free(tree);
}

void free_tree_node(tnode_t *root) {
	/* If node is null, return */
	if (root->tdata == NULL) {
		return;
	}
	
	/* Else free call for left and right, then free the node */
	free_tree_node(root->left); 
	free_tree_node(root->right);
	
	free(root);
}