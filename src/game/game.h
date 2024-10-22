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
	static const char* G_START_TITLE_TEXT = "Tetris";

	static const float G_START_TITLE_THICKNESS = SCR_WIDTH / 50.0;

	static unsigned short G_START_TITLE_TEXT_LENGTH = 0;
	
	static float G_START_TITLE_WIDTH = 0;
	static float G_START_TITLE_HEIGHT = 0;
	static float G_START_TITLE_SPACING = 0;
	static float G_START_TITLE_LETTER_WIDTH = 0;

	static vec2 G_START_TITLE_POSITION;
	static vec2 G_START_TITLE_CHAR_SCALE;

	//Press Start Text----------------------------------------------------------
	#define G_START_ANIMATION_INTERVAL_UP 2.0
	#define G_START_ANIMATION_INTERVAL_DOWN 0.5

	static const char* G_START_PRESS_TEXT = "Press Enter To Play";

	static const float G_START_PRESS_THICKNESS = SCR_WIDTH / 500.0;

	static unsigned short G_START_PRESS_TEXT_LENGTH = 0;

	static float G_START_PRESS_WIDTH = 0;
	static float G_START_PRESS_HEIGHT = 0;
	static float G_START_PRESS_SPACING = 0;
	static float G_START_PRESS_LETTER_WIDTH = 0;

	static vec2 G_START_PRESS_POSITION;
	static vec2 G_START_PRESS_CHAR_SCALE;

	static unsigned char g_start_pressStartToggle = 1;

//Game State Functionality-----------------------------------------------------------------------------------------

	//UI-----------------------------------------------------------------------------------------------------------
	
	static const float G_GAME_BOX_THICKNESS = SCR_WIDTH / 150.0;
	static const float G_GAME_GAME_BOX_THICKNESS = SCR_WIDTH / 50.0;

		//Score Box-----------------------------------------------------------------
			#define G_GAME_SCORE_TEXT_LENGTH 7
			
			static const char* G_GAME_SCORE_TITLE_TEXT = "score";
			static char* G_GAME_SCORE_TEXT = "0000000";
			
			static const float G_GAME_SCORE_TITLE_TEXT_THICKNESS = SCR_WIDTH / 250.0;

			static const float G_GAME_SCORE_TEXT_THICKNESS = SCR_WIDTH / 350.0;
			static const float G_GAME_SCORE_TEXT_CHAR_SPACING = SCR_WIDTH / 150.0;

			static unsigned int G_GAME_SCORE_TITLE_TEXT_LENGTH = 0;
		
			static vec2 G_GAME_SCORE_BOX_POSITION;
			static vec2 G_GAME_SCORE_BOX_SCALE;

			static vec2 G_GAME_SCORE_TITLE_TEXT_POSITION;
			static vec2 G_GAME_SCORE_TITLE_TEXT_SCALE;

			static vec2 G_GAME_SCORE_TEXT_POSITION;
			static vec2 G_GAME_SCORE_TEXT_SCALE;

		//Next Box------------------------------------------------------------------
			static vec2 G_GAME_NEXT_BOX_POSITION;
			static vec2 G_GAME_NEXT_BOX_SCALE;

		//Hold Box------------------------------------------------------------------
			static vec2 G_GAME_HOLD_BOX_POSITION;
			static vec2 G_GAME_HOLD_BOX_SCALE;

		//Stats Box-----------------------------------------------------------------
			static vec2 G_GAME_STATS_BOX_POSITION;
			static vec2 G_GAME_STATS_BOX_SCALE;

		//Game Box------------------------------------------------------------------
			static vec2 G_GAME_GAME_BOX_POSITION;
			static vec2 G_GAME_GAME_BOX_SCALE;

static const vec3 G_COLOR_WHITE = { 1.0f, 1.0f, 1.0f };

static unsigned char g_state = GAME_STATE_TITLE;

void g_init();

void g_update(float deltaTime);

static void g_updateTitle(float udt);
static void g_updatePlay(float udt);

void g_render();

void g_changeState(unsigned char destinationState);

#endif