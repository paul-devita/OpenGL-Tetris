#ifndef _COLOR_H_
#define _COLOR_H_

#include <stdio.h>

#include "../math/vec3.h"

extern const vec3 COLOR_BLUE;
#define COLOR_INDEX_BLUE 0

extern const vec3 COLOR_YELLOW;
#define COLOR_INDEX_YELLOW 1

extern const vec3 COLOR_RED;
#define COLOR_INDEX_RED 2

extern const vec3 COLOR_GREEN;
#define COLOR_INDEX_GREEN 3

extern const vec3 COLOR_ORANGE;
#define COLOR_INDEX_ORANGE 4

extern const vec3 COLOR_PINK;
#define COLOR_INDEX_PINK 5

extern const vec3 COLOR_PURPLE;
#define COLOR_INDEX_PURPLE 6

extern const vec3 COLOR_TEAL;
#define COLOR_INDEX_TEAL 7

extern const vec3 COLOR_WHITE;
#define COLOR_INDEX_WHITE 8

extern const vec3 COLOR_GRAY;
#define COLOR_INDEX_GRAY 9

const vec3* c_getColorByIndex(unsigned char index);

#endif