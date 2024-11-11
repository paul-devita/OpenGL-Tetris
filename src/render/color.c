#include "color.h"

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
