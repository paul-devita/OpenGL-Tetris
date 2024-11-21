#include "grid.h"

const float GRID_CELL_SIZE = ((9 * SCR_WIDTH) / (float)20) / (float)G_GRID_CELL_COUNT;

void gr_init() {
	for (int x = 0; x < G_GRID_CELL_COUNT; x++)
		for (int y = 0; y < 2 * G_GRID_CELL_COUNT; y++)
			gr_grid[x][y] = GR_NULL_ELEMENT; // 11111111

	GRID_POSITION.x = SCR_WIDTH / (float)2;
	GRID_POSITION.y = SCR_HEIGHT / (float)2;

	GRID_SCALE.x = (9 * SCR_WIDTH) / (float)20;
	GRID_SCALE.y = 2 * GRID_SCALE.x;

	GRID_LOWER_LEFT.x = GRID_POSITION.x - (GRID_SCALE.x / (float)2);
	GRID_LOWER_LEFT.y = GRID_POSITION.y + (GRID_SCALE.x);

	GRID_OUTLINE_SCALE.x = GRID_SCALE.x + 2 * GRID_OUTLINE_THICKNESS;
	GRID_OUTLINE_SCALE.y = GRID_SCALE.y + 2 * GRID_OUTLINE_THICKNESS;
}

void gr_drawGridUI() {
	qd_drawOutlineRect(GRID_POSITION, GRID_OUTLINE_SCALE, GRID_OUTLINE_THICKNESS, COLOR_WHITE);
}

void gr_drawGridContents() {
	vec2s gridPos;

	int yMax = 2 * G_GRID_CELL_COUNT;

	for (int x = 0; x < G_GRID_CELL_COUNT; x++) {
		for (int y = 0; y < yMax; y++) {
			unsigned char gridElement = gr_grid[x][y];

			if (gridElement != GR_NULL_ELEMENT) {
				gridPos.x = x;
				gridPos.y = y;

				vec2 p = gr_gridToScreen(&gridPos);

				b_drawBlock(&p, gridElement);
			}
		}
	}
}

void gr_drawGridLines() {
	const float width = SCR_WIDTH / 400.0;

	vec2 p, s;

	float dx;
	float dy;

	if (G_GRID_CELL_COUNT % 2 == 0) {
		dx = 0;
		dy = 0;
	}
	else {
		dx = GRID_CELL_SIZE / (float)2;
		dy = GRID_CELL_SIZE / (float)2;
	}

	s.x = width;
	s.y = GRID_SCALE.y;

	p.y = GRID_POSITION.y;

	for (int i = 0; i < G_GRID_CELL_COUNT / 2; i++) {
		p.x = GRID_POSITION.x + dx;

		qd_drawSolidRect(p, s, 0, COLOR_GRAY);

		if (dx != 0) {
			p.x = GRID_POSITION.x - dx;

			qd_drawSolidRect(p, s, 0, COLOR_GRAY);
		}

		dx += GRID_CELL_SIZE;
	}

	s.x = GRID_SCALE.x;
	s.y = width;

	p.x = GRID_POSITION.x;

	for (int i = 0; i < G_GRID_CELL_COUNT; i++) {
		p.y = GRID_POSITION.y + dy;

		qd_drawSolidRect(p, s, 0, COLOR_GRAY);

		if (dy != 0) {
			p.y = GRID_POSITION.y - dy;

			qd_drawSolidRect(p, s, 0, COLOR_GRAY);
		}

		dy += GRID_CELL_SIZE;
	}
}

vec2 gr_gridToScreen(vec2s* pos) {
	vec2 result;

	float sized2 = GRID_CELL_SIZE / (float)2;

	result.x = GRID_LOWER_LEFT.x + sized2 + pos->x * GRID_CELL_SIZE;
	result.y = GRID_LOWER_LEFT.y - sized2 - pos->y * GRID_CELL_SIZE;

	return result;
}

unsigned char gr_checkGridPos(vec2s* pos) {
	short x = pos->x;
	short y = pos->y;

	unsigned char val = gr_grid[x][y];

	return val;
}

void gr_updateGrid(vec2s* gridPos, unsigned char data) {
	short x = gridPos->x;
	short y = gridPos->y;

	gr_grid[x][y] = data;
}

void gr_deleteRowAndShift(short row) {
	short gridHeight = 2 * G_GRID_CELL_COUNT;

	for (int r = row + 1; r < gridHeight; r++) {
		for (int x = 0; x < G_GRID_CELL_COUNT; x++) {
			gr_grid[x][r - 1] = gr_grid[x][r];
		}
	}

	for (int x = 0; x < G_GRID_CELL_COUNT; x++) {
		gr_grid[x][gridHeight - 1] = GR_NULL_ELEMENT;
	}
}