#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "../render/texture.h"
#include "../render/quad.h"

#include "../math/vec2.h"
#include "../math/vec3.h"

#define B_BLOCK_TEXTURE_PATH "../resources/textures/block.png"

#define B_NUL_BLOCK 0 //             - 000

#define B_I_BLOCK 1	//				 - 001
#define B_J_BLOCK 2 //				 - 010
#define B_L_BLOCK 3 //				 - 011
#define B_O_BLOCK 4 //				 - 100
#define B_S_BLOCK 5 //				 - 101
#define B_T_BLOCK 6 //				 - 110
#define B_Z_BLOCK 7 //				 - 111

#define B_ROTATION_O 0 //Normal      - 00
#define B_ROTATION_1 1 //90			 - 01
#define B_ROTATION_2 2 //Inverted    - 10
#define B_ROTATION_3 3 //270		 - 11

#define B_COLOR_INDEX_0 0 //         - 000
#define B_COLOR_INDEX_1 1 //         - 001
#define B_COLOR_INDEX_2 2 //         - 010
#define B_COLOR_INDEX_3 3 //         - 011
#define B_COLOR_INDEX_4 4 //         - 100
#define B_COLOR_INDEX_5 5 //         - 101
#define B_COLOR_INDEX_6 6 //         - 110
#define B_COLOR_INDEX_7 7 //         - 111

typedef unsigned char BlockData;

/*
	Data Format:	    [Bit 8]---   000				00				000   ---[Bit 0]
					                 |-|				||				|-|
					              color bits       rotation bits	 type bits
*/

typedef struct {
	vec2 position;
	BlockData data;
} Piece;

static unsigned int B_BLOCK_TEXTURE;

void b_init();

unsigned char b_getBlockType(BlockData data);

unsigned char b_getBlockRotation(BlockData data);

unsigned char b_getBlockColor(BlockData data);

void b_translate(Piece* piece, int dx, int dy);

void b_rotate(unsigned char newRotation);

void b_drawSingle(vec2 position, vec2 scale, vec3 color);

void b_drawBlock(unsigned char type, vec2 position, vec2 scale, vec3 color);

void b_drawPiece(unsigned int gridPosX, unsigned int gridPosY, BlockData data);

void b_drawPiece(vec2 position, BlockData data);

void b_drawPiece(Piece* piece);

#endif