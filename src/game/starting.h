#ifndef _STARTING_H_
#define _STARTING_H_

#include "../math/vec2.h"

#include "../util/window.h"

#include "stateManager.h"

#define STARTING_COUNTDOWN_TIME 3
#define STARTING_TEXT_LENGTH 1

static const vec2 G_STARTING_COUNTDOWN_POSITION = { SCR_WIDTH / (float)2, SCR_HEIGHT / (float)2 };
static const vec2 G_STARTING_COUNTDOWN_CHAR_SCALE = { SCR_WIDTH / (float)5, 2 * SCR_HEIGHT / (float)5 };

static const float G_STARTING_COUNTDOWN_THICKNESS = SCR_WIDTH / (float)50;

static char G_STARTING_COUNTDOWN_TEXT[] = { '0', '\0' };

static float st_startingTimer = STARTING_COUNTDOWN_TIME + 1;

void st_update(float deltaTime);

void st_render();

#endif