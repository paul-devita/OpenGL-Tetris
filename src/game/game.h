#ifndef _GAME_H_
#define _GAME_H_

#include "../util/window.h"

#include "../math/mat4.h"

#include "../render/shader.h"
#include "../render/texture.h"
#include "../render/quad.h"
#include "../render/type.h"

//Start State Functionality----------------------------------------------------------------------------------------
	
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
	#define G_START_ANIMATION_INTERVAL_UP 2.0
	#define G_START_ANIMATION_INTERVAL_DOWN 0.5

	static const char* G_START_PRESS_TEXT = "Press Enter To Play";

	static const float G_START_PRESS_THICKNESS = SCR_WIDTH / 500.0;

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

	static const float G_GAME_TEXT_HEIGHT = SCR_HEIGHT / 40.0;

	static const float G_GAME_TEXT_THICKNESS_STANDARD = SCR_WIDTH / 350.0;
	static const float G_GAME_TEXT_THICKNESS_BOLD = SCR_WIDTH / 250.0;

	static const float G_GAME_TEXT_CHAR_SPACING = SCR_WIDTH / 200.0;

		//Score Box-----------------------------------------------------------------
			#define G_GAME_SCORE_TEXT_LENGTH 7
			
			static const char* G_GAME_SCORE_TITLE_TEXT = "score";

			static char G_GAME_SCORE_TEXT[G_GAME_SCORE_TEXT_LENGTH + 1];
		
			static vec2 G_GAME_SCORE_BOX_POSITION;
			static vec2 G_GAME_SCORE_BOX_SCALE;

			static vec2 G_GAME_SCORE_TITLE_TEXT_POSITION;
			static vec2 G_GAME_SCORE_TITLE_TEXT_SCALE;

			static vec2 G_GAME_SCORE_TEXT_POSITION;
			static vec2 G_GAME_SCORE_TEXT_SCALE;

		//Next Box------------------------------------------------------------------
			static const char* G_GAME_NEXT_TITLE_TEXT = "next";

			static vec2 G_GAME_NEXT_BOX_POSITION;
			static vec2 G_GAME_NEXT_BOX_SCALE;

			static vec2 G_GAME_NEXT_TITLE_TEXT_POSITION;
			static vec2 G_GAME_NEXT_TITLE_TEXT_SCALE;

			static vec2 G_GAME_NEXT_BLOCK_POSITION;
			static vec2 G_GAME_NEXT_BLOCK_SCALE;

		//Hold Box------------------------------------------------------------------
			static const char* G_GAME_HOLD_TITLE_TEXT = "hold";

			static vec2 G_GAME_HOLD_BOX_POSITION;
			static vec2 G_GAME_HOLD_BOX_SCALE;

			static vec2 G_GAME_HOLD_TITLE_TEXT_POSITION;
			static vec2 G_GAME_HOLD_TITLE_TEXT_SCALE;

			static vec2 G_GAME_HOLD_BLOCK_POSITION;
			static vec2 G_GAME_HOLD_BLOCK_SCALE;

		//Stats Box-----------------------------------------------------------------
			#define G_GAME_STATS_NUM_LENGTH 4

			#define G_GAME_STATS_MAXIMUM_COUNT 9999

			static const char* G_GAME_STATS_TITLE_TEXT = "stats";

			static const float G_GAME_STATS_ELEMENT_SPACING = SCR_HEIGHT / 64.0;

			static const vec2 G_GAME_STATS_ELEMENT_SCALE = { (3 * SCR_WIDTH) / 20.0, (9 * (SCR_HEIGHT / 2.0)) / 112.0 - (6 * SCR_HEIGHT / 64.0) / 7.0 };
			
			static char G_GAME_STATS_I_BLOCK_TEXT[G_GAME_STATS_NUM_LENGTH + 1];
			static char G_GAME_STATS_J_BLOCK_TEXT[G_GAME_STATS_NUM_LENGTH + 1];
			static char G_GAME_STATS_L_BLOCK_TEXT[G_GAME_STATS_NUM_LENGTH + 1];
			static char G_GAME_STATS_O_BLOCK_TEXT[G_GAME_STATS_NUM_LENGTH + 1];
			static char G_GAME_STATS_S_BLOCK_TEXT[G_GAME_STATS_NUM_LENGTH + 1];
			static char G_GAME_STATS_T_BLOCK_TEXT[G_GAME_STATS_NUM_LENGTH + 1];
			static char G_GAME_STATS_Z_BLOCK_TEXT[G_GAME_STATS_NUM_LENGTH + 1];

			static unsigned short G_GAME_STATS_I_BLOCK_COUNT = 0;
			static unsigned short G_GAME_STATS_J_BLOCK_COUNT = 0;
			static unsigned short G_GAME_STATS_L_BLOCK_COUNT = 0;
			static unsigned short G_GAME_STATS_O_BLOCK_COUNT = 0;
			static unsigned short G_GAME_STATS_S_BLOCK_COUNT = 0;
			static unsigned short G_GAME_STATS_T_BLOCK_COUNT = 0;
			static unsigned short G_GAME_STATS_Z_BLOCK_COUNT = 0;

			static vec2 G_GAME_STATS_BOX_POSITION;
			static vec2 G_GAME_STATS_BOX_SCALE;

			static vec2 G_GAME_STATS_TITLE_TEXT_POSITION;
			static vec2 G_GAME_STATS_TITLE_TEXT_SCALE;

			static vec2 G_GAME_STATS_ELEMENT_TEXT_CHAR_SCALE;

			static vec2 G_GAME_STATS_I_ELEMENT_TEXT_POSITION;
			static vec2 G_GAME_STATS_J_ELEMENT_TEXT_POSITION;
			static vec2 G_GAME_STATS_L_ELEMENT_TEXT_POSITION;
			static vec2 G_GAME_STATS_O_ELEMENT_TEXT_POSITION;
			static vec2 G_GAME_STATS_S_ELEMENT_TEXT_POSITION;
			static vec2 G_GAME_STATS_T_ELEMENT_TEXT_POSITION;
			static vec2 G_GAME_STATS_Z_ELEMENT_TEXT_POSITION;

			static vec2 G_GAME_STATS_I_ELEMENT_BLOCK_POSITION;
			static vec2 G_GAME_STATS_J_ELEMENT_BLOCK_POSITION;
			static vec2 G_GAME_STATS_L_ELEMENT_BLOCK_POSITION;
			static vec2 G_GAME_STATS_O_ELEMENT_BLOCK_POSITION;
			static vec2 G_GAME_STATS_S_ELEMENT_BLOCK_POSITION;
			static vec2 G_GAME_STATS_T_ELEMENT_BLOCK_POSITION;
			static vec2 G_GAME_STATS_Z_ELEMENT_BLOCK_POSITION;

	//GAME---------------------------------------------------------------------------------------------------------
		#define G_GAME_MAXIMUM_SCORE 9999999

		static unsigned int G_GAME_SCORE = 0;

		//Grid - MOVE ALL GRID FUNCTIONALITY TO SEPERATE FILE
			#define G_GRID_CELL_COUNT 6
		
			typedef unsigned char BlockData;

			/*
				Data Format:	    [Bit 8]---   000				00				000   ---[Bit 0]
												 |-|				||				|-|
											  color bits       rotation bits	 type bits
			*/

			typedef struct {
				vec2 position;
				BlockData data;
			} Piece;


			static const float G_GRID_OUTLINE_THICKNESS = SCR_WIDTH / (float)150;
			
			/*
			Column-major grid that represents blocks placed onto the grid

			g_grid[GRID X POSITION][GRID Y POSITION] = (HORIZONTAL COORDINATE, VERTICAL COORDINATE) of block
			*/
			static BlockData g_grid[G_GRID_CELL_COUNT][2 * G_GRID_CELL_COUNT];
			
			static Piece g_falling;

			static float G_GRID_CELL_SIZE;

			static vec2 G_GRID_POSITION;
			static vec2 G_GRID_LOWER_LEFT;
			static vec2 G_GRID_SCALE;

			static vec2 G_GRID_OUTLINE_SCALE;

