#ifndef _GAME_PAUSED_H_
#define _GAME_PAUSED_H_

#include "../util/window.h"
#include "../util/button.h"

#include "stateManager.h"

#define GP_FALSE 0
#define GP_TRUE 1

//Title
static const unsigned char* GP_TITLE_TEXT = "game paused";

static const vec2 GP_TITLE_POSITION = { SCR_WIDTH / (float)2, SCR_HEIGHT / (float)4 };

static const float GP_TITLE_WIDTH = 7 * SCR_WIDTH / (float)8;
static const float GP_TITLE_CHAR_THICKNESS = SCR_WIDTH / (float)100;

static vec2 GP_TITLE_CHAR_SCALE;

//Button Selection
static ButtonSelector* gp_originalSelection;
static ButtonSelector* gp_currentButton;

static unsigned char gp_selectionVisibilityToggle = U_FALSE;

//Button Text
static const float GP_BUTTON_TEXT_THICKNESS = SCR_WIDTH / (float)150;

#define GP_BUTTON_CHAR_SCALE_X (SCR_WIDTH / (float)25)
#define GP_BUTTON_CHAR_SCALE_Y (SCR_HEIGHT / (float)25)
static const vec2 GP_BUTTON_CHAR_SCALE = { GP_BUTTON_CHAR_SCALE_X, GP_BUTTON_CHAR_SCALE_Y };

#define GP_BUTTON_ORIGIN_X (SCR_WIDTH / (float)2)
#define GP_BUTTON_ORIGIN_Y ((3 * SCR_HEIGHT) / (float)4)

//Resume Button
#define GP_BUTTON_RESUME 0
static const unsigned char* GP_BUTTON_RESUME_TEXT = "resume";
static const vec2 GP_RESUME_POSITION = { GP_BUTTON_ORIGIN_X, GP_BUTTON_ORIGIN_Y - 3 * GP_BUTTON_CHAR_SCALE_Y / (float)2 };

//Restart Button
#define GP_BUTTON_RESTART 1
static const unsigned char* GP_RESTART_TEXT = "restart";
static const vec2 GP_RESTART_POSITION = { GP_BUTTON_ORIGIN_X, GP_BUTTON_ORIGIN_Y };

//Quit Button
#define GP_BUTTON_QUIT 2
static const unsigned char* GP_QUIT_TEXT = "quit";
static const vec2 GP_QUIT_POSITION = { GP_BUTTON_ORIGIN_X, GP_BUTTON_ORIGIN_Y + (3 * GP_BUTTON_CHAR_SCALE_Y) / (float)2 };

void gp_init();

void gp_update(float deltaTime);

void gp_render();

void gp_processInput();

#endif