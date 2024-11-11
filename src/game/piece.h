#ifndef _PIECE_H_
#define _PIECE_H_

#include "block.h"

#define P_I_PIECE 0	
#define P_J_PIECE 1 
#define P_L_PIECE 2 
#define P_O_PIECE 3 
#define P_S_PIECE 4 
#define P_T_PIECE 5 
#define P_Z_PIECE 6 

#define P_ROTATION_O 0 //Normal      - 00
#define P_ROTATION_1 1 //90			 - 01
#define P_ROTATION_2 2 //Inverted    - 10
#define P_ROTATION_3 3 //270		 - 11

#define P_COLOR_INDEX_0 0 //         - 000
#define P_COLOR_INDEX_1 1 //         - 001
#define P_COLOR_INDEX_2 2 //         - 010
#define P_COLOR_INDEX_3 3 //         - 011
#define P_COLOR_INDEX_4 4 //         - 100
#define P_COLOR_INDEX_5 5 //         - 101
#define P_COLOR_INDEX_6 6 //         - 110
#define P_COLOR_INDEX_7 7 //         - 111

typedef unsigned char PieceData;

/*
	Data Format:	    [Bit 8]---   000				00				000   ---[Bit 0]
									 |-|				||				|-|
								  color bits       rotation bits	 type bits
*/

typedef struct {
	vec2 blocks[4];
	PieceData data;
} Piece;

unsigned char p_getBlockType(PieceData data);

unsigned char p_getBlockRotation(PieceData data);

unsigned char p_getBlockColor(PieceData data);

void p_translate(Piece* piece, float dx, float dy);


#endif