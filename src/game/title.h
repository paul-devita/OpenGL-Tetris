#ifndef _TITLE_H_
#define _TITLE_H_

#include "stateManager.h"

#include "../util/window.h"
#include "../util/util.h"

#include "../math/vec2.h"

#include "../render/texture.h"

#define TI_FALSE 0
#define TI_TRUE 1

//Title Text
static const char* G_START_TITLE_TEXT = "tetris";

static const float G_START_TITLE_THICKNESS = SCR_WIDTH / (float)35;

static const float G_START_TITLE_SPACING = SCR_WIDTH / (float)60;

static const vec2 G_START_TITLE_POSITION = { SCR_WIDTH / (float)2, 3 * SCR_HEIGHT / (float)10 };
static vec2 G_START_TITLE_CHAR_SCALE;

//Title Button State
static const float TI_BUTTON_TEXT_THICKNESS = SCR_WIDTH / (float)150;
static const float TI_BUTTON_CHAR_SPACING = SCR_WIDTH / (float)150;

#define TI_BUTTON_CHAR_SCALE_X SCR_WIDTH / (float)25
#define TI_BUTTON_CHAR_SCALE_Y SCR_HEIGHT / (float)25
static const vec2 TI_BUTTON_CHAR_SCALE = { TI_BUTTON_CHAR_SCALE_X, TI_BUTTON_CHAR_SCALE_Y };

//Start Button
static const unsigned char* TI_START_BUTTON_TEXT = "Start Game";
static const vec2 TI_START_BUTTON_POS = { SCR_WIDTH / (float)2, (3 * SCR_HEIGHT / (float)4) - TI_BUTTON_CHAR_SCALE_Y };

//Quit Button
static const unsigned char* TI_QUIT_BUTTON_TEXT = "Quit Game";
static const vec2 TI_QUIT_BUTTON_POS = { SCR_WIDTH / (float)2, (3 * SCR_HEIGHT / (float)4) + TI_BUTTON_CHAR_SCALE_Y };

//Button Selection
static const unsigned char* TI_BUTTON_SELECTOR_PATH = "../resources/textures/selection.png";

static unsigned int TI_BUTTON_SELECTOR_TEXTURE_ID;

#define TI_SELECTION_VISIBILITY_INTERVAL 0.5
static float ti_selectionTimer = 0;
static unsigned char ti_selectionVisibilityToggle = 1;

#define TI_BUTTON_START 0
#define TI_BUTTON_QUIT 1
typedef struct {
	vec2* pos;
	struct TitleButtonState* next;
	struct TitleButtonState* prev;
	unsigned int length;
	unsigned char id;
} TitleButtonState;

static const vec2 TI_BUTTON_SELECTOR_SCALE = { SCR_HEIGHT / (float)15, SCR_HEIGHT / (float)15 };

static TitleButtonState* ti_buttonCurrent;

void ti_init();

void ti_update(float deltaTime);

void ti_render();

void ti_processInput();

#endif