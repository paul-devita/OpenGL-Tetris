#include "game.h"

void g_init() {
	//UI
	ui_init();
	//Grid
	gr_init();
	//Block
	b_init();
	//Piece
	p_init();

	//General
	g_currentPieceType = g_getRandomPiece();
	p_createPiece(&g_currentPiece, &g_pieceStartPos, g_currentPieceType, G_FALSE);
	p_translate(&g_currentPiece, -p_getPieceWidth(g_currentPiece.data) / 2, 0);
	g_incrementStat(g_currentPieceType);

	g_nextPiece = g_getRandomPiece();
	ui_setNextPiece(g_nextPiece);

	g_heldPiece = P_NULL;
	ui_setHeldPiece(g_heldPiece);
}

void g_reset() {
	//Reset Score

	//Reset Levels

	//Reset Lines Cleared Indices

	//Reset Grid

	//Reset UI

	//Run General Init Functionality To Init Game State for next Run
}

void g_update(float deltaTime) {
	if (g_gameHalted) {
		switch (g_haltReason) {
			case G_HALT_CLEARED_LINE: {
				const float PHASE_DURATION = 0.5f;
				const unsigned char MAX_NUM_PHASES = 4;

				static unsigned char numOfPhases = 0;

				static unsigned char phaseToggle = G_FALSE;
				static unsigned char whitePhaseTriggered = G_FALSE;
				static unsigned char colorPhaseTriggered = G_FALSE;

				static float phaseTimer = 0;

				phaseTimer += deltaTime;

				if (numOfPhases >= MAX_NUM_PHASES) {
					unsigned char numRowsCompleted = 0;

					//Sort indices so they are in descending order
					for (int i = 0; i < G_MAXIMUM_LINES_CLEARABLE; i++) {
						int maxIndex = i;

						for (int j = i + 1; j < G_MAXIMUM_LINES_CLEARABLE; j++) {
							if (g_completeLinesIndices[j] > g_completeLinesIndices[maxIndex]) {
								maxIndex = j;
							}
						}

						short temp = g_completeLinesIndices[i];

						g_completeLinesIndices[i] = g_completeLinesIndices[maxIndex];
						g_completeLinesIndices[maxIndex] = temp;
					}

					//Get num of rows completed
					for (int i = 0; i < G_MAXIMUM_LINES_CLEARABLE; i++) {
						if (g_completeLinesIndices[i] != G_NULL_INDEX) {
							//Add 1 to number of rows
							numRowsCompleted++;

							//Delete the row and shift the grid
							short row = g_completeLinesIndices[i];

							gr_deleteRowAndShift(row);

							g_completeLinesIndices[i] = G_NULL_INDEX;
						}
						else {
							break;
						}
					}

					//Update lines cleared
					g_linesCleared += numRowsCompleted;

					//Update Level and Difficulty
					unsigned char newLevel = g_linesCleared / 10;

					if (newLevel != g_level) {
						g_level = newLevel;

						if (g_level >= 1 && g_level <= 10) {
							g_fallingTimer -= 4;
						}
						else if (g_level == 13 || g_level == 16 || g_level == 19 || g_level == 24 || g_level == 29) {
							g_fallingTimer -= 4;
						}
					}

					//Update score
					unsigned int additionalScore = 0;

					switch (numRowsCompleted) {
					case 1:
						additionalScore = 40 * (g_level + 1);
						break;
					case 2:
						additionalScore = 100 * (g_level + 1);
						break;
					case 3:
						additionalScore = 300 * (g_level + 1);
						break;
					case 4:
						additionalScore = 1200 * (g_level + 1);
						break;
					default:
						printf("WARNING: invalid number of lines cleared\n");
						break;
					}

					g_increaseScore(additionalScore);

					phaseToggle = G_FALSE;
					whitePhaseTriggered = G_FALSE;
					colorPhaseTriggered = G_FALSE;

					phaseTimer = 0;
					numOfPhases = 0;

					g_gameHalted = G_FALSE;

					g_halt(G_HALT_CHANGING_PIECE);

					return;
				}

				if (!phaseToggle) {
					if (!whitePhaseTriggered) {
						for (int i = 0; i < G_MAXIMUM_LINES_CLEARABLE; i++) {
							if (g_completeLinesIndices[i] != -1) {
								short yVal = g_completeLinesIndices[i];

								for (int x = 0; x < G_GRID_CELL_COUNT; x++) {
									vec2s p;

									p.x = x;
									p.y = yVal;

									gr_updateGrid(&p, COLOR_INDEX_WHITE);
								}
							}
						}

						whitePhaseTriggered = G_TRUE;
					}

					if (phaseTimer >= PHASE_DURATION) {
						phaseToggle = G_TRUE;
						whitePhaseTriggered = G_FALSE;

						numOfPhases++;
						phaseTimer = 0;
					}
				}
				else {
					if (!colorPhaseTriggered) {
						for (int i = 0; i < G_MAXIMUM_LINES_CLEARABLE; i++) {
							if (g_completeLinesIndices[i] != -1) {
								short yVal = g_completeLinesIndices[i];

								for (int x = 0; x < G_GRID_CELL_COUNT; x++) {
									unsigned char color = g_completeLinesData[i][x];

									vec2s p;

									p.x = x;
									p.y = yVal;

									gr_updateGrid(&p, color);
								}
							}
						}

						colorPhaseTriggered = G_TRUE;
					}

					if (phaseTimer >= PHASE_DURATION) {
						phaseToggle = G_FALSE;
						colorPhaseTriggered = G_FALSE;

						numOfPhases++;
						phaseTimer = 0;
					}
				}

				break;
			}
			case G_HALT_CHANGING_PIECE: {
				const float CHANGING_PIECE_DURATION = 0.5f;

				static float haltTimer = 0;

				haltTimer += deltaTime;

				if (haltTimer >= CHANGING_PIECE_DURATION) {
					g_cycleNextPiece();

					haltTimer = 0;
					g_gameHalted = G_FALSE;
				}

				return;
			}
			default:
				printf("WARNING: invalid halt reason, resuming game\n");
				return;
		}
	}

	g_processGameInput();
}

