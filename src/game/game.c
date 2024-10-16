#include "game.h"

void g_init() {
	//Init Title Values
	G_START_TITLE_WIDTH = 3 * SCR_WIDTH / 4.0;
	G_START_TITLE_HEIGHT = SCR_HEIGHT / 5.0;
	G_START_TITLE_SPACING = G_START_TITLE_WIDTH / 32.0;
	
	G_START_TITLE_POSITION.x = SCR_WIDTH / 2.0;
	G_START_TITLE_POSITION.y = 3 * SCR_HEIGHT / 10.0;

	G_START_TITLE_CHAR_SCALE.x = (G_START_TITLE_WIDTH - (G_START_TITLE_TEXT_LENGTH - 1) * G_START_TITLE_SPACING) / G_START_TITLE_TEXT_LENGTH;
	G_START_TITLE_CHAR_SCALE.y = G_START_TITLE_HEIGHT;

	//Init Press Values
	G_START_PRESS_WIDTH = SCR_WIDTH / 2;
	G_START_PRESS_HEIGHT = SCR_HEIGHT / 30.0;
	G_START_PRESS_SPACING = G_START_PRESS_WIDTH / 32.0;
	
	G_START_PRESS_POSITION.x = SCR_WIDTH / 2.0;
	G_START_PRESS_POSITION.y = 2 * SCR_HEIGHT / 3.0;

	G_START_PRESS_CHAR_SCALE.x = (G_START_PRESS_WIDTH - (G_START_PRESS_TEXT_LENGTH - 1) * G_START_PRESS_SPACING) / G_START_PRESS_TEXT_LENGTH;
	G_START_PRESS_CHAR_SCALE.y = G_START_PRESS_HEIGHT;
}

void g_update(float deltaTime) {
	static float updateDeltaTime = 0;

	updateDeltaTime += deltaTime;

	if (updateDeltaTime >= SECONDS_PER_UPDATE) {
		switch (state) {
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

	}

	if (win_checkKey(GLFW_KEY_ESCAPE)) {
		win_close();
	}
}

static void g_updatePlay(float udt) {

}

void g_render() {
	win_clear();
	
	switch (state) {
		case GAME_STATE_TITLE:
			//Render Title
			tp_drawString(G_START_TITLE_POSITION, G_START_TITLE_CHAR_SCALE, G_START_TEXT_COLOR, G_START_TITLE_THICKNESS, G_START_TITLE_SPACING, 0, TP_ALIGNMENT_CENTER, G_START_TITLE_TEXT);

			//Render Press Start
			if (g_start_pressStartToggle)
				tp_drawString(G_START_PRESS_POSITION, G_START_PRESS_CHAR_SCALE, G_START_TEXT_COLOR, G_START_PRESS_THICKNESS, G_START_PRESS_SPACING, 0, TP_ALIGNMENT_CENTER, G_START_PRESS_TEXT);
			
			break;
		case GAME_STATE_PLAY:

			break;
	}
}

void g_changeState(float destinationState) {

}