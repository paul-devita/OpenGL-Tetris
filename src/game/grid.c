#include "grid.h"

const float GRID_CELL_SIZE = ((9 * SCR_WIDTH) / (float)20) / (float)G_GRID_CELL_COUNT;

void gr_init() {
	for (int x = 0; x < G_GRID_CELL_COUNT; x++)
		for (int y = 0; y < 2 * G_GRID_CELL_COUNT; y++)
			grid[x][y] = 0x00; // 00000000
	
	GRID_POSITION.x = SCR_WIDTH / (float)2;
	GRID_POSITION.y = SCR_HEIGHT / (float)2;

	GRID_SCALE.x = (9 * SCR_WIDTH) / (float)20;
	GRID_SCALE.y = 2 * GRID_SCALE.x;

	GRID_LOWER_LEFT.x = GRID_POSITION.x - (GRID_SCALE.x / (float)2);
	GRID_LOWER_LEFT.y = GRID_POSITION.y + (GRID_SCALE.x);

	GRID_OUTLINE_SCALE.x = GRID_SCALE.x + 2 * GRID_OUTLINE_THICKNESS;
	GRID_OUTLINE_SCALE.y = GRID_SCALE.y + 2 * GRID_OUTLINE_THICKNESS;
}

void gr_drawGridUI() {
	qd_drawOutlineRect(GRID_POSITION, GRID_OUTLINE_SCALE, GRID_OUTLINE_THICKNESS, COLOR_WHITE);
}

void gr_drawGridContents() {
	for (unsigned int x = 0; x < G_GRID_CELL_COUNT; x++) 
		for(unsigned int y = 0; y < 2 * G_GRID_CELL_COUNT; y++)
			if (grid[x][y] != GR_NULL_ELEMENT) {
				vec2 p = gr_gridToScreen(x, y);

				b_drawBlock(&p, grid[x][y]);
			}
}

vec2 gr_gridToScreen(unsigned int grX, unsigned int grY) {
	vec2 result;

	float sized2 = GRID_CELL_SIZE / (float)2;

	result.x = GRID_LOWER_LEFT.x + sized2 + grX * GRID_CELL_SIZE;
	result.y = GRID_LOWER_LEFT.y - sized2 - grY * GRID_CELL_SIZE;

	return result;
}