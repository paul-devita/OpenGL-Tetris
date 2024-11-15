#include "piece.h"

void p_init() {
	//I

	//J

	//L

	//O

	//S

	//T

	//Z

}

void p_createPiece(Piece* piece, vec2s* gridPosition, unsigned char pieceType, unsigned char randomColor) {
	unsigned char width, height;

	piece->blocks = 0x00; // 00000000

	switch (pieceType) {
		case P_I_PIECE:
			if (randomColor) {
				//Set random color
			}
			else {
				p_setPieceColor(piece, COLOR_INDEX_BLUE);
			}

			piece->position = *gridPosition;

			width = 1;
			height = 4;

			p_setPieceWidth(piece, width);
			p_setPieceHeight(piece, height);

			for (int i = 0; i < height; i++)
				p_setBlockAt(piece, width - 1, i);

			break;
		case P_J_PIECE:
		
			break;
		case P_L_PIECE:

			break;
		case P_O_PIECE:

			break;
		case P_S_PIECE:

			break;
		case P_T_PIECE:

			break;
		case P_Z_PIECE:

			break;
		default:
			printf("WARNING: invalid piece type passed to p_createPiece\n");
			return;
	}
}

void p_setBlockAt(Piece* piece, unsigned char xBlockPos, unsigned char yBlockPos) {
	unsigned short mask = 0x0001; // 00000000 00000001

	unsigned char height = p_getPieceHeight(piece->data);

	mask <<= (yBlockPos * height) + xBlockPos;

	piece->blocks |= mask;
}

void p_setBlockAtFromShort(unsigned short* blocks, unsigned char xBlockPos, unsigned char yBlockPos, unsigned char height) {
	unsigned short mask = 0x0001; // 00000000 00000001

	mask <<= (yBlockPos * height) + xBlockPos;

	*blocks |= mask;
}

void p_unsetBlockAt(Piece* piece, unsigned char xBlockPos, unsigned char yBlockPos) {
	unsigned short mask = 0x0001; // 00000000 00000001

	unsigned char height = p_getPieceHeight(piece->data);

	mask <<= (yBlockPos * height) + xBlockPos;

	piece->blocks &= ~mask;
}

unsigned char p_getBlockAt(Piece* piece, unsigned char xBlockPos, unsigned char yBlockPos) {
	short mask = 0x0001; // 00000000 00000001

	unsigned char height = p_getPieceHeight(piece->data);

	mask <<= (yBlockPos * height) + xBlockPos;

	short result = mask & piece->blocks;

	result >>= (yBlockPos * height) + xBlockPos;

	return (unsigned char)result;
}

unsigned char p_getPieceColor(PieceData data) {
	unsigned char mask = 0x0F; // 00001111

	unsigned char result = data & mask;

	return result;
}

void p_setPieceColor(Piece* piece, unsigned char colorIndex) {
	unsigned char mask = 0xF0; // 11110000

	piece->data &= mask;

	colorIndex &= ~(mask);

	piece->data |= colorIndex;
}

unsigned char p_getPieceHeight(PieceData data) {
	unsigned char mask = 0xC0; // 11000000

	unsigned char result = (data & mask) >> 6;

	return result + 1;
}

void p_setPieceHeight(Piece* piece, unsigned char height) {
	height--;

	unsigned char mask = 0x3F; // 00111111

	piece->data &= mask;

	height <<= 6;

	piece->data |= height;
}

unsigned char p_getPieceWidth(PieceData data) {
	unsigned char mask = 0x30; // 00110000

	unsigned char result = (data & mask) >> 4;

	return result + 1;
}

void p_setPieceWidth(Piece* piece, unsigned char width) {
	width--;

	unsigned char mask = 0xCF; // 11001111

	piece->data &= mask;

	width <<= 4;

	width &= ~(mask);

	piece->data |= width;
}

void p_translate(Piece* piece, short dx, short dy) {
	piece->position.x += dx;
	piece->position.y += dy;
}

void p_rotate(Piece* piece) {
	unsigned short newBlocks = 0x0000; // 00000000 00000000

	unsigned char oldWidth = p_getPieceWidth(piece->data);
	unsigned char oldHeight = p_getPieceHeight(piece->data);

	unsigned char newWidth = oldHeight;
	unsigned char newHeight = oldWidth;

	for (int y = 0; y < oldHeight; y++) {
		for (int x = 0; x < oldWidth; x++) {
			if (p_getBlockAt(piece, x, y)) {
				unsigned char newX = y;
				unsigned char newY = (oldWidth - 1) - x;

				p_setBlockAtFromShort(&newBlocks, newX, newY, newHeight);
			}
		}
	}

	p_setPieceHeight(piece, newHeight);
	p_setPieceWidth(piece, newWidth);

	piece->blocks = newBlocks;

	short newXPos = piece->position.x + (oldWidth / 2) - (newWidth / 2);
	short newYPos = piece->position.y - (oldHeight / 2) + (newHeight / 2);

	piece->position.x = newXPos;
	piece->position.y = newYPos;
}

void p_draw(Piece* piece) {
	unsigned char width = p_getPieceWidth(piece->data);
	unsigned char height = p_getPieceHeight(piece->data);

	unsigned char colorIndex = p_getPieceColor(piece->data);

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			unsigned char block = p_getBlockAt(piece, x, y);

			if (block) {
				vec2s gridPos = piece->position;

				gridPos.x += x;
				gridPos.y -= y;

				vec2 screenPos = gr_gridToScreen(&gridPos);

				b_drawBlock(&screenPos, colorIndex);
			}
		}
	}
}