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

	piece->position = *gridPosition;

	switch (pieceType) {
		case P_I_PIECE:
			if (randomColor) {
				//Set random color
			}
			else {
				p_setPieceColor(piece, COLOR_INDEX_BLUE);
			}

			width = 4;
			height = 1;

			p_setPieceWidth(piece, width);
			p_setPieceHeight(piece, height);

			for (int i = 0; i < width; i++)
				p_setBlockAt(piece, i, height - 1);

			//h >= w
			//w = 1, h = 4
			//i = x * h + y

			//Bit 0 - (0, 0) - 0 * h + 0
			//Bit 1 - (0, 1) - 0 * h + 1
			//Bit 2 - (0, 2) - 0 * h + 2
			//Bit 3 - (0, 3) - 0 * h + 3

			//else
			//w = 4, h = 1
			//i = y * h + x
			
			//Bit 0 - (0, 0) - 0 + 0 * 1
			//Bit 1 - (1, 0) - 1 + 0 * 1
			//Bit 2 - (2, 0) - 2 + 0 * 1
			//Bit 3 - (3, 0) - 3 + 0 * 1
		

			break;
		case P_J_PIECE:
			if (randomColor) {
				//Set random color
			}
			else {
				p_setPieceColor(piece, COLOR_INDEX_TEAL);
			}

			width = 2;
			height = 3;

			p_setPieceWidth(piece, width);
			p_setPieceHeight(piece, height);

			p_setBlockAt(piece, 1, 0); 
			p_setBlockAt(piece, 1, 1); 
			p_setBlockAt(piece, 1, 2); 
			p_setBlockAt(piece, 0, 2); 

			//h >= w
			//h = 3, w = 2
			//i = x * h + y

			//Bit 0 - (0, 0) - 0 * 3 + 0
			//Bit 1 - (0, 1) - 0 * 3 + 1
			//Bit 2 - (0, 2) - 0 * 3 + 2
			//Bit 3 - (1, 0) - 1 * 3 + 0
			//Bit 4 - (1, 1) - 1 * 3 + 1
			//Bit 5 - (1, 2) - 1 * 3 + 2

			//else
			//h = 2, w = 3
			//i = y * w + x

			//Bit 0 - (0, 0) - 0 * 3 + 0
			//Bit 1 - (1, 0) - 0 * 3 + 1
			//Bit 2 - (2, 0) - 0 * 3 + 2
			//Bit 3 - (0, 1) - 1 * 3 + 0
			//Bit 4 - (1, 1) - 1 * 3 + 1
			//Bit 5 - (1, 2) - 1 * 3 + 2

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
	unsigned char width = p_getPieceWidth(piece->data);

	if (height >= width) {
		mask <<= (xBlockPos * height) + yBlockPos;
	}
	else {
		mask <<= (yBlockPos * width) + xBlockPos;

		//h = 2, w = 3

		//Bit 0 - (0, 0) - 0 * 3 + 0
		//Bit 1 - (1, 0) - 1 * 3 + 0
		//Bit 2 - (2, 0) - 2 * 3 + 0
		//Bit 3 - (0, 1) - 1 + 1 * 2
		//Bit 4 - (1, 1) - 0 + 2 * 2
		//Bit 5 - (2, 1) - 1 + 2 * 2
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