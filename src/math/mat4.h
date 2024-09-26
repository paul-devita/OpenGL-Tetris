#ifndef _MAT4_H_
#define _MAT4_H_

#include <math.h>

#include "../util/util.h"

#include "vec3.h"

#define SIZE_M4 4

typedef struct {
	float values[4][4];
} mat4;

extern const mat4 IDENTITY_M4;

/*
Multiplies the first matrix by the second and returns their product
*/
mat4 m4_multiply(mat4* multiplicand, mat4* multiplier);

/*
Provides the given matrix transformation translative properties according to the provided vec3 value.
Returns the result.
*/
mat4 m4_translate(mat4* matrix, const vec3 translation);

/*
Provides the given matrix transformation rotational properties according to the provided vec3 value and axis.
Returns the result.
*/
mat4 m4_rotate(mat4* matrix, double angle_rad, const vec3 axis);

/*
Provides the given matrix transformational scalar properties according to the provided integer value.
Returns the result.
*/
mat4 m4_scale(mat4* matrix, const vec3 scale);

/*
Returns an orhographic matrix that covers coordinates ranginging from [0, width] and [0, height] to normalized screen coordinates ranging from [-1, 1]
*/
mat4 m4_ortho2D(unsigned int width, unsigned int height);

#endif