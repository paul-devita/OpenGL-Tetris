#ifndef _TITLE_H_
#define _TITLE_H_

#include "stateManager.h"

#include "../util/window.h"
#include "../util/util.h"

#include "../math/vec2.h"

//TITLE STATE
#define G_START_ANIMATION_INTERVAL_UP 2.0
#define G_START_ANIMATION_INTERVAL_DOWN 0.5

static unsigned char g_start_pressStartToggle = 1;

//Title Text
static const char* G_START_TITLE_TEXT = "tetris";

static const float G_START_TITLE_THICKNESS = SCR_WIDTH / 50.0;

static float G_START_TITLE_WIDTH = 0;
static float G_START_TITLE_HEIGHT = 0;
static float G_START_TITLE_SPACING = 0;
static float G_START_TITLE_LETTER_WIDTH = 0;

static vec2 G_START_TITLE_POSITION;
static vec2 G_START_TITLE_CHAR_SCALE;

//Press Start Text
static const char* G_START_PRESS_TEXT = "Press Enter To Play";

static const float G_START_PRESS_THICKNESS = SCR_WIDTH / 500.0;

static float G_START_PRESS_WIDTH = 0;
static float G_START_PRESS_HEIGHT = 0;
static float G_START_PRESS_SPACING = 0;
static float G_START_PRESS_LETTER_WIDTH = 0;

static vec2 G_START_PRESS_POSITION;
static vec2 G_START_PRESS_CHAR_SCALE;


void ti_init();

void ti_update(float deltaTime);

static void ti_proccessInput();

void ti_render();

#endif