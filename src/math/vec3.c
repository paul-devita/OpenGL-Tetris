#include "vec3.h"

const vec3 AXIS_X_V3 = { {1.0f, 0, 0} };
const vec3 AXIS_Y_V3 = { {0, 1.0f, 0} };
const vec3 AXIS_Z_V3 = { {0, 0, 1.0f} };

vec3 v3_new(float x, float y, float z) {
	vec3 result;

	result.values[X_V3] = x;
	result.values[Y_V3] = y;
	result.values[Z_V3] = z;

	return result;
}

ubyte v3_equals(const vec3 v1, const vec3 v2) {
	if (v1.values[X_V3] != v2.values[X_V3])
		return 0;
	if (v1.values[Y_V3] != v2.values[Y_V3])
		return 0;
	if (v1.values[Z_V3] != v2.values[Z_V3])
		return 0;

	return 1;
}