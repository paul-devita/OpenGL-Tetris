#include "block.h"

void b_init() {
	B_BLOCK_TEXTURE = tx_genTexture(B_BLOCK_TEXTURE_PATH, TX_TRUE);
}

void b_drawBlockFromPos(vec2* position, vec3* color) {
	qd_drawTexturedRect(B_BLOCK_TEXTURE, position, &B_BLOCK_SCALE, 0, color);
}

void b_drawBlockFromGrid(unsigned int gridPosX, unsigned int gridPosY, unsigned char colorIndex) {
	vec2 p, s;

	vec3* color = c_getColorByIndex(colorIndex);

	s.x = GRID_CELL_SIZE;
	s.y = GRID_CELL_SIZE;

	p.x = GRID_LOWER_LEFT.x + (gridPosX * GRID_CELL_SIZE) - (GRID_CELL_SIZE / (float)2);
	p.y = GRID_LOWER_LEFT.y - (gridPosY * GRID_CELL_SIZE) + (GRID_CELL_SIZE / (float)2);

	qd_drawTexturedRect(B_BLOCK_TEXTURE, &p, &s, 0, color);
}