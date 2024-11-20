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

static Piece g_falling;


void g_init();

void g_reset();

void g_update(float deltaTime);
void g_fixedUpdate(float updateDt);

void g_render();

static void g_processGameInput();

static void g_rotateFallingPiece();
static void g_horizontalFallingPieceMovement(unsigned char direction);

void g_increaseScore(unsigned int additionalScore);

void g_incrementStat(unsigned char block);

#endif