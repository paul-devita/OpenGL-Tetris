#include "game.h"


void g_init() {

}

void g_processInput(float deltaTime) {

}

void g_update(float deltaTime) {
	static float updateTimer = 0;

	updateTimer += deltaTime;

	if (updateTimer >= SECONDS_PER_UPDATE) {
		switch (state) {
			case GAME_STATE_TITLE:

				break;
			case GAME_STATE_PLAY:

				break;
			case GAME_STATE_PAUSED:

				break;
			case GAME_STATE_OVER:

				break;
		}
	}
}

static void g_UpdateTitle(float dt) {
	//Animate press start alpha values

	//Look for enter key press or escape key press

	//Proceed to next game state
}

void g_render() {
	glClear(GL_COLOR_BUFFER_BIT);

}