#include "block.h"

void b_init() {
	B_BLOCK_TEXTURE = tx_genTexture(B_BLOCK_TEXTURE_PATH, TX_TRUE);
}

void b_drawSingle(vec2 position, vec2 scale, vec3 color) {
	qd_drawTexturedRect(B_BLOCK_TEXTURE, position, scale, 0, color);
}

