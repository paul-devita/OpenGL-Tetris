#include "game.h"

const float G_END_GAME_BLOCK_SIZE = SCR_WIDTH / (float)(sizeof(unsigned char) * 8);

const vec2 G_END_GAME_BLOCKS_START = { (SCR_WIDTH / (float)(sizeof(unsigned char) * 8)) / (float)2, 0 };

const unsigned int G_END_GAME_BLOCKS_VERTICAL_COUNT = SCR_HEIGHT / (float)(SCR_WIDTH / (float)(sizeof(unsigned char) * 8));

void g_init() {

	//UI
	ui_init();
	//Grid
	gr_init();
	//Block
	b_init();
	//Piece
	p_init();

	//Init Score
	g_score = 0;

	//Init Stats
	for (int i = 0; i < G_STATS_COUNT; i++) {
		g_stats[i] = 0;
	}

	//Init Completing Lines
	for (int i = 0; i < G_MAXIMUM_LINES_CLEARABLE; i++) {
		g_completeLinesIndices[i] = G_NULL_INDEX;
	}

	g_linesCleared = 0;
	g_level = 0;

	//Init Game Halts
	g_gameHalted = G_FALSE;

	//Init Falling Variables
	g_fallingDelay = 60;
	g_fallingTimer = 0;

	g_fastFallToggle = G_FALSE;

	g_placingDelay = 60;
	g_placingTimer = 0;

	//Init Falling Piece
	g_currentPieceType = g_getRandomPiece();
	p_createPiece(&g_currentPiece, &g_pieceStartPos, g_currentPieceType, G_FALSE);
	p_translate(&g_currentPiece, -p_getPieceWidth(g_currentPiece.data) / 2, 0);
	g_incrementStat(g_currentPieceType);

	//Init Next Piece
	g_nextPiece = g_getRandomPiece();
	ui_setNextPiece(g_nextPiece);

	//Init Held Piece
	g_heldPiece = P_NULL;
	ui_setHeldPiece(g_heldPiece);

	//Game Over Functionality
	g_endGameBlocks = (unsigned char*)malloc(G_END_GAME_BLOCKS_VERTICAL_COUNT * sizeof(unsigned char));
	if (g_endGameBlocks == NULL) {
		printf("ERROR: out of memory\n");
		exit(-1);
	}
	memset(g_endGameBlocks, 0, G_END_GAME_BLOCKS_VERTICAL_COUNT * sizeof(unsigned char));

	g_endGameMinIndex = 0;
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
							g_fallingDelay -= 4;
						}
						else if (g_level == 13 || g_level == 16 || g_level == 19 || g_level == 24 || g_level == 29) {
							g_fallingDelay -= 4;
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

				return;
			}

			case G_HALT_CHANGING_PIECE: {
				const float CHANGING_PIECE_DURATION = 0.5f;

				static float haltTimer = 0;

				haltTimer += deltaTime;

				if (haltTimer >= CHANGING_PIECE_DURATION) {
					haltTimer = 0;
					g_gameHalted = G_FALSE;

					g_cycleNextPiece();
				}

				return;
			}

			case G_HALT_GAME_END: {
				const float PHASE1_WAITING_INTERVAL = 1.0f;
				const float PHASE2_ANIMATION_INTERVAL = 0.1f;

				const float PHASE2_ENDING_INTERVAL = 1.0f;

				static unsigned char phase1Finished = G_FALSE;

				static float haltTimer = 0;

				static unsigned int curIndex = 0;

				haltTimer += deltaTime;

				if (!phase1Finished && haltTimer >= PHASE1_WAITING_INTERVAL) {
					haltTimer = 0;
					phase1Finished = G_TRUE;
				}

				if (phase1Finished && curIndex >= G_END_GAME_BLOCKS_VERTICAL_COUNT && haltTimer >= PHASE2_ENDING_INTERVAL) {
					g_gameHalted = G_FALSE;
					haltTimer = 0;
					curIndex = 0;

					memset(g_endGameBlocks, 0, G_END_GAME_BLOCKS_VERTICAL_COUNT * sizeof(unsigned char));

					//Go to End Game Screen
					sm_changeState(SM_OVER_STATE);
				}
				else if (phase1Finished && curIndex < G_END_GAME_BLOCKS_VERTICAL_COUNT && haltTimer >= PHASE2_ANIMATION_INTERVAL) {
					unsigned int minRow = curIndex;
					unsigned int maxRow = G_END_GAME_BLOCKS_VERTICAL_COUNT - 1 - curIndex;

					unsigned char mask = 0x01;

					for (int i = 0; i < (int)(sizeof(unsigned char) * 8); i++) {
						if (i % 2 == 0) {
							g_endGameBlocks[minRow] |= mask;
						}
						else {
							g_endGameBlocks[maxRow] |= mask;
						}

						mask <<= 1;
					}

					haltTimer = 0;
					curIndex++;
				}

				return;
			}

			default:
				printf("WARNING: invalid halt reason, resuming game\n");
				g_gameHalted = G_FALSE;
				return;
		}
	}

	g_processGameInput(deltaTime);
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

	//Render Game Over
	if (g_gameHalted && g_haltReason == G_HALT_GAME_END) {
		for (int i = 0; i < G_END_GAME_BLOCKS_VERTICAL_COUNT; i++) {
			unsigned char mask = 0x01;
			unsigned char row = g_endGameBlocks[i];

			for (int j = 0; j < (int)(sizeof(unsigned char) * 8); j++) {
				unsigned char value = row & mask;

				if (value) {
					vec2 pos;

					pos.x = G_END_GAME_BLOCKS_START.x + (j * G_END_GAME_BLOCK_SIZE);
					pos.y = G_END_GAME_BLOCKS_START.y + (i * G_END_GAME_BLOCK_SIZE);

					b_drawDummyBlock(&pos, G_END_GAME_BLOCK_SIZE, COLOR_INDEX_WHITE);
				}

				mask <<= 1;
			}
		}
	}
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

	//Choose and initialize next piece
	g_currentPieceType = g_nextPiece;
	p_createPiece(&g_currentPiece, &g_pieceStartPos, g_currentPieceType, G_FALSE);

	unsigned char width = p_getPieceWidth(g_currentPiece.data);
	unsigned char height = p_getPieceHeight(g_currentPiece.data);

	p_translate(&g_currentPiece, -(width / 2), 0);

	g_incrementStat(g_currentPieceType);

	g_nextPiece = g_getRandomPiece();
	ui_setNextPiece(g_nextPiece);

	//Check if new pieces starts on any existing pieces
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			unsigned char block = p_getBlockAt(&g_currentPiece, x, y);

			if (block) {
				vec2s pos;

				pos.x = g_currentPiece.position.x + x;
				pos.y = g_currentPiece.position.y - y;

				if (gr_checkGridPos(&pos) != GR_NULL_ELEMENT) {
					g_halt(G_HALT_GAME_END);
					return;
				}
			}
		}
	}
}

