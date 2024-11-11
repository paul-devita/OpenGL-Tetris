#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "../render/texture.h"
#include "../render/quad.h"
#include "../render/color.h"

#include "../math/vec2.h"
#include "../math/vec3.h"

#include "grid.h"

#define B_BLOCK_TEXTURE_PATH "../resources/textures/block.png"

static unsigned int B_BLOCK_TEXTURE;

static vec2 B_BLOCK_SCALE;

//Initializes textures and block size
//MUST be called AFTER grid.h is initialized
void b_init();

void b_drawBlock(vec2* position, vec2* scale, vec3* color);

void b_drawBlock(unsigned int gridPosX, unsigned int gridPosY, unsigned char colorIndex);

#endif