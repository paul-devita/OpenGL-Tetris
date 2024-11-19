#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "../render/texture.h"
#include "../render/quad.h"
#include "../render/color.h"

#include "../math/vec2.h"
#include "../math/vec3.h"

#define B_BLOCK_TEXTURE_PATH "../resources/textures/block.png"

static unsigned int B_BLOCK_TEXTURE;

extern const float GRID_CELL_SIZE;

static vec2 B_BLOCK_SCALE;

//Initializes textures and block size
//MUST be called AFTER grid.h is initialized
void b_init();

void b_drawBlock(vec2* position, unsigned char colorIndex);

void b_drawDummyBlock(vec2* position, float blockSize, unsigned char colorIndex);

#endif