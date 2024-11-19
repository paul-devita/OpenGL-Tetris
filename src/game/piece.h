#ifndef _PIECE_H_
#define _PIECE_H_

#include "../util/random.h"

#include "block.h"
#include "grid.h"

#define P_BLOCK_COUNT 4

#define P_I_PIECE_INDEX 0  //         - 000
#define P_J_PIECE_INDEX 1  //         - 001
#define P_L_PIECE_INDEX 2  //         - 010
#define P_O_PIECE_INDEX 3  //         - 011
#define P_S_PIECE_INDEX 4  //         - 100
#define P_T_PIECE_INDEX 5  //         - 101
#define P_Z_PIECE_INDEX 6  //         - 110

typedef unsigned char PieceData;

/*
	Data Format:	    [Bit 8]---    00			00			0000   ---[Bit 0]
									  ||			||	     	|--|
								  height bits	width bits	 color bits
*/

typedef struct {
	vec2s position;
	unsigned char blocks;
	PieceData data;
} Piece;

static Piece P_I_PIECE;
static Piece P_J_PIECE;
static Piece P_L_PIECE;
static Piece P_O_PIECE;
static Piece P_S_PIECE;
static Piece P_T_PIECE;
static Piece P_Z_PIECE;

void p_init();

void p_createPiece(Piece* piece, vec2s* gridPosition, unsigned char pieceType, unsigned char randomColor);

void p_setBlockAt(Piece* piece, unsigned char xBlockPos, unsigned char yBlockPos);
void p_setBlockAtFromByte(unsigned char* blocks, unsigned char xBlockPos, unsigned char yBlockPos, unsigned char width, unsigned char height);

void p_unsetBlockAt(Piece* piece, unsigned char xBlockPos, unsigned char yBlockPos);

unsigned char p_getBlockAt(Piece* piece, unsigned char xBlockPos, unsigned char yBlockPos);

unsigned char p_getPieceColor(PieceData data);
void p_setPieceColor(Piece* piece, unsigned char colorIndex);

unsigned char p_getPieceHeight(PieceData data);
void p_setPieceHeight(Piece* piece, unsigned char height);

unsigned char p_getPieceWidth(PieceData data);
void p_setPieceWidth(Piece* piece, unsigned char width);

void p_translate(Piece* piece, short dx, short dy);

void p_rotate(Piece* piece);

void p_draw(Piece* piece);

void p_drawDummy(unsigned char pieceType, vec2* position, float blockSize, unsigned char colorIndex);

#endif