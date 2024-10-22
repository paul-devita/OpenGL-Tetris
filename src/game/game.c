#include "game.h"

void g_init() {
	//Start State
		//Init Title Values
		for (unsigned char* c = G_START_TITLE_TEXT; *c != TP_NULL; c++, G_START_TITLE_TEXT_LENGTH++) {}
	
		G_START_TITLE_WIDTH = 3 * SCR_WIDTH / 4.0;
		G_START_TITLE_HEIGHT = SCR_HEIGHT / 5.0;
		G_START_TITLE_SPACING = G_START_TITLE_WIDTH / 32.0;

		G_START_TITLE_POSITION.x = SCR_WIDTH / 2.0;
		G_START_TITLE_POSITION.y = 3 * SCR_HEIGHT / 10.0;

		G_START_TITLE_CHAR_SCALE.x = (G_START_TITLE_WIDTH - (G_START_TITLE_TEXT_LENGTH - 1) * G_START_TITLE_SPACING) / G_START_TITLE_TEXT_LENGTH;
		G_START_TITLE_CHAR_SCALE.y = G_START_TITLE_HEIGHT;

		//Init Press Values
		for (unsigned char* c = G_START_PRESS_TEXT; *c != TP_NULL; c++, G_START_PRESS_TEXT_LENGTH++) {}

		G_START_PRESS_WIDTH = SCR_WIDTH / 2;
		G_START_PRESS_HEIGHT = SCR_HEIGHT / 30.0;
		G_START_PRESS_SPACING = G_START_PRESS_WIDTH / 32.0;

		G_START_PRESS_POSITION.x = SCR_WIDTH / 2.0;
		G_START_PRESS_POSITION.y = 2 * SCR_HEIGHT / 3.0;

		G_START_PRESS_CHAR_SCALE.x = (G_START_PRESS_WIDTH - (G_START_PRESS_TEXT_LENGTH - 1) * G_START_PRESS_SPACING) / G_START_PRESS_TEXT_LENGTH;
		G_START_PRESS_CHAR_SCALE.y = G_START_PRESS_HEIGHT;

	//Game State
		//UI
			//Score Box
				//Box
				G_GAME_SCORE_BOX_POSITION.x = 7 * SCR_WIDTH / 8.0;
				G_GAME_SCORE_BOX_POSITION.y = 7 * SCR_HEIGHT / 10.0;
		
				G_GAME_SCORE_BOX_SCALE.x = SCR_WIDTH / 5.0;
				G_GAME_SCORE_BOX_SCALE.y = SCR_HEIGHT / 2.0;

				//Title
				for (unsigned char* c = G_GAME_SCORE_TITLE_TEXT; *c != TP_NULL; c++, G_GAME_SCORE_TITLE_TEXT_LENGTH++) {}

				float G_GAME_SCORE_TEXT_TITLE_CHAR_WIDTH = (3 * G_GAME_SCORE_BOX_SCALE.x) / (4.0 * G_GAME_SCORE_TITLE_TEXT_LENGTH) - ((G_GAME_SCORE_TITLE_TEXT_LENGTH - 1) * G_GAME_SCORE_TEXT_CHAR_SPACING) / G_GAME_SCORE_TITLE_TEXT_LENGTH;

				G_GAME_SCORE_TITLE_TEXT_POSITION.x = G_GAME_SCORE_BOX_POSITION.x;
				G_GAME_SCORE_TITLE_TEXT_POSITION.y = G_GAME_SCORE_BOX_POSITION.y - 3 * G_GAME_SCORE_BOX_SCALE.y / 8.0;

				G_GAME_SCORE_TITLE_TEXT_SCALE.x = G_GAME_SCORE_TEXT_TITLE_CHAR_WIDTH;
				G_GAME_SCORE_TITLE_TEXT_SCALE.y = G_GAME_SCORE_BOX_SCALE.y / 20.0;

				
			
			//Next Box
			G_GAME_NEXT_BOX_POSITION.x = 7 * SCR_WIDTH / 8.0;
			G_GAME_NEXT_BOX_POSITION.y = 9 * SCR_HEIGHT / 40.0;

			G_GAME_NEXT_BOX_SCALE.x = SCR_WIDTH / 5.0;
			G_GAME_NEXT_BOX_SCALE.y = 7 * SCR_HEIGHT / 20.0;

			//Hold Box
			G_GAME_HOLD_BOX_POSITION.x = SCR_WIDTH / 8.0;
			G_GAME_HOLD_BOX_POSITION.y = 9 * SCR_HEIGHT / 40.0;

			G_GAME_HOLD_BOX_SCALE.x = SCR_WIDTH / 5.0;
			G_GAME_HOLD_BOX_SCALE.y = 7 * SCR_HEIGHT / 20.0;

			//Stats Box
			G_GAME_STATS_BOX_POSITION.x = SCR_WIDTH / 8.0;
			G_GAME_STATS_BOX_POSITION.y = 7 * SCR_HEIGHT / 10.0;

			G_GAME_STATS_BOX_SCALE.x = SCR_WIDTH / 5.0;
			G_GAME_STATS_BOX_SCALE.y = SCR_HEIGHT / 2.0;

			//Game Box
			G_GAME_GAME_BOX_POSITION.x = SCR_WIDTH / 2.0;
			G_GAME_GAME_BOX_POSITION.y = SCR_HEIGHT / 2.0;

			G_GAME_GAME_BOX_SCALE.x = SCR_WIDTH / 2.0;
			G_GAME_GAME_BOX_SCALE.y = 9 * SCR_HEIGHT / 10.0;

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
	static float pressStartTimer = G_START_ANIMATION_INTERVAL_UP;

	pressStartTimer -= udt;

	if (pressStartTimer <= 0) {
		if (g_start_pressStartToggle) {
			pressStartTimer = G_START_ANIMATION_INTERVAL_DOWN;
			g_start_pressStartToggle = GAME_FALSE;
		}
		else {
			pressStartTimer = G_START_ANIMATION_INTERVAL_UP;
			g_start_pressStartToggle = GAME_TRUE;
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

}

void g_render() {
	win_clear();
	
	switch (g_state) {
		case GAME_STATE_TITLE:
			//Render Title
			tp_drawString(G_START_TITLE_POSITION, G_START_TITLE_CHAR_SCALE, G_COLOR_WHITE, G_START_TITLE_THICKNESS, G_START_TITLE_SPACING, 0, TP_ALIGNMENT_CENTER, G_START_TITLE_TEXT);

			//Render Press Start
			if (g_start_pressStartToggle)
				tp_drawString(G_START_PRESS_POSITION, G_START_PRESS_CHAR_SCALE, G_COLOR_WHITE, G_START_PRESS_THICKNESS, G_START_PRESS_SPACING, 0, TP_ALIGNMENT_CENTER, G_START_PRESS_TEXT);
			
			break;
		case GAME_STATE_PLAY:
			//Render UI
				//Score
					qd_drawOutlineRect(G_GAME_SCORE_BOX_POSITION, G_GAME_SCORE_BOX_SCALE, G_GAME_BOX_THICKNESS, G_COLOR_WHITE);

					tp_drawString(G_GAME_SCORE_TITLE_TEXT_POSITION, G_GAME_SCORE_TITLE_TEXT_SCALE, G_COLOR_WHITE, G_GAME_SCORE_TITLE_TEXT_THICKNESS, G_GAME_SCORE_TEXT_CHAR_SPACING, 0, TP_ALIGNMENT_CENTER, G_GAME_SCORE_TITLE_TEXT);

				//Next
				qd_drawOutlineRect(G_GAME_NEXT_BOX_POSITION, G_GAME_NEXT_BOX_SCALE, G_GAME_BOX_THICKNESS, G_COLOR_WHITE);
				qd_drawOutlineRect(G_GAME_HOLD_BOX_POSITION, G_GAME_HOLD_BOX_SCALE, G_GAME_BOX_THICKNESS, G_COLOR_WHITE);
				qd_drawOutlineRect(G_GAME_STATS_BOX_POSITION, G_GAME_STATS_BOX_SCALE, G_GAME_BOX_THICKNESS, G_COLOR_WHITE);
				qd_drawOutlineRect(G_GAME_GAME_BOX_POSITION, G_GAME_GAME_BOX_SCALE, G_GAME_GAME_BOX_THICKNESS, G_COLOR_WHITE);
				
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