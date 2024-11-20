#include "starting.h"

void st_update(float deltaTime) {
	st_startingTimer -= deltaTime;

	char startingNum = (int)st_startingTimer + '0';

	G_STARTING_COUNTDOWN_TEXT[0] = startingNum;

	if (st_startingTimer <= 1) {
		sm_changeState(SM_GAME_STATE);
		st_startingTimer = STARTING_COUNTDOWN_TIME + 1;
	}
}

void st_render() {
	tp_drawString(G_STARTING_COUNTDOWN_POSITION, G_STARTING_COUNTDOWN_CHAR_SCALE, COLOR_WHITE, G_STARTING_COUNTDOWN_THICKNESS, TP_NO_SPACING, TP_NO_SPACING, TP_ALIGNMENT_CENTER, G_STARTING_COUNTDOWN_TEXT);
}