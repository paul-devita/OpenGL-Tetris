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

void g_initState() {

}

void g_update(float deltaTime) {
	static float updateTimer = 0;

	updateTimer += deltaTime;

	if (updateTimer >= SECONDS_PER_UPDATE) {
		switch (state) {
			case GAME_STATE_TITLE:
				g_updateTitle(updateTimer);
				break;
			case GAME_STATE_PLAY:

				break;
			case GAME_STATE_PAUSED:

				break;
			case GAME_STATE_OVER:

				break;
		}

		updateTimer = 0;
	}
}

static void g_updateTitle(float dt) {
	static float pressStartTimer = G_START_ANIMATION_INTERVAL_UP;

	pressStartTimer -= dt;

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

void g_render() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	switch (state) {
		case GAME_STATE_TITLE: {
			//Render Title
			tp_drawString(G_START_TITLE_POSITION, G_START_TITLE_CHAR_SCALE, G_START_TEXT_COLOR, G_START_TITLE_THICKNESS, G_START_TITLE_SPACING, 0, TP_ALIGNMENT_CENTER, G_START_TITLE_TEXT);

			if (g_start_pressStartToggle)
				tp_drawString(G_START_PRESS_POSITION, G_START_PRESS_CHAR_SCALE, G_START_TEXT_COLOR, G_START_PRESS_THICKNESS, G_START_PRESS_SPACING, 0, TP_ALIGNMENT_CENTER, G_START_PRESS_TEXT);
		}
	}
}