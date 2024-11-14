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
	switch (pieceType) {
		case P_I_PIECE:
			if (randomColor) {
				//Set random color
			}
			else {
				p_setPieceColor(piece, COLOR_INDEX_BLUE);
			}

			short grY = gridPosition->y;
			short grX = gridPosition->x;

			for (int i = 0; i < P_BLOCK_COUNT; i++) {
				piece->blocks[i].x = grX;
				piece->blocks[i].y = grY;

				grX++;

				printf("%d, %d\n", piece->blocks[i].x, piece->blocks[i].y);
			}

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

unsigned char p_getPieceColor(PieceData data) {
	unsigned char mask = 0x0F; // 00001111

	unsigned char result = data & mask;

	return result;
}

void p_setPieceColor(Piece* piece, unsigned char colorIndex) {
	unsigned char mask = 0xF0; // 11110000

	piece->data &= mask;

	mask |= colorIndex;

	piece->data |= mask;
}

unsigned char p_getPieceHeightFromData(PieceData data) {
	unsigned char mask = 0xC0; // 11000000

	unsigned char result = (data & mask) >> 6;

	return result;
}

unsigned char p_getPieceHeight(Piece* piece) {

}

void p_setPieceHeight(Piece* piece, unsigned char height) {
	unsigned char mask = 0x3F; // 00111111

	piece->data &= mask;

	height <<= 6;

	mask |= height;

	piece->data |= mask;
}

unsigned char p_getPieceWidthFromData(PieceData data) {

}

unsigned char p_getPieceWidth(Piece* piece) {

}

void p_setPieceWidth(Piece* piece, unsigned char width) {

}

void p_translate(Piece* piece, short dx, short dy) {

}

void p_rotate(Piece* piece) {
	for (int i = 0; i < P_BLOCK_COUNT; i++) {
		vec2s* oldPos = &piece->blocks[i];

		short newY = oldPos->x;
		short newX = oldPos->y - 2;

		if (newX < 0) newX *= -1;

		oldPos->x = newX;
		oldPos->y = newY;
	}
}

void p_draw(Piece* piece) {
	static unsigned char x = 1;

	unsigned char colorIndex = p_getPieceColor(piece->data);

	for (int i = 0; i < P_BLOCK_COUNT; i++) {
		vec2 screenPos = gr_gridToScreen(&piece->blocks[i]);

		if (x) {
			printf("%f, %f\n", screenPos.x, screenPos.y);

			if (x == 4)
				x = 0;
			else
				x++;
		}

		b_drawBlock(&screenPos, colorIndex);
	}
}