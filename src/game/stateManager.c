#include "stateManager.h"

void sm_init() {
	//Init Title
	ti_init();

	//Init Game
	g_init();

	//Init Game Over
	go_init();

	//Init Game Paused
	gp_init();
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
			gp_update(deltaTime);
			return;
		case SM_OVER_STATE:
			go_update(deltaTime);
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
			case SM_OVER_STATE:

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
			gp_render();
			return;
		case SM_OVER_STATE:
			go_render();
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
				SM_STATE = SM_GAME_STATE;
			}
			else {
				printf("WARNING: invalid state change attempted\n");
			}

			return;
		case SM_GAME_STATE:
			switch (newState) {
				case SM_PAUSE_STATE:
					SM_STATE = SM_PAUSE_STATE;
					break;
				case SM_OVER_STATE:
					SM_STATE = SM_OVER_STATE;
					break;
				default:
					printf("WARNING: invalid state change attempted\n");
			}

			return;
		case SM_PAUSE_STATE:
			switch (newState) {
			case SM_GAME_STATE:
				SM_STATE = SM_GAME_STATE;
				break;
			case SM_STARTING_STATE:
				SM_STATE = SM_STARTING_STATE;
				g_init();
				break;
			case SM_TITLE_STATE:
				SM_STATE = SM_TITLE_STATE;
				g_init();
				break;
			default:
				printf("WARNING: invalid state change attempted\n");
			}

			return;
		default:
			printf("WARNING: invalid state passed to sm_changeState\n");
			return;
	}
}