void g_fixedUpdate(float deltaTime) {
	if (g_gameHalted) {

		return;
	}

	switch (g_checkBelowCurrentPiece()) {
		//Unobstructed, continue to move piece downward
		case G_TRUE: {
			unsigned char fallingDelay = g_fallingDelay;

			if (g_fastFallToggle)
				fallingDelay = 0;

			g_placingTimer = 0;
			g_fallingTimer++;

			if (g_fallingTimer >= fallingDelay) {
				p_translate(&g_currentPiece, 0, -1);
				g_fallingTimer = 0;

				if (g_fastFallToggle) {
					unsigned int additionalScore = 1;

					g_increaseScore(additionalScore);
				}
			}

			break;
		}
		//Obstructed, begin piece placement
		case G_FALSE: {
			unsigned char placingDelay = g_placingDelay;

			g_fallingTimer = 0;
			g_placingTimer++;

			if (g_placingTimer >= placingDelay) {
				unsigned char width = p_getPieceWidth(g_currentPiece.data);
				unsigned char height = p_getPieceHeight(g_currentPiece.data);

				unsigned char color = p_getPieceColor(g_currentPiece.data);

				//Copy pieces to grid
				for (int x = 0; x < width; x++) {
					for (int y = 0; y < height; y++) {
						unsigned char block = p_getBlockAt(&g_currentPiece, x, y);

						if (block) {
							vec2s gridPos;

							gridPos.x = g_currentPiece.position.x + x;
							gridPos.y = g_currentPiece.position.y - y;

							gr_updateGrid(&gridPos, color);
						}
					}
				}

				//"remove" current piece
				g_currentPiece.blocks = 0x00; // 0000 0000

				//Find any completed rows (if they exist)
				unsigned char completeLinesFound = G_FALSE;
				unsigned char curIndex = 0;

				for (int y = 0; y < 2 * G_GRID_CELL_COUNT; y++) {
					for (int x = 0; x < G_GRID_CELL_COUNT; x++) {
						vec2s p;

						p.x = x;
						p.y = y;

						if (gr_checkGridPos(&p) == GR_NULL_ELEMENT) {
							break;
						}
						else if (x == G_GRID_CELL_COUNT - 1) {
							completeLinesFound = G_TRUE;
							g_completeLinesIndices[curIndex] = y;

							for (int i = 0; i < G_GRID_CELL_COUNT; i++) {
								p.x = i;

								g_completeLinesData[curIndex][i] = gr_checkGridPos(&p);
							}

							curIndex++;
							break;
						}
					}
				}

				//Decide what to do next
				if (completeLinesFound) {
					g_halt(G_HALT_CLEARED_LINE);
				}
				else {
					g_halt(G_HALT_CHANGING_PIECE);
				}

				g_placingTimer = 0;
			}

			break;
		}
	}
}

