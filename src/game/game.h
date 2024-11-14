#ifndef _GAME_H_
#define _GAME_H_

#include "../util/window.h"

#include "../math/mat4.h"

#include "../render/shader.h"
#include "../render/texture.h"
#include "../render/quad.h"
#include "../render/type.h"
#include "../render/color.h"

#include "block.h"
#include "grid.h"
#include "piece.h"
#include "ui.h"

//Start State Functionality----------------------------------------------------------------------------------------

#define G_START_ANIMATION_INTERVAL_UP 2.0
#define G_START_ANIMATION_INTERVAL_DOWN 0.5

static unsigned char g_start_pressStartToggle = 1;

//Title Text----------------------------------------------------------------
static const char* G_START_TITLE_TEXT = "tetris";

static const float G_START_TITLE_THICKNESS = SCR_WIDTH / 50.0;

static float G_START_TITLE_WIDTH = 0;
static float G_START_TITLE_HEIGHT = 0;
static float G_START_TITLE_SPACING = 0;
static float G_START_TITLE_LETTER_WIDTH = 0;

static vec2 G_START_TITLE_POSITION;
static vec2 G_START_TITLE_CHAR_SCALE;

//Press Start Text----------------------------------------------------------
static const char* G_START_PRESS_TEXT = "Press Enter To Play";

static const float G_START_PRESS_THICKNESS = SCR_WIDTH / 500.0;

static float G_START_PRESS_WIDTH = 0;
static float G_START_PRESS_HEIGHT = 0;
static float G_START_PRESS_SPACING = 0;
static float G_START_PRESS_LETTER_WIDTH = 0;

static vec2 G_START_PRESS_POSITION;
static vec2 G_START_PRESS_CHAR_SCALE;

//GAME---------------------------------------------------------------------------------------------------------
	#define G_MAXIMUM_SCORE 9999999

	#define G_MAXIMUM_STATS 9999
			
	static Piece g_falling;

	#define SECONDS_PER_UPDATE 0.1

	#define GAME_STATE_TITLE 0
	#define GAME_STATE_PLAY 1

	#define G_FALSE 0
	#define G_TRUE 1

	#define G_COLOR_COUNT 8

	static unsigned char g_state = GAME_STATE_TITLE;

//-----------------------------------------------------------------------------------------------------------------

void g_init();

void g_update(float deltaTime);

static void g_updateTitle(float udt);
static void g_updatePlay(float udt);

void g_render();

static void g_drawGridLines();

void g_changeState(unsigned char destinationState);

void g_increaseScore(unsigned int additionalScore);

void g_incrementStat(unsigned char block);

#endif