//General----------------------------------------------------------------------------------------------------------

	#define SECONDS_PER_UPDATE 0.1

	#define GAME_STATE_TITLE 0
	#define GAME_STATE_PLAY 1

	#define GAME_FALSE 0
	#define GAME_TRUE 1

	#define G_COLOR_COUNT 8

	#define G_I_BLOCK 1	
	#define G_J_BLOCK 2 
	#define G_L_BLOCK 3 
	#define G_O_BLOCK 4 
	#define G_S_BLOCK 5 
	#define G_T_BLOCK 6 
	#define G_Z_BLOCK 7 

	static unsigned char g_state = GAME_STATE_TITLE;

	static vec3* g_colors[G_COLOR_COUNT];

	static const vec3 G_COLOR_BLUE = { 0.000f, 0.827f, 1.000f };
	static const vec3 G_COLOR_YELLOW = { 1.000f, 0.984f, 0.000f };
	static const vec3 G_COLOR_RED = { 1.000f, 0.388f, 0.388f };
	static const vec3 G_COLOR_GREEN = { 0.388f, 1.000f, 0.510f };
	static const vec3 G_COLOR_ORANGE = { 0.988f, 0.647f, 0.000f };
	static const vec3 G_COLOR_PINK = { 1.000f, 0.682f, 0.957f };
	static const vec3 G_COLOR_PURPLE = { 0.659f, 0.157f, 1.000f };
	static const vec3 G_COLOR_TEAL = { 0.000f, 1.000f, 0.761f };

	static const vec3 G_COLOR_WHITE = { 1.0f, 1.0f, 1.0f };
	static const vec3 G_COLOR_GRAY = { 0.472f, 0.472f, 0.472f };

//-----------------------------------------------------------------------------------------------------------------

void g_init();

void g_update(float deltaTime);

static void g_updateTitle(float udt);
static void g_updatePlay(float udt);

void g_render();

static void g_drawGrid();

static void g_drawGridLines();

void g_changeState(unsigned char destinationState);

void g_increaseScore(unsigned int additionalScore);

void g_incrementStat(unsigned char block);

vec2i g_screenToGrid(vec2 screenCords);

vec2 g_gridToScreen(unsigned int gridX, unsigned int gridY);

#endif