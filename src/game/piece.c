#include "piece.h"

unsigned char p_getBlockType(PieceData data) {
	unsigned char mask = 0x07; // 00000111

	unsigned char result = data & mask;

	return result;
}

unsigned char p_getBlockRotation(PieceData data) {
	unsigned char mask = 0x03; // 00000011

	unsigned char result = (data & mask) >> 3;

	return result;
}

unsigned char p_getBlockColor(PieceData data) {
	unsigned char mask = 0xE0; // 11100000

	unsigned char result = (data & mask) >> 5;

	return result;
}

void p_translate(Piece* piece, float dx, float dy) {
	for (int i = 0; i < P_BLOCK_COUNT; i++) {
		vec2* p = &piece->blocks[i];

		p->x += dx;
		p->y += dy;
	}
}

void p_draw(Piece* piece) {
	unsigned char colorIndex = p_getBlockColor(piece->data);

	vec3* color = c_getColorByIndex(colorIndex);

	for (int i = 0; i < P_BLOCK_COUNT; i++) {
		vec2* p = &piece->blocks[i];

		b_drawBlock(p, color);
	}
}