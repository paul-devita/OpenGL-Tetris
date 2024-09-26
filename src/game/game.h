#ifndef _GAME_H_
#define _GAME_H_

static unsigned int shaderID;

static unsigned int textureID;

void g_init();

void g_processInput(float deltaTime);

void g_processGameTic(float deltaTime);

void g_render();

#endif