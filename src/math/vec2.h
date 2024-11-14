#ifndef _VEC2_H_
#define _VEC2_H_

typedef struct {
	float x;
	float y;
} vec2;

typedef struct {
	int x;
	int y;
} vec2i;

typedef struct {
	short x;
	short y;
} vec2s;

vec2 v2_new(float x, float y);

#endif