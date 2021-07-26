#ifndef POINT
#define POINT
#include <stdio.h>
#include <math.h>

#define SMALLER -1
#define EQUALS 0
#define BIGGER 1
#define NOT_EQUALS 1

#define NUM_DIMENS 2

/* point - A 2D coordinate on the map */

typedef struct point point_t;

struct point {
	double x, y;
};

int pointEquality(point_t a, point_t b, double margin);

int getDirection(double a, double b, double margin);

point_t str_to_point(char *string);

double pointDistance(point_t a, point_t b);

double square(double a);

#endif