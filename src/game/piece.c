#include "piece.h"

void p_init() {

	if (!P_INITIALIZED) {
		//I
			P_I_PIECE.blocks = 0x00; // 0000 0000

			p_setPieceColor(&P_I_PIECE, COLOR_INDEX_BLUE);

			const unsigned char I_WIDTH = 4;
			const unsigned char I_HEIGHT = 1;

			p_setPieceWidth(&P_I_PIECE, I_WIDTH);
			p_setPieceHeight(&P_I_PIECE, I_HEIGHT);

			for (int i = 0; i < I_WIDTH; i++)
				p_setBlockAt(&P_I_PIECE, i, I_HEIGHT - 1);

		//J
			P_J_PIECE.blocks = 0x00; // 0000 0000

			p_setPieceColor(&P_J_PIECE, COLOR_INDEX_TEAL);

			const unsigned char J_WIDTH = 3;
			const unsigned char J_HEIGHT = 2;

			p_setPieceWidth(&P_J_PIECE, J_WIDTH);
			p_setPieceHeight(&P_J_PIECE, J_HEIGHT);

			p_setBlockAt(&P_J_PIECE, 0, 0);
			p_setBlockAt(&P_J_PIECE, 0, 1);
			p_setBlockAt(&P_J_PIECE, 1, 1);
			p_setBlockAt(&P_J_PIECE, 2, 1);

		//L
			P_L_PIECE.blocks = 0x00; // 0000 0000

			p_setPieceColor(&P_L_PIECE, COLOR_INDEX_ORANGE);

			const unsigned char L_WIDTH = 3;
			const unsigned char L_HEIGHT = 2;

			p_setPieceWidth(&P_L_PIECE, L_WIDTH);
			p_setPieceHeight(&P_L_PIECE, L_HEIGHT);

			p_setBlockAt(&P_L_PIECE, 0, 1);
			p_setBlockAt(&P_L_PIECE, 1, 1);
			p_setBlockAt(&P_L_PIECE, 2, 1);
			p_setBlockAt(&P_L_PIECE, 2, 0);

		//O
			P_O_PIECE.blocks = 0x00; // 0000 0000

			p_setPieceColor(&P_O_PIECE, COLOR_INDEX_YELLOW);

			const unsigned char O_SIZE = 2;

			p_setPieceWidth(&P_O_PIECE, O_SIZE);
			p_setPieceHeight(&P_O_PIECE, O_SIZE);

			p_setBlockAt(&P_O_PIECE, 0, 0);
			p_setBlockAt(&P_O_PIECE, 0, 1);
			p_setBlockAt(&P_O_PIECE, 1, 0);
			p_setBlockAt(&P_O_PIECE, 1, 1);

		//S
			P_S_PIECE.blocks = 0x00; // 0000 0000

			p_setPieceColor(&P_S_PIECE, COLOR_INDEX_RED);

			unsigned char S_WIDTH = 3;
			unsigned char S_HEIGHT = 2;

			p_setPieceWidth(&P_S_PIECE, S_WIDTH);
			p_setPieceHeight(&P_S_PIECE, S_HEIGHT);

			p_setBlockAt(&P_S_PIECE, 1, 0);
			p_setBlockAt(&P_S_PIECE, 2, 0);
			p_setBlockAt(&P_S_PIECE, 0, 1);
			p_setBlockAt(&P_S_PIECE, 1, 1);

		//T
			P_T_PIECE.blocks = 0x00; // 0000 0000

			p_setPieceColor(&P_T_PIECE, COLOR_INDEX_PURPLE);

			unsigned char T_WIDTH = 3;
			unsigned char T_HEIGHT = 2;

			p_setPieceWidth(&P_T_PIECE, T_WIDTH);
			p_setPieceHeight(&P_T_PIECE, T_HEIGHT);

			p_setBlockAt(&P_T_PIECE, 0, 0);
			p_setBlockAt(&P_T_PIECE, 1, 0);
			p_setBlockAt(&P_T_PIECE, 2, 0);
			p_setBlockAt(&P_T_PIECE, 1, 1);

		//Z
			P_Z_PIECE.blocks = 0x00; // 0000 0000

			p_setPieceColor(&P_Z_PIECE, COLOR_INDEX_GREEN);

			unsigned char Z_WIDTH = 3;
			unsigned char Z_HEIGHT = 2;

			p_setPieceWidth(&P_Z_PIECE, Z_WIDTH);
			p_setPieceHeight(&P_Z_PIECE, Z_HEIGHT);

			p_setBlockAt(&P_Z_PIECE, 0, 0);
			p_setBlockAt(&P_Z_PIECE, 1, 0);
			p_setBlockAt(&P_Z_PIECE, 1, 1);
			p_setBlockAt(&P_Z_PIECE, 2, 1);

			P_INITIALIZED = 1;
	}
}

void p_createPiece(Piece* piece, vec2s* gridPosition, unsigned char pieceType, unsigned char randomColor) {
	switch (pieceType) {
		case P_I_PIECE_INDEX: 
			*piece = P_I_PIECE;

			break;
		case P_J_PIECE_INDEX:
			*piece = P_J_PIECE;

			break;
		case P_L_PIECE_INDEX: 
			*piece = P_L_PIECE;

			break;
		case P_O_PIECE_INDEX: 
			*piece = P_O_PIECE;

			break;
		case P_S_PIECE_INDEX: 
			*piece = P_S_PIECE;

			break;
		case P_T_PIECE_INDEX: 
			*piece = P_T_PIECE;

			break;
		case P_Z_PIECE_INDEX: 
			*piece = P_Z_PIECE;

			break;
		default:
			printf("WARNING: invalid piece type passed to p_createPiece\n");
			return;
	}

	piece->position = *gridPosition;

	if (randomColor) {
		unsigned char randomColor = (unsigned char)r_randomIntInRange(0, 8);

		p_setPieceColor(piece, randomColor);
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

unsigned char p_getDefaultPieceColor(unsigned char pieceType) {
	switch (pieceType) {
	case P_I_PIECE_INDEX:
		return COLOR_INDEX_BLUE;
	case P_J_PIECE_INDEX:
		return COLOR_INDEX_TEAL;
	case P_L_PIECE_INDEX:
		return COLOR_INDEX_ORANGE;
	case P_O_PIECE_INDEX:
		return COLOR_INDEX_YELLOW;
	case P_S_PIECE_INDEX:
		return COLOR_INDEX_RED;
	case P_T_PIECE_INDEX:
		return COLOR_INDEX_PURPLE;
	case P_Z_PIECE_INDEX:
		return COLOR_INDEX_GREEN;
	default:
		printf("WARNING: invalid piece type passed to p_getDefaultPieceColor\n");
		return;
	}
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

				if (gridPos.y >= 2 * G_GRID_CELL_COUNT)
					continue;

				vec2 screenPos = gr_gridToScreen(&gridPos);

				b_drawBlock(&screenPos, colorIndex);
			}
		}
	}
}

void p_drawDummy(unsigned char pieceType, vec2* position, float blockSize, unsigned char colorIndex) {
	switch (pieceType) {
		case P_I_PIECE_INDEX: {
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
		case P_J_PIECE_INDEX: {
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
		case P_L_PIECE_INDEX: {
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
		case P_O_PIECE_INDEX: {
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
		case P_S_PIECE_INDEX: {
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
		case P_T_PIECE_INDEX: {
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
		case P_Z_PIECE_INDEX: {
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