#include "block.h"

void b_init() {
	B_BLOCK_TEXTURE = tx_genTexture(B_BLOCK_TEXTURE_PATH, TX_TRUE);

	B_BLOCK_SCALE.x = GRID_CELL_SIZE;
	B_BLOCK_SCALE.y = GRID_CELL_SIZE;
}

void b_drawBlock(vec2* position, unsigned char colorIndex) {
	vec3* color = c_getColorByIndex(colorIndex);
	static vec3 c = { 1.0f, 1.0f, 1.0f };

	qd_drawTexturedRect(B_BLOCK_TEXTURE, position, &B_BLOCK_SCALE, 0, color);
	//qd_drawSolidRect(*position, B_BLOCK_SCALE, 0, *color);
}