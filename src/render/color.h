#ifndef _COLOR_H_
#define _COLOR_H_

#include <stdio.h>

#include "../math/vec3.h"

static const vec3 COLOR_BLUE = { 0.000f, 0.827f, 1.000f };
#define COLOR_INDEX_BLUE 0

static const vec3 COLOR_YELLOW = { 1.000f, 0.984f, 0.000f };
#define COLOR_INDEX_YELLOW 1

static const vec3 COLOR_RED = { 1.000f, 0.388f, 0.388f };
#define COLOR_INDEX_RED 2

static const vec3 COLOR_GREEN = { 0.388f, 1.000f, 0.510f };
#define COLOR_INDEX_GREEN 3

static const vec3 COLOR_ORANGE = { 0.988f, 0.647f, 0.000f };
#define COLOR_INDEX_ORANGE 4

static const vec3 COLOR_PINK = { 1.000f, 0.682f, 0.957f };
#define COLOR_INDEX_PINK 5

static const vec3 COLOR_PURPLE = { 0.659f, 0.157f, 1.000f };
#define COLOR_INDEX_PURPLE 6

static const vec3 COLOR_TEAL = { 0.000f, 1.000f, 0.761f };
#define COLOR_INDEX_TEAL 7

static const vec3 COLOR_WHITE = { 1.0f, 1.0f, 1.0f };
#define COLOR_INDEX_WHITE 8

static const vec3 COLOR_GRAY = { 0.472f, 0.472f, 0.472f };
#define COLOR_INDEX_GRAY 9

vec3* c_getColorByIndex(unsigned char index);

#endif