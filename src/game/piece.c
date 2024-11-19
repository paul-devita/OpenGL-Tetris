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
	piece->blocks = 0x00; // 00000000

	piece->position = *gridPosition;

	switch (pieceType) {
		case P_I_PIECE: {
			if (randomColor) {
				unsigned char randomColor = (unsigned char)r_randomIntInRange(0, 8);

				p_setPieceColor(piece, randomColor);
			}
			else {
				p_setPieceColor(piece, COLOR_INDEX_BLUE);
			}

			unsigned char width = 4;
			unsigned char height = 1;

			p_setPieceWidth(piece, width);
			p_setPieceHeight(piece, height);

			for (int i = 0; i < width; i++)
				p_setBlockAt(piece, i, height - 1);

			break;
		}
		case P_J_PIECE: {
			if (randomColor) {
				unsigned char randomColor = (unsigned char)r_randomIntInRange(0, 8);

				p_setPieceColor(piece, randomColor);
			}
			else {
				p_setPieceColor(piece, COLOR_INDEX_TEAL);
			}

			unsigned char width = 2;
			unsigned char height = 3;

			p_setPieceWidth(piece, width);
			p_setPieceHeight(piece, height);

			p_setBlockAt(piece, 1, 0);
			p_setBlockAt(piece, 1, 1);
			p_setBlockAt(piece, 1, 2);
			p_setBlockAt(piece, 0, 2);

			break;
		}
		case P_L_PIECE: {
			if (randomColor) {
				unsigned char randomColor = (unsigned char)r_randomIntInRange(0, 8);

				p_setPieceColor(piece, randomColor);
			}
			else {
				p_setPieceColor(piece, COLOR_INDEX_ORANGE);
			}

			unsigned char width = 2;
			unsigned char height = 3;

			p_setPieceWidth(piece, width);
			p_setPieceHeight(piece, height);

			p_setBlockAt(piece, 0, 0);
			p_setBlockAt(piece, 0, 1);
			p_setBlockAt(piece, 0, 2);
			p_setBlockAt(piece, 1, 2);

			break;
		}
		case P_O_PIECE: {
			if (randomColor) {
				unsigned char randomColor = (unsigned char)r_randomIntInRange(0, 8);

				p_setPieceColor(piece, randomColor);
			}
			else {
				p_setPieceColor(piece, COLOR_INDEX_YELLOW);
			}

			unsigned char size = 2;

			p_setPieceWidth(piece, size);
			p_setPieceHeight(piece, size);

			p_setBlockAt(piece, 0, 0);
			p_setBlockAt(piece, 0, 1);
			p_setBlockAt(piece, 1, 0);
			p_setBlockAt(piece, 1, 1);

			break;
		}
		case P_S_PIECE: {
			if (randomColor) {
				unsigned char randomColor = (unsigned char)r_randomIntInRange(0, 8);

				p_setPieceColor(piece, randomColor);
			}
			else {
				p_setPieceColor(piece, COLOR_INDEX_RED);
			}

			unsigned char width = 3;
			unsigned char height = 2;

			p_setPieceWidth(piece, width);
			p_setPieceHeight(piece, height);

			p_setBlockAt(piece, 1, 0);
			p_setBlockAt(piece, 2, 0);
			p_setBlockAt(piece, 0, 1);
			p_setBlockAt(piece, 1, 1);

			break;
		}
		case P_T_PIECE: {
			if (randomColor) {
				unsigned char randomColor = (unsigned char)r_randomIntInRange(0, 8);

				p_setPieceColor(piece, randomColor);
			}
			else {
				p_setPieceColor(piece, COLOR_INDEX_PURPLE);
			}

			unsigned char width = 3;
			unsigned char height = 2;

			p_setPieceWidth(piece, width);
			p_setPieceHeight(piece, height);

			p_setBlockAt(piece, 0, 0);
			p_setBlockAt(piece, 1, 0);
			p_setBlockAt(piece, 2, 0);
			p_setBlockAt(piece, 1, 1);

			break;
		}
		case P_Z_PIECE: {
			if (randomColor) {
				unsigned char randomColor = (unsigned char)r_randomIntInRange(0, 8);

				p_setPieceColor(piece, randomColor);
			}
			else {
				p_setPieceColor(piece, COLOR_INDEX_GREEN);
			}

			unsigned char width = 3;
			unsigned char height = 2;

			p_setPieceWidth(piece, width);
			p_setPieceHeight(piece, height);

			p_setBlockAt(piece, 0, 0);
			p_setBlockAt(piece, 1, 0);
			p_setBlockAt(piece, 1, 1);
			p_setBlockAt(piece, 2, 1);

			break;
		}
		default:
			printf("WARNING: invalid piece type passed to p_createPiece\n");
			return;
	}
}

void p_setBlockAt(Piece* piece, unsigned char xBlockPos, unsigned char yBlockPos) {
	unsigned short mask = 0x0001; // 00000000 00000001

	unsigned char height = p_getPieceHeight(piece->data);
	unsigned char width = p_getPieceWidth(piece->data);

	if (height >= width) {
		mask <<= (xBlockPos * height) + yBlockPos;
	}
	else {
		mask <<= (yBlockPos * width) + xBlockPos;
	}

	piece->blocks |= mask;
}

void p_setBlockAtFromByte(unsigned char* blocks, unsigned char xBlockPos, unsigned char yBlockPos, unsigned char width, unsigned char height) {
	unsigned short mask = 0x0001; // 00000000 00000001

	if (height >= width) {
		mask <<= (xBlockPos * height) + yBlockPos;
	}
	else {
		mask <<= (yBlockPos * width) + xBlockPos;
	}

	*blocks |= mask;
}

