#ifndef _VEC3_H_
#define _VEC3_H_

#include "../util/util.h"

#define SIZE_V3 3

typedef struct {
	float x;
	float y;
	float z;
} vec3;

extern const vec3 AXIS_X_V3;
extern const vec3 AXIS_Y_V3;
extern const vec3 AXIS_Z_V3;

/*
Creates and returns a vec3 values containing the values provided.
The created vec3 is not dynamically allocated.
*/
vec3 v3_new(float x, float y, float z);

/*
Returns 1 if the two vectors are equal (ie x1 = x2, y2 = y2, and z2 = z2) and 0 otherwise
*/
ubyte v3_equals(const vec3 v1, const vec3 v2);

/*
Returns the address of a statically allocated array containing the 3 elements of a vec3 struct.
*/
float* v3_asArray(const vec3* v);

#endif