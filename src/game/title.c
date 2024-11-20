#include "title.h"

void ti_init() {
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

	G_START_PRESS_CHAR_SCALE.x = (G_START_PRESS_WIDTH - (G_START_PRESS_TEXT_LENGTH - 1) * G_START_PRESS_SPACING) / (float)G_START_PRESS_TEXT_LENGTH;
	G_START_PRESS_CHAR_SCALE.y = G_START_PRESS_HEIGHT;
}

void ti_update(float udt) {
	static float pressStartTimer = G_START_ANIMATION_INTERVAL_UP / 2.0;

	pressStartTimer -= udt;

	if (pressStartTimer <= 0) {
		if (g_start_pressStartToggle) {
			pressStartTimer = G_START_ANIMATION_INTERVAL_DOWN;
			g_start_pressStartToggle = U_FALSE;
		}
		else {
			pressStartTimer = G_START_ANIMATION_INTERVAL_UP;
			g_start_pressStartToggle = U_TRUE;
		}
	}

	ti_proccessInput();
}

void ti_proccessInput() {
	if (win_checkKey(GLFW_KEY_ENTER)) {
		sm_changeState(SM_STARTING_STATE);
	}

	if (win_checkKey(GLFW_KEY_ESCAPE)) {
		win_close();
	}
}

void ti_render() {
	//Render Title
	tp_drawString(G_START_TITLE_POSITION, G_START_TITLE_CHAR_SCALE, COLOR_WHITE, G_START_TITLE_THICKNESS, G_START_TITLE_SPACING, TP_NO_SPACING, TP_ALIGNMENT_CENTER, G_START_TITLE_TEXT);

	//Render Press Start
	if (g_start_pressStartToggle)
		tp_drawString(G_START_PRESS_POSITION, G_START_PRESS_CHAR_SCALE, COLOR_WHITE, G_START_PRESS_THICKNESS, G_START_PRESS_SPACING, TP_NO_SPACING, TP_ALIGNMENT_CENTER, G_START_PRESS_TEXT);

}
