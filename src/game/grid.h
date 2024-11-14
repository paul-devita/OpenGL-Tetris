#ifndef _GRID_H_
#define _GRID_H_

#include "../math/vec2.h"

#include "../util/window.h"

#include "../render/color.h"

#include "block.h"

#define G_GRID_CELL_COUNT 12
#define GR_NULL_ELEMENT 0xFF

/*
Column-major grid that represents blocks placed onto the grid

g_grid[GRID X POSITION][GRID Y POSITION] = (HORIZONTAL COORDINATE, VERTICAL COORDINATE) of block
*/
static unsigned char grid[G_GRID_CELL_COUNT][2 * G_GRID_CELL_COUNT];

extern const float GRID_CELL_SIZE;

static vec2 GRID_POSITION;
static vec2 GRID_LOWER_LEFT;
static vec2 GRID_SCALE;

static vec2 GRID_OUTLINE_SCALE;

static const float GRID_OUTLINE_THICKNESS = SCR_WIDTH / (float)150;

void gr_init();

void gr_drawGridUI();

void gr_drawGridContents();

void gr_drawGridLines();

vec2 gr_gridToScreen(vec2s* pos);

void gr_updateGrid(unsigned int grX, unsigned int grY, unsigned char data);

#endif