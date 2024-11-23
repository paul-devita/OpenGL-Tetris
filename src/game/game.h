#ifndef _GAME_H_
#define _GAME_H_

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

#include "../util/window.h"
#include "../util/random.h"

#include "../math/mat4.h"

#include "../render/shader.h"
#include "../render/texture.h"
#include "../render/quad.h"
#include "../render/type.h"
#include "../render/color.h"

#include "stateManager.h"

#include "block.h"
#include "grid.h"
#include "piece.h"
#include "ui.h"

//General Game Functionality
#define G_MAXIMUM_SCORE 9999999

#define G_MAXIMUM_STATS 9999

#define G_FALSE 0
#define G_TRUE 1

#define G_LEFT 0
#define G_RIGHT 1

#define G_DOWN 0
#define G_UP 1

#define G_COLOR_COUNT 8

static unsigned int g_score = 0;

static unsigned short g_stats[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

//Completing Lines
#define G_MAXIMUM_LINES_CLEARABLE 4
#define G_NULL_INDEX -1
static short g_completeLinesIndices[] = { G_NULL_INDEX, G_NULL_INDEX, G_NULL_INDEX, G_NULL_INDEX };
static unsigned char g_completeLinesData[4][G_GRID_CELL_COUNT];

//Game Halts
#define G_HALT_CLEARED_LINE 0
#define G_HALT_CHANGING_PIECE 1
#define G_HALT_GAME_END 2
static unsigned char g_gameHalted = G_FALSE;
static unsigned char g_haltReason;
static float g_haltDuration;

//Falling Piece
static const vec2s g_pieceStartPos = { G_GRID_CELL_COUNT / (float)2, (2 * G_GRID_CELL_COUNT) - 2 };

static unsigned char g_currentPieceType;
static Piece g_currentPiece;

static unsigned char g_nextPiece;
static unsigned char g_heldPiece = P_NULL;

static unsigned char g_fallingDelay = 60;
static unsigned char g_fallingTimer = 0;

static unsigned char g_fastFallToggle = G_FALSE;

static unsigned char g_placingDelay = 60;
static unsigned char g_placingTimer = 0;

static unsigned int g_linesCleared = 0;
static unsigned char g_level;

//Game Over Functionality
static const float G_END_GAME_BLOCK_SIZE = SCR_WIDTH / (float)(sizeof(unsigned char) * 8);

static vec2 g_endGameStart;

static unsigned int g_endGameBlocksHeight;

static unsigned int g_endGameMinIndex = 0;

static unsigned char* g_endGameBlocks;

void g_init();

void g_reset();

void g_update(float deltaTime);
void g_fixedUpdate(float updateDt);

void g_render();

void g_halt(unsigned char reason);

unsigned char g_getRandomPiece();

/*Returns G_FALSE if there is an obstruction(placed piece or bottom of grid) directly below the Piece
Returns G_TRUE if there are no obstructions present below the piece*/
unsigned char g_checkBelowCurrentPiece();

void g_cycleNextPiece();
void g_holdPiece();

void g_rotateFallingPiece();
void g_horizontalFallingPieceMovement(unsigned char direction);

void g_increaseScore(unsigned int additionalScore);

void g_incrementStat(unsigned char block);

void g_processGameInput();

#endif