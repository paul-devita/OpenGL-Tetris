#ifndef _UI_H_
#define _UI_H_

#include "../math/vec2.h"

#include "../render/type.h"
#include "../render/color.h"

#include "../util/window.h"

#include "piece.h"

//UI-----------------------------------------------------------------------------------------------------------

static const float UI_BOX_THICKNESS = SCR_WIDTH / 150.0;

static const float UI_TEXT_HEIGHT = SCR_HEIGHT / 40.0;

static const float UI_TEXT_THICKNESS_STANDARD = SCR_WIDTH / 350.0;
static const float UI_TEXT_THICKNESS_BOLD = SCR_WIDTH / 250.0;

static const float UI_TEXT_CHAR_SPACING = SCR_WIDTH / 200.0;

//Score Box-----------------------------------------------------------------
#define UI_GAME_SCORE_TEXT_LENGTH 7

static const char* UI_SCORE_TITLE_TEXT = "score";

static char UI_GAME_SCORE_TEXT[UI_GAME_SCORE_TEXT_LENGTH + 1];

static vec2 UI_SCORE_BOX_POSITION;
static vec2 UI_SCORE_BOX_SCALE;

static vec2 UI_SCORE_TITLE_TEXT_POSITION;
static vec2 UI_SCORE_TITLE_TEXT_SCALE;

static vec2 UI_SCORE_TEXT_POSITION;
static vec2 UI_SCORE_TEXT_SCALE;

//Next Box------------------------------------------------------------------
static const char* UI_NEXT_TITLE_TEXT = "next";

static vec2 UI_NEXT_BOX_POSITION;
static vec2 UI_NEXT_BOX_SCALE;

static vec2 UI_NEXT_TITLE_TEXT_POSITION;
static vec2 UI_NEXT_TITLE_TEXT_SCALE;

static vec2 UI_NEXT_BLOCK_POSITION;

static float UI_NEXT_PIECE_SIZE;

static unsigned char ui_nextPiece = P_NULL;

//Hold Box------------------------------------------------------------------
static const char* UI_HOLD_TITLE_TEXT = "hold";

static vec2 UI_HOLD_BOX_POSITION;
static vec2 UI_HOLD_BOX_SCALE;

static vec2 UI_HOLD_TITLE_TEXT_POSITION;
static vec2 UI_HOLD_TITLE_TEXT_SCALE;

static vec2 UI_HOLD_BLOCK_POSITION;

static float UI_HOLD_PIECE_SIZE;

static unsigned char ui_heldPiece = P_NULL;

//Stats Box-----------------------------------------------------------------
#define UI_STATS_NUM_LENGTH 4

static const char* UI_STATS_TITLE_TEXT = "stats";

static const float UI_STATS_ELEMENT_SPACING = SCR_HEIGHT / 64.0;

static const vec2 UI_STATS_ELEMENT_SCALE = { (3 * SCR_WIDTH) / 20.0, (9 * (SCR_HEIGHT / 2.0)) / 112.0 - (6 * SCR_HEIGHT / 64.0) / 7.0 };

static float UI_STATS_ELEMENT_BLOCK_SIZE;

static char UI_STATS_I_BLOCK_TEXT[UI_STATS_NUM_LENGTH + 1];
static char UI_STATS_J_BLOCK_TEXT[UI_STATS_NUM_LENGTH + 1];
static char UI_STATS_L_BLOCK_TEXT[UI_STATS_NUM_LENGTH + 1];
static char UI_STATS_O_BLOCK_TEXT[UI_STATS_NUM_LENGTH + 1];
static char UI_STATS_S_BLOCK_TEXT[UI_STATS_NUM_LENGTH + 1];
static char UI_STATS_T_BLOCK_TEXT[UI_STATS_NUM_LENGTH + 1];
static char UI_STATS_Z_BLOCK_TEXT[UI_STATS_NUM_LENGTH + 1];

static unsigned short UI_STATS_I_BLOCK_COUNT = 0;
static unsigned short UI_STATS_J_BLOCK_COUNT = 0;
static unsigned short UI_STATS_L_BLOCK_COUNT = 0;
static unsigned short UI_STATS_O_BLOCK_COUNT = 0;
static unsigned short UI_STATS_S_BLOCK_COUNT = 0;
static unsigned short UI_STATS_T_BLOCK_COUNT = 0;
static unsigned short UI_STATS_Z_BLOCK_COUNT = 0;

static vec2 UI_STATS_BOX_POSITION;
static vec2 UI_STATS_BOX_SCALE;

static vec2 UI_STATS_TITLE_TEXT_POSITION;
static vec2 UI_STATS_TITLE_TEXT_SCALE;

static vec2 UI_STATS_ELEMENT_TEXT_CHAR_SCALE;

static vec2 UI_STATS_I_ELEMENT_TEXT_POSITION;
static vec2 UI_STATS_J_ELEMENT_TEXT_POSITION;
static vec2 UI_STATS_L_ELEMENT_TEXT_POSITION;
static vec2 UI_STATS_O_ELEMENT_TEXT_POSITION;
static vec2 UI_STATS_S_ELEMENT_TEXT_POSITION;
static vec2 UI_STATS_T_ELEMENT_TEXT_POSITION;
static vec2 UI_STATS_Z_ELEMENT_TEXT_POSITION;

static vec2 UI_STATS_I_ELEMENT_BLOCK_POSITION;
static vec2 UI_STATS_J_ELEMENT_BLOCK_POSITION;
static vec2 UI_STATS_L_ELEMENT_BLOCK_POSITION;
static vec2 UI_STATS_O_ELEMENT_BLOCK_POSITION;
static vec2 UI_STATS_S_ELEMENT_BLOCK_POSITION;
static vec2 UI_STATS_T_ELEMENT_BLOCK_POSITION;
static vec2 UI_STATS_Z_ELEMENT_BLOCK_POSITION;

void ui_init();

void ui_render();

void ui_setNextPiece(unsigned char newNext);
void ui_setHeldPiece(unsigned char newHeld);

void ui_updateScoreText(unsigned int score);

void ui_updateStatsText(unsigned char blockType, unsigned short stat);

#endif