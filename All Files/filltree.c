/* =========================================================================
* filltree.c
*
* Created by Mahee Hossain 1080102 (mfhossain@student.unimelb.edu.au)
* 14/09/2020
*
* Creates and defines functions needed to fill a K-D binary search
* tree from a linked list (from readdata.c)
*
==========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "kdtree.h"
#include "llist.h"
#include "point.h"
#include "kdtree.h"
#include "readdata.h"
#include "filltree.h"

void fill_tree(list_t *datas, tree_t *tree) {
	/* Fills a kd tree from a linked list */
	node_t *curr = (node_t*)malloc(sizeof(*curr));
	assert(datas!=NULL && curr!=NULL);
	point_t curr_point;
	
	/* Go through the linked list, and put every node inside the tree */
	curr = datas->head;
	while(curr!=NULL) {
		curr_point = find_location(curr);
		insert_node(tree->root, curr->data, curr_point, TRUE);
		curr = curr->next;
	}
	
	/* Free curr node */
	free(curr);
}

void print_tree(char* argv[], tree_t *tree) {
	/* Print a kd tree */
	
	/* Open output file */
	FILE *output_file = fopen(argv[2], "w");
	
	/* Traverse the tree, printing any node it comes across */
	print_tree_roots(tree->root, output_file);
	
	/* Close files */
	fclose(output_file);
}

void print_tree_roots(tnode_t *root, FILE *output) {
	/* Traverse the tree recursively, and then print data if not NULL */
	assert(root!=NULL && output!=NULL);
	
	if (root->left!=NULL) {
		print_tree_roots(root->left, output);
	}
	
	if (root->right!=NULL) {
		print_tree_roots(root->right, output);
	}
	
	if (root->location!=NULL) {
		print_data_linked_list_new(output, root->tdata);
	}
	
}

point_t find_location(node_t *curr) {
	/* Takes a node, and returns the location in a point form */
	assert(curr!=NULL && curr->data!=NULL);
	double *loc = (double *)malloc(COORD_NUM*sizeof(double));
	point_t point;
	
	/* Grabs the x and y coordinates from the data and returns as a point */
	//loc[X] = strtod(curr->data[X_COORD], NULL);
	loc[X] = atof(curr->data[X_COORD]);
	//loc[Y] = strtod(curr->data[Y_COORD], NULL);
	loc[Y] = atof(curr->data[Y_COORD]);
	point.x = loc[X];
	point.y = loc[Y];
	
	free(loc);
	
	return point;
}

void print_data_linked_list_new(FILE *output_file, list_t *datas) {
	/* Print the linked list filled with the data from the csv file into an
	*  already open file*/
	/* Open output file */
	
	/* Create a new node, check if it and initial list are not NULL */
	node_t *curr = (node_t*)malloc(sizeof(*curr));
	assert(datas!=NULL && curr!=NULL);
	
	/* Traverse the linked list with the node,
	   printing each node as it goes along */
	data_t dataArr;
	curr = datas->head;
	
	while (curr != NULL) {
		
		dataArr = curr->data;
		fprintf(output_file, PRINT_ALL_INFO, dataArr[0], dataArr[1], dataArr[2],
				dataArr[3], dataArr[4], dataArr[TR_NAME], dataArr[6], dataArr[7],
				dataArr[X_COORD], dataArr[Y_COORD], dataArr[LOC]);
		curr = curr->next;
	}
	
	/* Free node */
	free(curr);
}