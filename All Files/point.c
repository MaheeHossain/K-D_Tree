/* =========================================================================
* point.c
*
* Created by Mahee Hossain 1080102 (mfhossain@student.unimelb.edu.au)
* 14/09/2020
*
* Creates a point (2D coordinate from two doubles). Includes extra 
* functions for checking equality. 
*
==========================================================================*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"

int pointEquality(point_t a, point_t b, double margin) {
	/* Checks if two points are within a margin in difference */
	if ((getDirection(a.x, b.x, margin) == EQUALS) &&
		(getDirection(a.y, b.y, margin)) == EQUALS) {
		return EQUALS;
	}
	return NOT_EQUALS;
}

int getDirection(double a, double b, double margin) {
	/* Checks if two doubles are within a margin in difference */
	double diff;
	diff = a-b;
	if ((diff < margin) && (-diff < margin)) {
		return EQUALS;
	}
	else if (diff > 0) {
		return BIGGER;
	}
	else {
		return SMALLER;
	}
}

double pointDistance(point_t a, point_t b) {
	/* Returns the distance between two points */
	return sqrt(square(a.x-b.x) + square(a.y-b.y));
}

double square(double a) {
	/* Returns the square of a double */
	return a*a;
}

point_t str_to_point(char *string) {
	/* Takes a string with two doubles and turns it into a point */
	/* WORKS! */
	double x_loc, y_loc;
	point_t point;
	
	/* Create two smaller chars to store the two doubles (can use array instead) */
	char *line1 = strtok(string, " ");
	char *line2 = strtok(NULL, " ");
	
	x_loc = atof(line2);
	//loc[Y] = strtod(curr->data[Y_COORD], NULL);
	y_loc = atof(line1);
	point.x = x_loc;
	point.y = y_loc;
	
	/* Free the lines used */
	
	
	return point;
}

/*point_t find_location(node_t *curr) {
	/ * Takes a node, and returns the location in a point form * /
	assert(curr!=NULL && curr->data!=NULL);
	double *loc = (double *)malloc(COORD_NUM*sizeof(double));
	point_t point;
	
	/ * Grabs the x and y coordinates from the data and returns as a point * /
	//loc[X] = strtod(curr->data[X_COORD], NULL);
	loc[X] = atof(curr->data[X_COORD]);
	//loc[Y] = strtod(curr->data[Y_COORD], NULL);
	loc[Y] = atof(curr->data[Y_COORD]);
	point.x = loc[X];
	point.y = loc[Y];
	
	free(loc);
	
	return point;
}*/