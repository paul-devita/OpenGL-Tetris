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

	vec2s p = { 5, 0 };

	gr_updateGrid(&p, 4);

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

}

void g_update(float deltaTime) {
	if (g_gameHalted) {
		static float haltTimer = 0;

		haltTimer += deltaTime;

		switch (g_haltReason) {
			case G_HALT_CLEARED_LINE: {
				


				break;
			}
			case G_HALT_CHANGING_PIECE: {
				const float CHANGING_PIECE_DURATION = 0.5f;

				if (haltTimer >= CHANGING_PIECE_DURATION) {
					g_cycleNextPiece();

					haltTimer = 0;
					g_gameHalted = G_FALSE;
				}

				break;
			}
			default:
				printf("WARNING: invalid halt reason, resuming game\n");
				break;
		}

		return;
	}

	g_processGameInput();
}

void g_fixedUpdate(float deltaTime) {
	if (g_gameHalted) {

		return;
	}

	switch (g_checkBelowCurrentPiece()) {
		case G_TRUE: {
			unsigned char fallingDelay = g_fallingDelay;

			if (g_fastFallToggle)
				fallingDelay = g_fastFallDelay;

			g_placingTimer = 0;
			g_fallingTimer++;

			if (g_fallingTimer >= fallingDelay) {
				p_translate(&g_currentPiece, 0, -1);
				g_fallingTimer = 0;
			}

			break;
		}
		case G_FALSE:
			g_fallingTimer = 0;
			g_placingTimer++;

			if (g_placingTimer >= g_placingDelay) {
				unsigned char width = p_getPieceWidth(g_currentPiece.data);
				unsigned char height = p_getPieceHeight(g_currentPiece.data);

				unsigned char color = p_getPieceColor(g_currentPiece.data);

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

				g_currentPiece.blocks = 0x00; // 0000 0000

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
							curIndex++;
							break;
						}
					}
				}

				unsigned char reason;

				if (completeLinesFound) {
					reason = G_HALT_CLEARED_LINE;
				}
				else {
					reason = G_HALT_CHANGING_PIECE;
				}

				g_halt(reason);

				g_placingTimer = 0;
			}

			break;
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

	if (newPiece.position.x < 0) {
		newPiece.position.x = 0;
	}
	if (newPiece.position.x + width >= G_GRID_CELL_COUNT) {
		newPiece.position.x = G_GRID_CELL_COUNT - width;
	}

	if (!g_checkBelowCurrentPiece() && (newPiece.position.y - height >= 0 || newPiece.position.y - height < 0)) {
		newPiece.position.y = height - 1;
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