void g_render() {
	//Render UI
	ui_render();

	//Render Grid
	gr_drawGridUI();
	gr_drawGridContents();

	//Render Game
	if (g_currentPiece.data != P_NULL)
		p_draw(&g_currentPiece);
}

void g_halt(unsigned char reason) {
	g_gameHalted = G_TRUE;

	g_haltReason = reason;
}

unsigned char g_getRandomPiece() {
	unsigned char randomPiece = r_randomIntInRange(0, P_PIECE_COUNT);

	return randomPiece;
}

unsigned char g_checkBelowCurrentPiece() {
	unsigned char height = p_getPieceHeight(g_currentPiece.data);
	unsigned char width = p_getPieceWidth(g_currentPiece.data);

	if (g_currentPiece.position.y - height < 0) {
		return G_FALSE;
	}

	for (short x = 0; x < width; x++) {
		unsigned char lowestY = 0;

		for (short y = height - 1; y >= 0; y--) {
			if (p_getBlockAt(&g_currentPiece, x, y)) {
				lowestY = y;
				break;
			}
		}

		vec2s gridPos;

		gridPos.x = g_currentPiece.position.x + x;
		gridPos.y = g_currentPiece.position.y - lowestY - 1;

		unsigned char gridVal = gr_checkGridPos(&gridPos);

		if (gridVal != GR_NULL_ELEMENT) {
			return G_FALSE;
		}
	}

	return G_TRUE;
}

void g_cycleNextPiece() {
	g_currentPieceType = g_nextPiece;
	p_createPiece(&g_currentPiece, &g_pieceStartPos, g_currentPieceType, G_FALSE);
	p_translate(&g_currentPiece, -p_getPieceWidth(g_currentPiece.data) / 2, 0);

	g_incrementStat(g_currentPieceType);

	g_nextPiece = g_getRandomPiece();
	ui_setNextPiece(g_nextPiece);
}

void g_holdPiece() {
	if (g_heldPiece == P_NULL) {
		g_heldPiece = g_currentPieceType;
		ui_setHeldPiece(g_heldPiece);

		g_cycleNextPiece();

		return;
	}
	else {
		unsigned char temp = g_heldPiece;

		g_heldPiece = g_currentPieceType;
		g_currentPieceType = temp;

		p_createPiece(&g_currentPiece, &g_pieceStartPos, g_currentPieceType, G_FALSE);
		ui_setHeldPiece(g_heldPiece);
	}
}

void g_rotateFallingPiece() {
	Piece newPiece = g_currentPiece;

	p_rotate(&newPiece);

	unsigned char width = p_getPieceWidth(newPiece.data);
	unsigned char height = p_getPieceHeight(newPiece.data);

	//x-value checks
	if (newPiece.position.x < 0) {
		newPiece.position.x = 0;
	}
	if (newPiece.position.x + width >= G_GRID_CELL_COUNT) {
		newPiece.position.x = G_GRID_CELL_COUNT - width;
	}

	//y-value checks
	if (!g_checkBelowCurrentPiece() && (newPiece.position.y - height >= 0 || newPiece.position.y - height < 0)) {
		newPiece.position.y = height - 1;
	}
	if (newPiece.position.y >= 2 * G_GRID_CELL_COUNT) {
		newPiece.position.y = (2 * G_GRID_CELL_COUNT) - 1;
	}

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			unsigned char block = p_getBlockAt(&newPiece, x, y);

			if (block) {
				vec2s pos;

				pos.x = newPiece.position.x + x;
				pos.y = newPiece.position.y - y;

				unsigned char gridVal = gr_checkGridPos(&pos);

				if (gridVal != GR_NULL_ELEMENT)
					return;
			}
		}
	}

	g_currentPiece = newPiece;
}

