#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "../render/texture.h"
#include "../render/quad.h"

#include "../math/vec2.h"
#include "../math/vec3.h"

#define B_BLOCK_TEXTURE_PATH "../resources/textures/block.png"

#define B_I_BLOCK 0
#define B_J_BLOCK 1
#define B_L_BLOCK 2
#define B_O_BLOCK 3
#define B_S_BLOCK 4
#define B_T_BLOCK 5
#define B_Z_BLOCK 6

typedef struct {
	vec2 positon;
	unsigned char data;
} Block;

//Make matrix of blocks to define the board
//Use statically allocated array or linked list to define blocks that are not placed

static unsigned int B_BLOCK_TEXTURE;

void b_init();

void b_drawSingle(vec2 position, vec2 scale, vec3 color);

void b_drawBlock(unsigned char type, vec2 position, vec2 scale, vec3 color);

#endif