#include "vec3.h"

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