void g_horizontalFallingPieceMovement(unsigned char direction) {
	short dx;

	switch (direction) {
		case G_LEFT:
			dx = -1;
			break;
		case G_RIGHT:
			dx = 1;
			break;
		default:
			printf("WARNING: invalid direction passed to g_horizontalFallingPieceMovement\n");
			return;
	}

	unsigned char width = p_getPieceWidth(g_currentPiece.data);
	unsigned char height = p_getPieceHeight(g_currentPiece.data);

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			unsigned char block = p_getBlockAt(&g_currentPiece, x, y);

			if (block) {
				vec2s pos;

				pos.x = g_currentPiece.position.x + x + dx;
				pos.y = g_currentPiece.position.y - y;

				unsigned char gridVal = gr_checkGridPos(&pos);

				if (gridVal != GR_NULL_ELEMENT)
					return;
			}
		}
	}

	p_translate(&g_currentPiece, dx, 0);
}

void g_increaseScore(unsigned int additionalScore) {
	if (g_score + additionalScore >= G_MAXIMUM_SCORE) {
		g_score = G_MAXIMUM_SCORE;
	}
	else {
		g_score += additionalScore;
	}

	ui_updateScoreText(g_score);
}

void g_incrementStat(unsigned char blockType) {
	if (g_stats[blockType] + 1 > G_MAXIMUM_STATS) {
		g_stats[blockType] = (unsigned short)G_MAXIMUM_STATS;
	}
	else {
		g_stats[blockType]++;
	}

	ui_updateStatsText(blockType, g_stats[blockType]);
}

void g_processGameInput() {
	//Set if a key is down, held, or up
	static unsigned char rKey = 0;
	static unsigned char eKey = 0;
	static unsigned char wKey = 0;
	static unsigned char sKey = 0;
	static unsigned char aKey = 0;
	static unsigned char dKey = 0;

	//R Key
	if (!rKey && win_checkKey(GLFW_KEY_R)) {
		//Key Down Event
		g_rotateFallingPiece();

		rKey = G_TRUE;
	}
	else if (rKey && win_checkKey(GLFW_KEY_R)) {
		//Key Held Event
	}
	else if (rKey && !win_checkKey(GLFW_KEY_R)) {
		//Key Up Event

		rKey = G_FALSE;
	}

	//E Key
	if (!eKey && win_checkKey(GLFW_KEY_E)) {
		//Key Down Event
		g_holdPiece();

		eKey = G_TRUE;
	}
	else if (eKey && win_checkKey(GLFW_KEY_E)) {
		//Key Held Event
	}
	else if (eKey && !win_checkKey(GLFW_KEY_E)) {
		//Key Up Event

		eKey = G_FALSE;
	}

	//W Key
	if (!wKey && win_checkKey(GLFW_KEY_W)) {
		//Key Down Event

		wKey = G_TRUE;
	}
	else if (wKey && win_checkKey(GLFW_KEY_W)) {
		//Key Held Event
	}
	else if (wKey && !win_checkKey(GLFW_KEY_W)) {
		//Key Up Event

		wKey = G_FALSE;
	}

	//S Key
	if (!sKey && win_checkKey(GLFW_KEY_S)) {
		//Key Down Event
		g_fastFallToggle = G_TRUE;

		sKey = G_TRUE;
	}
	else if (sKey && win_checkKey(GLFW_KEY_S)) {
		//Key Held Event
	}
	else if (sKey && !win_checkKey(GLFW_KEY_S)) {
		//Key Up Event
		g_fastFallToggle = G_FALSE;

		sKey = G_FALSE;
	}

	//A Key
	if (!aKey && win_checkKey(GLFW_KEY_A)) {
		//Key Down Event

		g_horizontalFallingPieceMovement(G_LEFT);

		aKey = G_TRUE;
	}
	else if (aKey && win_checkKey(GLFW_KEY_A)) {
		//Key Held Event
	}
	else if (aKey && !win_checkKey(GLFW_KEY_A)) {
		//Key Up Event

		aKey = G_FALSE;
	}

	//D Key
	if (!dKey && win_checkKey(GLFW_KEY_D)) {
		//Key Down Event

		g_horizontalFallingPieceMovement(G_RIGHT);

		dKey = G_TRUE;
	}
	else if (dKey && win_checkKey(GLFW_KEY_D)) {
		//Key Held Event
	}
	else if (dKey && !win_checkKey(GLFW_KEY_D)) {
		//Key Up Event

		dKey = G_FALSE;
	}
}