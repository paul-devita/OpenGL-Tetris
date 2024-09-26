#include "util.h"

const float pi = 3.14159265358979;

float* util_asArray2f(float f1, float f2) {
	static float arr[2];

	arr[0] = f1;
	arr[1] = f2;

	return arr;
}

float* util_asArray3f(float f1, float f2, float f3) {
	static float arr[3];

	arr[0] = f1;
	arr[1] = f2;
	arr[2] = f3;

	return arr;
}

float* util_asArray4f(float f1, float f2, float f3, float f4) {
	static float arr[4];

	arr[0] = f1;
	arr[1] = f2;
	arr[2] = f3;
	arr[3] = f4;

	return arr;
}

int* util_asArray2i(int i1, int i2) {
	static int arr[2];

	arr[0] = i1;
	arr[1] = i2;

	return arr;
}

int* util_asArray3i(int i1, int i2, int i3) {
	static int arr[3];

	arr[0] = i1;
	arr[1] = i2;
	arr[2] = i3;

	return arr;
}

int* util_asArray4i(int i1, int i2, int i3, int i4) {
	static int arr[4];

	arr[0] = i1;
	arr[1] = i2;
	arr[2] = i3;
	arr[3] = i4;

	return arr;
}