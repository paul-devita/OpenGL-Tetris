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

}

void g_update(float deltaTime) {
	g_processGameInput();

}

void g_fixedUpdate(float deltaTime) {
	static float updateDeltaTime = 0;

	updateDeltaTime += deltaTime;

	if (updateDeltaTime >= SECONDS_PER_UPDATE) {
		static unsigned char fallingInterval = 4;
		static unsigned char fallingTimer = 0;

		updateDeltaTime = 0;
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

unsigned char g_getRandomPiece() {
	unsigned char randomPiece = r_randomIntInRange(0, P_PIECE_COUNT);

	return randomPiece;
}

void g_cycleNextPiece() {
	g_currentPieceType = g_nextPiece;
	p_createPiece(&g_currentPiece, &g_pieceStartPos, g_currentPieceType, G_FALSE);

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

		sKey = G_TRUE;
	}
	else if (sKey && win_checkKey(GLFW_KEY_S)) {
		//Key Held Event
	}
	else if (sKey && !win_checkKey(GLFW_KEY_S)) {
		//Key Up Event

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