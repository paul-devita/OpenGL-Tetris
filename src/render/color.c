#include "color.h"

const vec3 COLOR_BLUE = { 0.000f, 0.827f, 1.000f };
const vec3 COLOR_YELLOW = { 1.000f, 0.984f, 0.000f };
const vec3 COLOR_RED = { 1.000f, 0.388f, 0.388f };
const vec3 COLOR_GREEN = { 0.388f, 1.000f, 0.510f };
const vec3 COLOR_ORANGE = { 0.988f, 0.647f, 0.000f };
const vec3 COLOR_PINK = { 1.000f, 0.682f, 0.957f };
const vec3 COLOR_PURPLE = { 0.659f, 0.157f, 1.000f };
const vec3 COLOR_TEAL = { 0.000f, 1.000f, 0.761f };
const vec3 COLOR_WHITE = { 1.0f, 1.0f, 1.0f };
const vec3 COLOR_GRAY = { 0.472f, 0.472f, 0.472f };

vec3* c_getColorByIndex(unsigned char index)
{
	switch (index) {
		case COLOR_INDEX_BLUE: 
			return &COLOR_BLUE;
		case COLOR_INDEX_YELLOW:
			return &COLOR_YELLOW;
		case COLOR_INDEX_RED:
			return &COLOR_RED;
		case COLOR_INDEX_GREEN:
			return &COLOR_GREEN;
		case COLOR_INDEX_ORANGE:
			return &COLOR_ORANGE;
		case COLOR_INDEX_PINK:
			return &COLOR_PINK;
		case COLOR_INDEX_PURPLE:
			return &COLOR_PURPLE;
		case COLOR_INDEX_TEAL:
			return &COLOR_TEAL;
		case COLOR_INDEX_WHITE:
			return &COLOR_WHITE;
		case COLOR_INDEX_GRAY:
			return &COLOR_GRAY;
		default:
			printf("WARNING: invalid color index passed to c_getColorByIndex\n");
			return NULL;
	}
}
