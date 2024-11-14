#ifndef _PIECE_H_
#define _PIECE_H_

#include "block.h"
#include "grid.h"

#define P_BLOCK_COUNT 4

#define P_I_PIECE 0	 //         - 000
#define P_J_PIECE 1  //         - 001
#define P_L_PIECE 2  //         - 010
#define P_O_PIECE 3  //         - 011
#define P_S_PIECE 4  //         - 100
#define P_T_PIECE 5  //         - 101
#define P_Z_PIECE 6  //         - 110

#define P_COLOR_INDEX_0 0 //         - 00000
#define P_COLOR_INDEX_1 1 //         - 00001
#define P_COLOR_INDEX_2 2 //         - 00010
#define P_COLOR_INDEX_3 3 //         - 00011
#define P_COLOR_INDEX_4 4 //         - 00100
#define P_COLOR_INDEX_5 5 //         - 00101
#define P_COLOR_INDEX_6 6 //         - 00110
#define P_COLOR_INDEX_7 7 //         - 00111

typedef unsigned char PieceData;

/*
	Data Format:	    [Bit 8]---    00			00			0000   ---[Bit 0]
									  ||			||	     	|--|
								  height bits	width bits	 color bits
*/

typedef struct {
	vec2s blocks[P_BLOCK_COUNT];
	PieceData data;
} Piece;

void p_init();

void p_createPiece(Piece* piece, vec2s* gridPosition, unsigned char pieceType, unsigned char randomColor);

unsigned char p_getPieceColor(PieceData data);
void p_setPieceColor(Piece* piece, unsigned char colorIndex);

unsigned char p_getPieceHeightFromData(PieceData data);
unsigned char p_getPieceHeight(Piece* piece);
void p_setPieceHeight(Piece* piece, unsigned char height);

unsigned char p_getPieceWidthFromData(PieceData data);
unsigned char p_getPieceWidth(Piece* piece);
void p_setPieceWidth(Piece* piece, unsigned char width);

unsigned char p_

void p_translate(Piece* piece, short dx, short dy);

void p_rotate(Piece* piece);

void p_draw(Piece* piece);

void p_drawDummy(unsigned char pieceType, unsigned char rotation, vec2* position, vec2* scale);

#endif