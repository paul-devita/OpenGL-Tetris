#include "stateManager.h"

void sm_init() {
	//Init Title
	ti_init();

	//Init Game
	g_init();
}

void sm_update(float deltaTime) {
	switch (SM_STATE) {
		case SM_TITLE_STATE:
			ti_update(deltaTime);
			return;
		case SM_STARTING_STATE:
			st_update(deltaTime);
			return;
		case SM_GAME_STATE:
			g_update(deltaTime);
			return;
		case SM_PAUSE_STATE:

			return;
		default:
		
			return;
	}
}

void sm_fixedUpdate(float deltaTime) {
	static const float fixedRate = 1 / (float)SM_TPS;
	static float fixedUpdateTime = 0;

	fixedUpdateTime += deltaTime;

	if (fixedUpdateTime >= fixedRate) {
		fixedUpdateTime = 0;

		switch (SM_STATE) {
			case SM_TITLE_STATE:

				return;
			case SM_STARTING_STATE:

				return;
			case SM_GAME_STATE:
				g_fixedUpdate(fixedUpdateTime);
				return;
			case SM_PAUSE_STATE:

				return;
			default:

				return;
		}
	}
}

void sm_render() {
	win_clear();

	switch (SM_STATE) {
		case SM_TITLE_STATE:
			ti_render();
			return;
		case SM_STARTING_STATE:
			st_render();
			return;
		case SM_GAME_STATE:
			g_render();
			return;
		case SM_PAUSE_STATE:

			return;
		default:

			return;
	}
}

void sm_changeState(State newState) {
	switch (SM_STATE) {
		case SM_TITLE_STATE:
			if (newState == SM_STARTING_STATE) {
				SM_STATE = SM_STARTING_STATE;
			}
			else {
				printf("WARNING: invalid state change attempted\n");
			}

			return;
		case SM_STARTING_STATE:
			if (newState == SM_GAME_STATE) {
				g_reset();
				SM_STATE = SM_GAME_STATE;
			}
			else {
				printf("WARNING: invalid state change attempted\n");
			}

			return;
		case SM_GAME_STATE:
			if (newState == SM_PAUSE_STATE) {
				SM_STATE = SM_PAUSE_STATE;
			}
			else {
				printf("WARNING: invalid state change attempted\n");
			}

			return;
		case SM_PAUSE_STATE:
			if (newState == SM_GAME_STATE) {
				SM_STATE = SM_GAME_STATE;
			}
			else if (newState == SM_STARTING_STATE) {
				SM_STATE = SM_STARTING_STATE;
			}
			else if (newState == SM_TITLE_STATE) {
				SM_STATE = SM_TITLE_STATE;
			}
			else {
				printf("WARNING: invalid state change attempted\n");
			}

			return;
		default:

			return;
	}
}