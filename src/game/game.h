#ifndef _GAME_H_
#define _GAME_H_

#include "../util/window.h"
#include "../util/random.h"

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

#define G_MAXIMUM_SCORE 9999999

#define G_MAXIMUM_STATS 9999

#define SECONDS_PER_UPDATE 0.1

#define G_FALSE 0
#define G_TRUE 1

#define G_LEFT 0
#define G_RIGHT 1

#define G_COLOR_COUNT 8

static unsigned int g_score = 0;

static unsigned short g_stats[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

static const vec2s g_pieceStartPos = { G_GRID_CELL_COUNT / (float)2, (2 * G_GRID_CELL_COUNT) - 2 };

static unsigned char g_currentPieceType;
static Piece g_currentPiece;

static unsigned char g_nextPiece;
static unsigned char g_heldPiece = P_NULL;

void g_init();

void g_reset();

void g_update(float deltaTime);
void g_fixedUpdate(float updateDt);

void g_render();

unsigned char g_getRandomPiece();

void g_cycleNextPiece();

void g_holdPiece();

void g_rotateFallingPiece();
void g_horizontalFallingPieceMovement(unsigned char direction);

void g_increaseScore(unsigned int additionalScore);

void g_incrementStat(unsigned char block);

void g_processGameInput();

#endif