void g_holdPiece() {
	if (!g_checkBelowCurrentPiece())
		return;

	Piece newPiece;

	if (g_heldPiece == P_NULL) {
		p_createPiece(&newPiece, &g_currentPiece.position, g_nextPiece, G_FALSE);
	}
	else {
		p_createPiece(&newPiece, &g_currentPiece.position, g_heldPiece, G_FALSE);
	}

	unsigned char newWidth = p_getPieceWidth(newPiece.data);
	unsigned char newHeight = p_getPieceHeight(newPiece.data);

	if (newPiece.position.x < 0) {
		newPiece.position.x = 0;
	}
	if (newPiece.position.x + newWidth >= G_GRID_CELL_COUNT) {
		newPiece.position.x = G_GRID_CELL_COUNT - newWidth;
	}

	for (int x = 0; x < newWidth; x++) {
		for (int y = 0; y < newHeight; y++) {
			unsigned char block = p_getBlockAt(&newPiece, x, y);

			if (block) {
				vec2s gridPos;

				gridPos.x = newPiece.position.x + x;
				gridPos.y = newPiece.position.y - y;

				unsigned char gridVal = gr_checkGridPos(&gridPos);

				if (gridVal != GR_NULL_ELEMENT)
					return;
			}
		}
	}

	if (g_heldPiece == P_NULL) {
		g_heldPiece = g_currentPieceType;
		ui_setHeldPiece(g_heldPiece);

		g_currentPieceType = g_nextPiece;
		g_incrementStat(g_currentPieceType);

		g_nextPiece = g_getRandomPiece();
		ui_setNextPiece(g_nextPiece);
	}
	else {
		unsigned char temp = g_heldPiece;

		g_heldPiece = g_currentPieceType;
		g_currentPieceType = temp;

		ui_setHeldPiece(g_heldPiece);
	}

	g_currentPiece = newPiece;
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

	//check all valid blocks
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
	if (blockType >= G_STATS_COUNT) return;

	if (g_stats[blockType] + 1 > G_MAXIMUM_STATS) {
		g_stats[blockType] = (unsigned short)G_MAXIMUM_STATS;
	}
	else {
		g_stats[blockType]++;
	}

	ui_updateStatsText(blockType, g_stats[blockType]);
}

void g_processGameInput(float deltaTime) {
	static const float HORIZONTAL_MOVE_FRAME_DELAY = 0.3f;

	static float horizontalMoveTimer = 0;

	//Set if a key is down, held, or up
	static unsigned char rKey = 0;
	static unsigned char eKey = 0;
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

		horizontalMoveTimer += deltaTime;

		if (horizontalMoveTimer >= HORIZONTAL_MOVE_FRAME_DELAY) {
			g_horizontalFallingPieceMovement(G_LEFT);
			horizontalMoveTimer = HORIZONTAL_MOVE_FRAME_DELAY / (float)2;
		}
	}
	else if (aKey && !win_checkKey(GLFW_KEY_A)) {
		//Key Up Event

		horizontalMoveTimer = 0;

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
		
		horizontalMoveTimer += deltaTime;

		if (horizontalMoveTimer >= HORIZONTAL_MOVE_FRAME_DELAY) {
			g_horizontalFallingPieceMovement(G_RIGHT);
			horizontalMoveTimer = HORIZONTAL_MOVE_FRAME_DELAY / (float)2;
		}
	}
	else if (dKey && !win_checkKey(GLFW_KEY_D)) {
		//Key Up Event

		horizontalMoveTimer = 0;

		dKey = G_FALSE;
	}
}