#ifndef _GAME_OVER_H_
#define _GAME_OVER_H_

#include "../util/button.h"

#include "../math/vec2.h"

#include "../render/color.h"
#include "../render/type.h"

#include "stateManager.h"

#include "block.h"

#define GO_FALSE 0
#define GO_TRUE 1

//Transition
extern const float G_END_GAME_BLOCK_SIZE;
extern const vec2 G_END_GAME_BLOCKS_START;
extern const unsigned int G_END_GAME_BLOCKS_VERTICAL_COUNT;
static vec2 go_blocksStart;
static unsigned char go_transitionFinished;

//Title
static const unsigned char* GO_TITLE_TEXT = "game over";

static const vec2 GO_TITLE_POSITION = { SCR_WIDTH / (float)2, SCR_HEIGHT / (float)4 };

static const float GO_TITLE_WIDTH = 7 * SCR_WIDTH / (float)8;
static const float GO_TITLE_CHAR_THICKNESS = SCR_WIDTH / (float)80;

static vec2 GO_TITLE_CHAR_SCALE;

//Button Selection
static ButtonSelector* go_originalSelection;
static ButtonSelector* go_currentSelection;

static unsigned char go_selectionVisibilityToggle;

//Button Text
static const float GO_BUTTON_TEXT_THICKNESS = SCR_WIDTH / (float)150;

#define GO_BUTTON_CHAR_SCALE_X (SCR_WIDTH / (float)25)
#define GO_BUTTON_CHAR_SCALE_Y (SCR_HEIGHT / (float)25)
static const vec2 GO_BUTTON_CHAR_SCALE = { GO_BUTTON_CHAR_SCALE_X, GO_BUTTON_CHAR_SCALE_Y };

#define GO_BUTTON_ORIGIN_X (SCR_WIDTH / (float)2)
#define GO_BUTTON_ORIGIN_Y ((3 * SCR_HEIGHT) / (float)4)

//Restart Button
#define GO_BUTTON_RESTART 0
static unsigned char* GO_RESTART_TEXT = "restart";
static const vec2 GO_RESTART_POSITION = { GO_BUTTON_ORIGIN_X, GO_BUTTON_ORIGIN_Y - GO_BUTTON_CHAR_SCALE_Y };

//Quit Button
#define GO_BUTTON_QUIT 1
static const char* GO_QUIT_TEXT = "quit";
static const vec2 GO_QUIT_POSITION = { GO_BUTTON_ORIGIN_X, GO_BUTTON_ORIGIN_Y + GO_BUTTON_CHAR_SCALE_Y };

void go_init();

void go_update(float deltaTime);

void go_processInput();

void go_render();

#endif