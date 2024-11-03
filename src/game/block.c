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

void b_drawBlock(unsigned int gridPosX, unsigned int gridPosY, BlockData data) {
	ubyte type = b_getBlockType(data);

	if (type == B_NULL_BLOCK) return;

	vec2 p, s;

	ubyte color = b_getBlockColor(data);

	s.x = G_GRID_CELL_SIZE;
	s.y = G_GRID_CELL_SIZE;

	p.x = G_GRID_LOWER_LEFT.x + (gridPosX * G_GRID_CELL_SIZE) - (G_GRID_CELL_SIZE / (float)2);
	p.y = G_GRID_LOWER_LEFT.y - (gridPosY * G_GRID_CELL_SIZE) + (G_GRID_CELL_SIZE / (float)2);

	qd_drawTexturedRect(B_BLOCK_TEXTURE, &p, &s, 0, g_colors[color]);
}

void b_drawSingle(vec2* position, vec2* scale, vec3* color) {
	qd_drawTexturedRect(B_BLOCK_TEXTURE, position, scale, 0, color);
}