#ifndef _GAME_OVER_H_
#define _GAME_OVER_H_

#include "../math/vec2.h"

#include "../render/color.h"

#include "block.h"

#define GO_FALSE 0
#define GO_TRUE 1

extern const float G_END_GAME_BLOCK_SIZE;

extern const vec2 G_END_GAME_BLOCKS_START;

extern const unsigned int G_END_GAME_BLOCKS_VERTICAL_COUNT;

static vec2 go_blocksStart;

static unsigned char go_transitionFinished;

void go_init();

void go_update(float deltaTime);

void go_processInput();

void go_render();

#endif