void p_unsetBlockAt(Piece* piece, unsigned char xBlockPos, unsigned char yBlockPos) {
	unsigned short mask = 0x0001; // 00000000 00000001

	unsigned char height = p_getPieceHeight(piece->data);
	unsigned char width = p_getPieceWidth(piece->data);

	if (height >= width) {
		mask <<= (xBlockPos * height) + yBlockPos;
	}
	else {
		mask <<= (yBlockPos * width) + xBlockPos;
	}

	piece->blocks &= ~mask;
}

unsigned char p_getBlockAt(Piece* piece, unsigned char xBlockPos, unsigned char yBlockPos) {
	unsigned char mask = 0x01; // 00000000 00000001
	unsigned char result;

	unsigned char height = p_getPieceHeight(piece->data);
	unsigned char width = p_getPieceWidth(piece->data);

	if (height >= width) {
		mask <<= (xBlockPos * height) + yBlockPos;

		result = mask & piece->blocks;

		result >>= (xBlockPos * height) + yBlockPos;
	}
	else {
		mask <<= (yBlockPos * width) + xBlockPos;

		result = mask & piece->blocks;

		result >>= (yBlockPos * width) + xBlockPos;
	}

	return result;
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

				p_setBlockAtFromByte(&newBlocks, newX, newY, newWidth, newHeight);
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

void p_drawDummy(unsigned char pieceType, vec2* position, float blockSize, unsigned char colorIndex) {
	switch (pieceType) {
		case P_I_PIECE: {
			const unsigned char WIDTH = 4;

			unsigned char iterations = WIDTH / 2;

			vec2 p;

			p.y = position->y;

			float dx = blockSize / (float)2;

			for (int i = 0; i < iterations; i++) {
				p.x = position->x + dx;

				b_drawDummyBlock(&p, blockSize, colorIndex);

				p.x = position->x - dx;

				b_drawDummyBlock(&p, blockSize, colorIndex);

				dx += blockSize;
			}

			break;
		}
		case P_J_PIECE: {
			vec2 p;

			//0, 0
			p.x = position->x - blockSize;
			p.y = position->y - (blockSize / (float)2);

			b_drawDummyBlock(&p, blockSize, colorIndex);

			//0, 1
			p.y += blockSize;

			b_drawDummyBlock(&p, blockSize, colorIndex);

			//1, 1
			p.x += blockSize;

			b_drawDummyBlock(&p, blockSize, colorIndex);

			//2, 1
			p.x += blockSize;

			b_drawDummyBlock(&p, blockSize, colorIndex);

			break;
		}
		case P_L_PIECE: {
			vec2 p;

			//0, 1
			p.x = position->x - blockSize;
			p.y = position->y + (blockSize / (float)2);

			b_drawDummyBlock(&p, blockSize, colorIndex);

			//1, 1
			p.x += blockSize;

			b_drawDummyBlock(&p, blockSize, colorIndex);

			//2, 1
			p.x += blockSize;

			b_drawDummyBlock(&p, blockSize, colorIndex);

			//2, 0
			p.y -= blockSize;

			b_drawDummyBlock(&p, blockSize, colorIndex);

			break;
		}
		case P_O_PIECE: {
			vec2 p;

			//0, 0
			p.x = position->x - (blockSize / (float)2);
			p.y = position->y - (blockSize / (float)2);

			b_drawDummyBlock(&p, blockSize, colorIndex);

			//1, 0
			p.x += blockSize;

			b_drawDummyBlock(&p, blockSize, colorIndex);

			//1, 1
			p.y += blockSize;

			b_drawDummyBlock(&p, blockSize, colorIndex);

			//0, 1
			p.x -= blockSize;

			b_drawDummyBlock(&p, blockSize, colorIndex);

			break;
		}
		case P_S_PIECE: {
			vec2 p;

			//0, 1
			p.x = position->x - blockSize;
			p.y = position->y + (blockSize / (float)2);

			b_drawDummyBlock(&p, blockSize, colorIndex);

			//1, 1
			p.x += blockSize;

			b_drawDummyBlock(&p, blockSize, colorIndex);

			//1, 0
			p.y -= blockSize;

			b_drawDummyBlock(&p, blockSize, colorIndex);

			//2, 0
			p.x += blockSize;

			b_drawDummyBlock(&p, blockSize, colorIndex);

			break;
		}
		case P_T_PIECE: {
			vec2 p;

			//0, 0
			p.x = position->x - blockSize;
			p.y = position->y - (blockSize / (float)2);

			b_drawDummyBlock(&p, blockSize, colorIndex);
			
			//1, 0
			p.x += blockSize;

			b_drawDummyBlock(&p, blockSize, colorIndex);

			//2, 0
			p.x += blockSize;

			b_drawDummyBlock(&p, blockSize, colorIndex);

			//1, 1
			p.x -= blockSize;
			p.y += blockSize;

			b_drawDummyBlock(&p, blockSize, colorIndex);

			break;
		}
		case P_Z_PIECE: {
			vec2 p;

			//0, 0
			p.x = position->x - blockSize;
			p.y = position->y - (blockSize / (float)2);

			b_drawDummyBlock(&p, blockSize, colorIndex);

			//1, 0
			p.x += blockSize;

			b_drawDummyBlock(&p, blockSize, colorIndex);

			//1, 1
			p.y += blockSize;

			b_drawDummyBlock(&p, blockSize, colorIndex);

			//2, 1
			p.x += blockSize;

			b_drawDummyBlock(&p, blockSize, colorIndex);

			break;
		}
		default:
			printf("WARNING: invalid piece type passed to p_drawDummy\n");
			return;
	}
}