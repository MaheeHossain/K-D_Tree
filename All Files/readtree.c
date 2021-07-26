/* =========================================================================
* readtree.c
*
* Created by Mahee Hossain 1080102 (mfhossain@student.unimelb.edu.au)
* 15/09/2020
*
* Searches through the tree for the closest point to the key
*
*
* Edited on 14/09/2020
*
==========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "kdtree.h"
#include "linkedlist.h"
#include "point.h"
#include "kdtree.h"
#include "readdata.h"
#include "filltree.h"
#include "readtree.h"

tdata_t search_tree(tree_t *tree, point_t key) {
	/* Searches through the tree for the node with the closest position to the
	*  key, and then returns the linked list attached to it                   */
	assert(tree!=NULL);
	double lowest=MAX_DISTANCE;
	/* Make a linked list (might not use it) */
	tdata_t *data = make_empty_list();
	
	/* RECURSION */
	check_node(tree->root, key, &lowest, data);
	
	return data; 
}

void check_node(tnode_t *node, point_t key, double *lowest, tdata_t *data) {
	/* Checks if the current node is closer than the current lowest, calls 
	*  recursively for its children nodes                                   */
	assert(node!=NULL);
	double dist=MAX_DISTANCE;
	
	/* Check current node */
	dist = pointDistance(key, node->location);
	if (dist < lowest) {
		lowest = dist;
		data = node->tdata; // Might have to do an equals function for linked list?
	}
	
	/* Call for children */
	if (node->left!=NULL) {
		check_node(node->left, key, lowest, data);
	}
	if (node->right!=NULL) {
		check_node(node->right, key, lowest, data);
	}
	
}