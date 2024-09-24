#ifndef _MAT4_H_
#define _MAT4_H_

#include "../util/typedef.h"

#include "vec3.h"

#define SIZE_M4 4

typedef struct {
	float values[4][4];
} mat4;

const mat4 IDENTITY_M4 = { {{1.0f, 0, 0, 0}, {0, 1.0f, 0, 0}, {0, 0, 1.0f, 0}, {0, 0, 0, 1.0f}} };

/*
Multiplies the first matrix by the second and returns their product
*/
mat4 m4_multiply(mat4 multiplicand, mat4 multiplier);

/*
Provides the given matrix transformation translative properties according to the provided vec3 value.
Returns the result.
*/
mat4 m4_translate(mat4 matrix, const vec3 translation);

/*
Provides the given matrix transformation rotational properties according to the provided vec3 value and axis.
Returns the result.
*/
mat4 m4_rotate(mat4 matrix, double angle_rad, const vec3 axis);

/*
Provides the given matrix transformational scalar properties according to the provided integer value.
Returns the result.
*/
mat4 m4_scale(mat4 matrix, int scale);

#endif