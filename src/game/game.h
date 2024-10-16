#ifndef _GAME_H_
#define _GAME_H_

#include "../util/window.h"

#include "../math/mat4.h"

#include "../render/shader.h"
#include "../render/texture.h"
#include "../render/quad.h"
#include "../render/type.h"

#define SECONDS_PER_UPDATE 0.1

#define GAME_STATE_TITLE 0
#define GAME_STATE_PLAY 1

#define GAME_FALSE 0
#define GAME_TRUE 1

//Start State Functionality----------------------------------------------------------------------------------------
	
	//Title Text----------------------------------------------------------------
	#define G_START_TITLE_TEXT "Tetris"
	#define G_START_TITLE_TEXT_LENGTH 6.0
	static const unsigned int G_START_TITLE_THICKNESS = SCR_WIDTH / 50;
	
	static float G_START_TITLE_WIDTH = 0;
	static float G_START_TITLE_HEIGHT = 0;
	static float G_START_TITLE_SPACING = 0;
	static float G_START_TITLE_LETTER_WIDTH = 0;

	static vec2 G_START_TITLE_POSITION;
	static vec2 G_START_TITLE_CHAR_SCALE;

	//Press Start Text----------------------------------------------------------
	#define G_START_PRESS_TEXT "Press Enter To Play"
	#define G_START_PRESS_TEXT_LENGTH 19.0
	#define G_START_ANIMATION_INTERVAL_UP 2.0
	#define G_START_ANIMATION_INTERVAL_DOWN 0.5
	static const unsigned int G_START_PRESS_THICKNESS = SCR_WIDTH / 500;

	static float G_START_PRESS_WIDTH = 0;
	static float G_START_PRESS_HEIGHT = 0;
	static float G_START_PRESS_SPACING = 0;
	static float G_START_PRESS_LETTER_WIDTH = 0;

	static vec2 G_START_PRESS_POSITION;
	static vec2 G_START_PRESS_CHAR_SCALE;

	static unsigned char g_start_pressStartToggle = 1;


static const vec3 G_START_TEXT_COLOR = { 1.0f, 1.0f, 1.0f };

//Game State Functionality-----------------------------------------------------------------------------------------

static unsigned char state = GAME_STATE_TITLE;

void g_init();

void g_update(float deltaTime);

static void g_updateTitle(float udt);
static void g_updatePlay(float udt);

void g_render();

void g_changeState(unsigned char destinationState);

#endif