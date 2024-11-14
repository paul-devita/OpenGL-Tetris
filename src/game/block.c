#include "block.h"

void b_init() {
	B_BLOCK_TEXTURE = tx_genTexture(B_BLOCK_TEXTURE_PATH, TX_TRUE);

	B_BLOCK_SCALE.x = GRID_CELL_SIZE;
	B_BLOCK_SCALE.y = GRID_CELL_SIZE;
}

void b_drawBlock(vec2* position, unsigned char colorIndex) {
	vec3* color = c_getColorByIndex(colorIndex);

	qd_drawTexturedRect(B_BLOCK_TEXTURE, position, &B_BLOCK_SCALE, 0, color);
}

void b_drawDummyBlock(vec2* position, vec2* scale, unsigned char colorIndex) {
	vec3* color = c_getColorByIndex(colorIndex);

	qd_drawTexturedRect(B_BLOCK_TEXTURE, position, scale, 0, color);
}
