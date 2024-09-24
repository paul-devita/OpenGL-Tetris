#ifndef _VEC3_H_
#define _VEC3_H_

#include "../util/typedef.h"

#define X_V3 0
#define Y_V3 1
#define Z_V3 2

typedef struct {
	float values[3];
} vec3;

const vec3 AXIS_X_V3 = { {1.0f, 0, 0} };
const vec3 AXIS_Y_V3 = { {0, 1.0f, 0} };
const vec3 AXIS_Z_V3 = { {0, 0, 1.0f} };

/*
Creates and returns a vec3 values containing the values provided.
The created vec3 is not dynamically allocated.
*/
vec3 v3_new(float x, float y, float z);

/*
Returns 1 if the two vectors are equal (ie x1 = x2, y2 = y2, and z2 = z2) and 0 otherwise
*/
ubyte v3_equals(const vec3 v1, const vec3 v2);

#endif