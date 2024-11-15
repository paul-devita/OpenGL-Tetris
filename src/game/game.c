#include "game.h"

void g_init() {
	//Start State
		//Init Title Values
		unsigned int G_START_TITLE_TEXT_LENGTH = 0;
		
		for (unsigned char* c = G_START_TITLE_TEXT; *c != TP_NULL; c++, G_START_TITLE_TEXT_LENGTH++) {}
	
		G_START_TITLE_WIDTH = 3 * SCR_WIDTH / 4.0;
		G_START_TITLE_HEIGHT = SCR_HEIGHT / 5.0;
		G_START_TITLE_SPACING = G_START_TITLE_WIDTH / 32.0;

		G_START_TITLE_POSITION.x = SCR_WIDTH / 2.0;
		G_START_TITLE_POSITION.y = 3 * SCR_HEIGHT / 10.0;

		G_START_TITLE_CHAR_SCALE.x = (G_START_TITLE_WIDTH - (G_START_TITLE_TEXT_LENGTH - 1) * G_START_TITLE_SPACING) / G_START_TITLE_TEXT_LENGTH;
		G_START_TITLE_CHAR_SCALE.y = G_START_TITLE_HEIGHT;

		//Init Press Values
		unsigned int G_START_PRESS_TEXT_LENGTH = 0;

		for (unsigned char* c = G_START_PRESS_TEXT; *c != TP_NULL; c++, G_START_PRESS_TEXT_LENGTH++) {}

		G_START_PRESS_WIDTH = SCR_WIDTH / 2;
		G_START_PRESS_HEIGHT = SCR_HEIGHT / 30.0;
		G_START_PRESS_SPACING = G_START_PRESS_WIDTH / 32.0;

		G_START_PRESS_POSITION.x = SCR_WIDTH / 2.0;
		G_START_PRESS_POSITION.y = 2 * SCR_HEIGHT / 3.0;

		G_START_PRESS_CHAR_SCALE.x = (G_START_PRESS_WIDTH - (G_START_PRESS_TEXT_LENGTH - 1) * G_START_PRESS_SPACING) / (float) G_START_PRESS_TEXT_LENGTH;
		G_START_PRESS_CHAR_SCALE.y = G_START_PRESS_HEIGHT;

	//UI
		ui_init();
	//Grid
		gr_init();
	//Block
		b_init();
	//Piece
		p_init();

	//Game State
		//General

		vec2s p = { 5, 5 };

		p_createPiece(&g_falling, &p, P_I_PIECE, G_FALSE);


}

void g_update(float deltaTime) {
	static float updateDeltaTime = 0;

	updateDeltaTime += deltaTime;

	if (updateDeltaTime >= SECONDS_PER_UPDATE) {
		switch (g_state) {
			case GAME_STATE_TITLE:
				g_updateTitle(updateDeltaTime);
				break;
			case GAME_STATE_PLAY:
				g_updatePlay(updateDeltaTime);
				break;
			default:
				printf("ERROR: invalid game state\n");
				win_close();
				break;
		}

		updateDeltaTime = 0;
	}
}

static void g_updateTitle(float udt) {
	static float pressStartTimer = G_START_ANIMATION_INTERVAL_UP / 2.0;

	pressStartTimer -= udt;

	if (pressStartTimer <= 0) {
		if (g_start_pressStartToggle) {
			pressStartTimer = G_START_ANIMATION_INTERVAL_DOWN;
			g_start_pressStartToggle = G_FALSE;
		}
		else {
			pressStartTimer = G_START_ANIMATION_INTERVAL_UP;
			g_start_pressStartToggle = G_TRUE;
		}
	}

	if (win_checkKey(GLFW_KEY_ENTER)) {
		g_changeState(GAME_STATE_PLAY);
	}

	if (win_checkKey(GLFW_KEY_ESCAPE)) {
		win_close();
	}
}

static void g_updatePlay(float udt) {
	if (win_checkKey(GLFW_KEY_R)) {
		p_rotate(&g_falling);
	}


	if(win_checkKey(GLFW_KEY_W)) {
		p_translate(&g_falling, 0, 1);
	}
	else if (win_checkKey(GLFW_KEY_S)) {
		p_translate(&g_falling, 0, -1);
	}
	else if (win_checkKey(GLFW_KEY_D)) {
		p_translate(&g_falling, 1, 0);
	}
	else if (win_checkKey(GLFW_KEY_A)) {
		p_translate(&g_falling, -1, 0);
	}
}

void g_render() {
	win_clear();
	
	switch (g_state) {
		case GAME_STATE_TITLE:
			//Render Title
			tp_drawString(G_START_TITLE_POSITION, G_START_TITLE_CHAR_SCALE, COLOR_WHITE, G_START_TITLE_THICKNESS, G_START_TITLE_SPACING, TP_NO_SPACING, TP_ALIGNMENT_CENTER, G_START_TITLE_TEXT);

			//Render Press Start
			if (g_start_pressStartToggle)
				tp_drawString(G_START_PRESS_POSITION, G_START_PRESS_CHAR_SCALE, COLOR_WHITE, G_START_PRESS_THICKNESS, G_START_PRESS_SPACING, TP_NO_SPACING, TP_ALIGNMENT_CENTER, G_START_PRESS_TEXT);
			
			break;
		case GAME_STATE_PLAY:
			//Render UI
				ui_render();
			
			//Render Grid
				gr_drawGridUI();
				gr_drawGridContents();

			//Render Game
				p_draw(&g_falling);

			break;
	}
}

void g_changeState(unsigned char destinationState) {
	switch (g_state) {
		case GAME_STATE_TITLE:
			switch (destinationState) {
				case GAME_STATE_PLAY:
					g_state = GAME_STATE_PLAY;
					break;
				default:
					printf("WARNING: invalid state transition attempted\n");
					break;
			}
		case GAME_STATE_PLAY:
			switch (destinationState) {
				default:
					printf("WARNING: invalid state transition attempted\n");
					break;
			}
		default:
			printf("WARNING: invalid state provided\n");
			break;
	}
}

void g_increaseScore(unsigned int additionalScore) {
	static unsigned int score = 0;

	if (score + additionalScore >= G_MAXIMUM_SCORE) {
		score = G_MAXIMUM_SCORE;
	}
	else {
		score += additionalScore;
	}

	ui_updateScoreText(score);
}

void g_incrementStat(unsigned char blockType) {
	static unsigned short stats[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

	if (stats[blockType] + 1 > G_MAXIMUM_STATS) {
		stats[blockType] = (unsigned short)G_MAXIMUM_STATS;
	}
	else {
		stats[blockType]++;
	}

	ui_updateStatsText(blockType, stats[blockType]);
}