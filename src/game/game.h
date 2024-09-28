#ifndef _GAME_H_
#define _GAME_H_

#include "../util/window.h"

#include "../math/mat4.h"

#include "../render/shader.h"
#include "../render/texture.h"
#include "../render/quad.h"

static unsigned int shaderID;
static unsigned int textureID;

static vec2 pos;
static vec2 scale;

void g_init();

void g_processInput(float deltaTime);

void g_processGameTic(float deltaTime);

void g_render();

#endif