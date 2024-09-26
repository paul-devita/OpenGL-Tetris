#include "mat4.h"

const mat4 IDENTITY_M4 = { {{1.0f, 0, 0, 0}, {0, 1.0f, 0, 0}, {0, 0, 1.0f, 0}, {0, 0, 0, 1.0f}} };

mat4 m4_multiply(mat4* multiplicand, mat4* multiplier) {
	mat4 product;

	for (ubyte r = 0; r < SIZE_M4; r++) {
		for (ubyte c = 0; c < SIZE_M4; c++) {
			float value = 0;

			for (ubyte i = 0; i < SIZE_M4; i++) 
				value += multiplicand->values[r][i] * multiplier->values[i][c];
			
			product.values[r][c] = value;
		}
	}
	
	return product;
}

mat4 m4_translate(mat4* matrix, const vec3 translation) {
	mat4 tMatrix = IDENTITY_M4;
	
	tMatrix.values[0][3] = translation.x;
	tMatrix.values[1][3] = translation.y;
	tMatrix.values[2][3] = translation.z;

	return m4_multiply(matrix, &tMatrix);
}

mat4 m4_rotate(mat4* matrix, double angle_deg, const vec3 axis) {
	if (v3_equals(axis, AXIS_X_V3)) {
		mat4 rMatrix = IDENTITY_M4;

		float angleCos = (float) cos(angle_deg * pi / 180.0f);
		float angleSin = (float) sqrt(1 - angleCos * angleCos);

		rMatrix.values[1][1] = angleCos;
		rMatrix.values[1][2] = angleSin;
		rMatrix.values[2][1] = -angleSin;
		rMatrix.values[2][2] = angleCos;

		return m4_multiply(matrix, &rMatrix);
	}
	else if (v3_equals(axis, AXIS_Y_V3)) {
		mat4 rMatrix = IDENTITY_M4;

		float angleCos = (float) cos(angle_deg * pi / 180.0f);
		float angleSin = (float) sqrt(1 - angleCos * angleCos);

		rMatrix.values[0][0] = (float) angleCos;
		rMatrix.values[0][2] = (float) -angleSin;
		rMatrix.values[2][0] = (float) angleSin;
		rMatrix.values[2][2] = (float) angleCos;

		return m4_multiply(matrix, &rMatrix);
	}
	else if (v3_equals(axis, AXIS_Z_V3)) {
		mat4 rMatrix = IDENTITY_M4;

		float angleCos = (float) cos(angle_deg * pi / 180.0f);
		float angleSin = (float) sqrt(1 - angleCos * angleCos);

		rMatrix.values[0][0] = angleCos;
		rMatrix.values[0][1] = -angleSin;
		rMatrix.values[1][0] = angleSin;
		rMatrix.values[1][1] = angleCos;

		return m4_multiply(matrix, &rMatrix);
	}

	return *matrix;
}

mat4 m4_scale(mat4* matrix, const vec3 scale) {
	mat4 sMatrix = IDENTITY_M4;

	sMatrix.values[0][0] = scale.x;
	sMatrix.values[1][1] = scale.y;
	sMatrix.values[2][2] = scale.z;

	return m4_multiply(matrix, &sMatrix);
}

mat4 m4_ortho2D(unsigned int width, unsigned int height) {
	mat4 result = IDENTITY_M4;

	float scaleX = 2.0f / (float) width;
	float scaleY = 2.0f / (float) height;

	float normalizeTranslationX = -1;
	float normalizeTranslationY = -1;

	result.values[0][0] = scaleX;
	result.values[1][1] = scaleY;

	result.values[0][3] = normalizeTranslationX;
	result.values[1][3] = normalizeTranslationY;

	return result;
}