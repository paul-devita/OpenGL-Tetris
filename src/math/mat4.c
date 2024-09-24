#include "mat4.h"

mat4 m4_multiply(mat4 multiplicand, mat4 multiplier) {
	mat4 product;

	for (ubyte r = 0; r < SIZE_M4; r++) {
		for (ubyte c = 0; c < SIZE_M4; c++) {
			float value = 0;

			for (ubyte i = 0; i < SIZE_M4; i++) 
				value += multiplicand.values[r][i] * multiplier.values[i][c];
			
			product.values[r][c] = value;
		}
	}
	
	return product;
}

mat4 m4_translate(mat4 matrix, const vec3 translation) {
	mat4 tMatrix = IDENTITY_M4;
	
	tMatrix.values[0][3] = translation.values[X_V3];
	tMatrix.values[1][3] = translation.values[Y_V3];
	tMatrix.values[2][3] = translation.values[Z_V3];

	return m4_multiply(matrix, tMatrix);
}

mat4 m4_rotate(mat4 m, double angle_rad, const vec3 axis) {
	mat4 result;

	if (v3_equals(axis, AXIS_X_V3)) {
		double angleCos = cos(angle_rad);
		double angleSin = sqrt(1 - angleCos * angleCos);


	}
	else if (v3_equals(axis, AXIS_Y_V3)) {
		double angleCos = cos(angle_rad);
		double angleSin = sqrt(1 - angleCos * angleCos);


	}
	else if (v3_equals(axis, AXIS_Z_V3)) {
		double angleCos = cos(angle_rad);
		double angleSin = sqrt(1 - angleCos * angleCos);


	}
}

mat4 m4_scale(mat4 m, int scale) {

}