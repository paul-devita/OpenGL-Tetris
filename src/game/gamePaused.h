#ifndef _GAME_PAUSED_H_
#define _GAME_PAUSED_H_

#include "stateManager.h"

//Button Selection
typedef struct {
	vec2* pos;
	struct PausedButtonState* next;
	struct PausedButtonState* prev;
	unsigned int length;
	unsigned char id;
} PausedButtonState;

static PausedButtonState* gp_currentButton = NULL;

//Resume Button
#define GP_BUTTON_RESUME 0



//Restart Button
#define GP_BUTTON_RESTART 1

//Title Button
#define GP_BUTTON_TITLE 2

void gp_init();

void gp_update(float deltaTime);

void gp_render();

#endif