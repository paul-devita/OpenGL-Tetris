#include "block.h"

void b_init() {
	B_BLOCK_TEXTURE = tx_genTexture(B_BLOCK_TEXTURE_PATH, TX_TRUE);
}

unsigned char b_getBlockType(BlockData data) {
	unsigned char mask = 0x07;

	unsigned char result = data & mask;

	return result;
}

unsigned char b_getBlockRotation(BlockData data) {
	unsigned char mask = 0x03 << 3;

	unsigned char result = data & mask;

	result = result >> 3;

	return result;
}

unsigned char b_getBlockColor(BlockData data) {
	unsigned char mask = 0x07 << 5;

	unsigned char result = data & mask;

	result = result >> 5;

	return result;
}

void b_drawSingle(vec2 position, vec2 scale, vec3 color) {
	qd_drawTexturedRect(B_BLOCK_TEXTURE, position, scale, 0, color);
}

