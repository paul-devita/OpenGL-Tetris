#ifndef _GAME_H_
#define _GAME_H_

#include "../util/window.h"

#include "../math/mat4.h"

#include "../render/shader.h"
#include "../render/texture.h"
#include "../render/quad.h"

#define SECONDS_PER_UPDATE 0.1

#define GAME_STATE_TITLE 0
#define GAME_STATE_PLAY 1
#define GAME_STATE_PAUSED 2
#define GAME_STATE_OVER 3

static unsigned char state = GAME_STATE_TITLE;

void g_init();

void g_processInput(float deltaTime);

void g_update(float deltaTime);

static void g_updateTitle(float dt);
static void g_updatePlay(float dt);
static void g_updatePaused(float dt);
static void g_updateOver(float dt);

void g_render();

#endif