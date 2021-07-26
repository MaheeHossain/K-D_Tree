/* =========================================================================
* findkey.c
*
* Created by Mahee Hossain 1080102 (mfhossain@student.unimelb.edu.au)
* 24/08/2020
*
* Takes user inputted key (company name), and searches the dictionary
* created in "readdata.c" for the information, and prints it to output
* file
*
* Edited on 14/09/2020
*
==========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include "readdata.h"
#include "linkedlist.h"
#include "kdtree.h"
#include "filltree.h"
#include "findkey.h"
#include "point.h"

void traverse_dictionary(char* argv[], list_t *datas, point_t key) {
	/* Goes through dictionary looking for key */
	/* Open files */
	FILE *output_file = fopen(argv[2], "w");
	
	/* Create a new node, check if it and initial list are not NULL */
	node_t *curr = (node_t*)malloc(sizeof(*curr));
	assert(datas!=NULL && curr!=NULL);
	
	/* Traverse the dictionary */
	data_t dA;
	point_t location;
	curr = datas->head;
	int resultsFound = 0;
	while(curr!=NULL) {
		dA = curr->data;
		location = find_location(curr); //filltree.h WORKS
		/* Check if the node has the right info, if so print output */
		if (pointEquality(location, key, MARGIN) == EQUALS){ //point.h
			resultsFound++;
			fprintf(output_file, "%lf %lf --> ", key.x, key.y);
			fprintf(output_file, PRINT_ALL_INFO, dA[0], dA[1], dA[2], dA[3], dA[4],
					dA[TR_NAME], dA[6], dA[7], dA[X_COORD], dA[Y_COORD], dA[LOC]);
		}
		
		curr = curr->next;
	}
	
	/* If no results were found, print so */
	if (resultsFound==0) {
		fprintf(output_file, "%lf %lf --> NOTFOUND\n", key.x, key.y);
	}
	
	/* Free curr node */
	free(curr);
	
	/* Close files */
	fclose(output_file);
}

void free_dict(list_t *datas) {
	/* Frees list properly */
	node_t *curr, *prev;
	assert(datas!=NULL);
	curr = datas->head;
	while (curr) {
		prev = curr;
		curr = curr->next;
		free_node(prev);
	}
	free(datas);
}

void free_node(node_t *curr) {
	/* Frees an individual node of the dictionary */
	assert(curr!=NULL && curr->data!=NULL);
	
	for(int i=0; i < FIELDS_NUM; i++) {
		free(curr->data[i]);
	}
	
	free(curr->data);
}