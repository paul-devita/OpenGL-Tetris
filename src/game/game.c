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

	//Game State
		//General

		//UI
			//Score Box
				//Box
				G_GAME_SCORE_BOX_POSITION.x = 7 * SCR_WIDTH / 8.0;
				G_GAME_SCORE_BOX_POSITION.y = 7 * SCR_HEIGHT / 10.0;
		
				G_GAME_SCORE_BOX_SCALE.x = SCR_WIDTH / 5.0;
				G_GAME_SCORE_BOX_SCALE.y = SCR_HEIGHT / 2.0;

				//Title
				unsigned int G_GAME_SCORE_TITLE_TEXT_LENGTH = 0;

				for (unsigned char* c = G_GAME_SCORE_TITLE_TEXT; *c != TP_NULL; c++, G_GAME_SCORE_TITLE_TEXT_LENGTH++) {}

				G_GAME_SCORE_TITLE_TEXT_POSITION.x = G_GAME_SCORE_BOX_POSITION.x;
				G_GAME_SCORE_TITLE_TEXT_POSITION.y = G_GAME_SCORE_BOX_POSITION.y - 3 * G_GAME_SCORE_BOX_SCALE.y / 8.0;

				G_GAME_SCORE_TITLE_TEXT_SCALE.x = (3 * G_GAME_SCORE_BOX_SCALE.x) / (4.0 * G_GAME_SCORE_TITLE_TEXT_LENGTH) - ((G_GAME_SCORE_TITLE_TEXT_LENGTH - 1) * G_GAME_TEXT_CHAR_SPACING) / (float) G_GAME_SCORE_TITLE_TEXT_LENGTH;
				G_GAME_SCORE_TITLE_TEXT_SCALE.y = G_GAME_TEXT_HEIGHT;

				//Score
				for (unsigned char i = 0; i < G_GAME_SCORE_TEXT_LENGTH; i++)
					G_GAME_SCORE_TEXT[i] = '0';
				G_GAME_SCORE_TEXT[G_GAME_SCORE_TEXT_LENGTH] = '\0';

				G_GAME_SCORE_TEXT_POSITION.x = G_GAME_SCORE_BOX_POSITION.x;
				G_GAME_SCORE_TEXT_POSITION.y = G_GAME_SCORE_BOX_POSITION.y;

				G_GAME_SCORE_TEXT_SCALE.x = (3 * G_GAME_SCORE_BOX_SCALE.x) / (4.0 * G_GAME_SCORE_TEXT_LENGTH) - ((G_GAME_SCORE_TEXT_LENGTH - 1) * G_GAME_TEXT_CHAR_SPACING) / (float) G_GAME_SCORE_TEXT_LENGTH;
				G_GAME_SCORE_TEXT_SCALE.y = G_GAME_TEXT_HEIGHT;
			
			//Next Box
				//Box
				G_GAME_NEXT_BOX_POSITION.x = 7 * SCR_WIDTH / 8.0;
				G_GAME_NEXT_BOX_POSITION.y = 9 * SCR_HEIGHT / 40.0;

				G_GAME_NEXT_BOX_SCALE.x = SCR_WIDTH / 5.0;
				G_GAME_NEXT_BOX_SCALE.y = 7 * SCR_HEIGHT / 20.0;

				//Title
				unsigned int G_GAME_NEXT_TITLE_TEXT_LENGTH = 0;

				for (unsigned char* c = G_GAME_NEXT_TITLE_TEXT; *c != TP_NULL; c++, G_GAME_NEXT_TITLE_TEXT_LENGTH++) {}

				G_GAME_NEXT_TITLE_TEXT_POSITION.x = G_GAME_NEXT_BOX_POSITION.x;
				G_GAME_NEXT_TITLE_TEXT_POSITION.y = G_GAME_NEXT_BOX_POSITION.y - G_GAME_NEXT_BOX_SCALE.y / 4.0;

				G_GAME_NEXT_TITLE_TEXT_SCALE.x = (3 * G_GAME_NEXT_BOX_SCALE.x) / (4.0 * G_GAME_NEXT_TITLE_TEXT_LENGTH) - ((G_GAME_NEXT_TITLE_TEXT_LENGTH - 1) * G_GAME_TEXT_CHAR_SPACING) / (float) G_GAME_NEXT_TITLE_TEXT_LENGTH;
				G_GAME_NEXT_TITLE_TEXT_SCALE.y = G_GAME_TEXT_HEIGHT;

				//Piece

			//Hold Box
				//Box
				G_GAME_HOLD_BOX_POSITION.x = SCR_WIDTH / 8.0;
				G_GAME_HOLD_BOX_POSITION.y = 9 * SCR_HEIGHT / 40.0;

				G_GAME_HOLD_BOX_SCALE.x = SCR_WIDTH / 5.0;
				G_GAME_HOLD_BOX_SCALE.y = 7 * SCR_HEIGHT / 20.0;

				//Title
				unsigned int G_GAME_HOLD_TITLE_TEXT_LENGTH = 0;

				for (unsigned char* c = G_GAME_HOLD_TITLE_TEXT; *c != TP_NULL; c++, G_GAME_HOLD_TITLE_TEXT_LENGTH++) {}

				G_GAME_HOLD_TITLE_TEXT_POSITION.x = G_GAME_HOLD_BOX_POSITION.x;
				G_GAME_HOLD_TITLE_TEXT_POSITION.y = G_GAME_HOLD_BOX_POSITION.y - G_GAME_HOLD_BOX_SCALE.y / 4.0;

				G_GAME_HOLD_TITLE_TEXT_SCALE.x = (3 * G_GAME_HOLD_BOX_SCALE.x) / (4.0 * G_GAME_NEXT_TITLE_TEXT_LENGTH) - ((G_GAME_NEXT_TITLE_TEXT_LENGTH - 1) * G_GAME_TEXT_CHAR_SPACING) / (float)G_GAME_NEXT_TITLE_TEXT_LENGTH;
				G_GAME_HOLD_TITLE_TEXT_SCALE.y = G_GAME_TEXT_HEIGHT;

				//Piece

			//Stats Box
				//Box
				G_GAME_STATS_BOX_POSITION.x = SCR_WIDTH / 8.0;
				G_GAME_STATS_BOX_POSITION.y = 7 * SCR_HEIGHT / 10.0;

				G_GAME_STATS_BOX_SCALE.x = SCR_WIDTH / 5.0;
				G_GAME_STATS_BOX_SCALE.y = SCR_HEIGHT / 2.0;

				//Title
				unsigned int G_GAME_STATS_TITLE_TEXT_LENGTH = 0;

				for (unsigned char* c = G_GAME_STATS_TITLE_TEXT; *c != TP_NULL; c++ < G_GAME_STATS_TITLE_TEXT_LENGTH++) {}

				G_GAME_STATS_TITLE_TEXT_POSITION.x = G_GAME_STATS_BOX_POSITION.x;
				G_GAME_STATS_TITLE_TEXT_POSITION.y = G_GAME_STATS_BOX_POSITION.y - 3 * G_GAME_STATS_BOX_SCALE.y / 8.0;

				G_GAME_STATS_TITLE_TEXT_SCALE.x = (3 * G_GAME_STATS_BOX_SCALE.x) / (4.0 * G_GAME_STATS_TITLE_TEXT_LENGTH) - ((G_GAME_STATS_TITLE_TEXT_LENGTH - 1) * G_GAME_TEXT_CHAR_SPACING) / (float)G_GAME_STATS_TITLE_TEXT_LENGTH;
				G_GAME_STATS_TITLE_TEXT_SCALE.y = G_GAME_TEXT_HEIGHT;

				//Elements
					for (unsigned int i = 0; i < G_GAME_STATS_NUM_LENGTH; i++) {
						G_GAME_STATS_I_BLOCK_TEXT[i] = '0';
						G_GAME_STATS_J_BLOCK_TEXT[i] = '0';
						G_GAME_STATS_L_BLOCK_TEXT[i] = '0';
						G_GAME_STATS_O_BLOCK_TEXT[i] = '0';
						G_GAME_STATS_S_BLOCK_TEXT[i] = '0';
						G_GAME_STATS_T_BLOCK_TEXT[i] = '0';
						G_GAME_STATS_Z_BLOCK_TEXT[i] = '0';
					}
					G_GAME_STATS_I_BLOCK_TEXT[G_GAME_STATS_NUM_LENGTH] = '\0';
					G_GAME_STATS_J_BLOCK_TEXT[G_GAME_STATS_NUM_LENGTH] = '\0';
					G_GAME_STATS_L_BLOCK_TEXT[G_GAME_STATS_NUM_LENGTH] = '\0';
					G_GAME_STATS_O_BLOCK_TEXT[G_GAME_STATS_NUM_LENGTH] = '\0';
					G_GAME_STATS_S_BLOCK_TEXT[G_GAME_STATS_NUM_LENGTH] = '\0';
					G_GAME_STATS_T_BLOCK_TEXT[G_GAME_STATS_NUM_LENGTH] = '\0';
					G_GAME_STATS_Z_BLOCK_TEXT[G_GAME_STATS_NUM_LENGTH] = '\0';

					G_GAME_STATS_ELEMENT_TEXT_CHAR_SCALE.x = (9 * G_GAME_STATS_ELEMENT_SCALE.x) / (float)(20 * G_GAME_STATS_NUM_LENGTH) - ((G_GAME_STATS_NUM_LENGTH - 1) * G_GAME_TEXT_CHAR_SPACING) / (float) G_GAME_STATS_NUM_LENGTH;
					G_GAME_STATS_ELEMENT_TEXT_CHAR_SCALE.y = (3 * G_GAME_STATS_ELEMENT_SCALE.y) / 4.0;

					//I Block
					G_GAME_STATS_I_ELEMENT_TEXT_POSITION.x = G_GAME_STATS_BOX_POSITION.x + G_GAME_STATS_ELEMENT_SCALE.x / 5.0;
					G_GAME_STATS_I_ELEMENT_TEXT_POSITION.y = G_GAME_STATS_BOX_POSITION.y + G_GAME_STATS_BOX_SCALE.y / 16.0 - (9 * G_GAME_STATS_ELEMENT_SCALE.y) / 2.0 - 3 * G_GAME_STATS_ELEMENT_SPACING;

					//J Block
					G_GAME_STATS_J_ELEMENT_TEXT_POSITION.x = G_GAME_STATS_BOX_POSITION.x + G_GAME_STATS_ELEMENT_SCALE.x / 5.0;
					G_GAME_STATS_J_ELEMENT_TEXT_POSITION.y = G_GAME_STATS_BOX_POSITION.y + G_GAME_STATS_BOX_SCALE.y / 16.0 - (6 * G_GAME_STATS_ELEMENT_SCALE.y) / 2.0 - 2 * G_GAME_STATS_ELEMENT_SPACING;

					//L Block
					G_GAME_STATS_L_ELEMENT_TEXT_POSITION.x = G_GAME_STATS_BOX_POSITION.x + G_GAME_STATS_ELEMENT_SCALE.x / 5.0;
					G_GAME_STATS_L_ELEMENT_TEXT_POSITION.y = G_GAME_STATS_BOX_POSITION.y + G_GAME_STATS_BOX_SCALE.y / 16.0 - (3 * G_GAME_STATS_ELEMENT_SCALE.y) / 2.0 - G_GAME_STATS_ELEMENT_SPACING;

					//O Block
					G_GAME_STATS_O_ELEMENT_TEXT_POSITION.x = G_GAME_STATS_BOX_POSITION.x + G_GAME_STATS_ELEMENT_SCALE.x / 5.0;
					G_GAME_STATS_O_ELEMENT_TEXT_POSITION.y = G_GAME_STATS_BOX_POSITION.y + G_GAME_STATS_BOX_SCALE.y / 16.0;

					//S Block
					G_GAME_STATS_S_ELEMENT_TEXT_POSITION.x = G_GAME_STATS_BOX_POSITION.x + G_GAME_STATS_ELEMENT_SCALE.x / 5.0;
					G_GAME_STATS_S_ELEMENT_TEXT_POSITION.y = G_GAME_STATS_BOX_POSITION.y + G_GAME_STATS_BOX_SCALE.y / 16.0 + (3 * G_GAME_STATS_ELEMENT_SCALE.y) / 2.0 + G_GAME_STATS_ELEMENT_SPACING;

					//T Block
					G_GAME_STATS_T_ELEMENT_TEXT_POSITION.x = G_GAME_STATS_BOX_POSITION.x + G_GAME_STATS_ELEMENT_SCALE.x / 5.0;
					G_GAME_STATS_T_ELEMENT_TEXT_POSITION.y = G_GAME_STATS_BOX_POSITION.y + G_GAME_STATS_BOX_SCALE.y / 16.0 + (6 * G_GAME_STATS_ELEMENT_SCALE.y) / 2.0 + 2 * G_GAME_STATS_ELEMENT_SPACING;

					//Z Block
					G_GAME_STATS_Z_ELEMENT_TEXT_POSITION.x = G_GAME_STATS_BOX_POSITION.x + G_GAME_STATS_ELEMENT_SCALE.x / 5.0;
					G_GAME_STATS_Z_ELEMENT_TEXT_POSITION.y = G_GAME_STATS_BOX_POSITION.y + G_GAME_STATS_BOX_SCALE.y / 16.0 + (9 * G_GAME_STATS_ELEMENT_SCALE.y) / 2.0 + 3 * G_GAME_STATS_ELEMENT_SPACING;

		//Grid
			G_GRID_POSITION.x = SCR_WIDTH / (double)2;
			G_GRID_POSITION.y = SCR_HEIGHT / (double)2;

			G_GRID_SCALE.x = (9 * SCR_WIDTH) / (double)20;
			G_GRID_SCALE.y = 2 * G_GRID_SCALE.x;

			G_GRID_OUTLINE_SCALE.x = G_GRID_SCALE.x + 2 * G_GRID_OUTLINE_THICKNESS;
			G_GRID_OUTLINE_SCALE.y = G_GRID_SCALE.y + 2 * G_GRID_OUTLINE_THICKNESS;


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
			tp_drawString(G_START_TITLE_POSITION, G_START_TITLE_CHAR_SCALE, G_COLOR_WHITE, G_START_TITLE_THICKNESS, G_START_TITLE_SPACING, TP_NO_SPACING, TP_ALIGNMENT_CENTER, G_START_TITLE_TEXT);

			//Render Press Start
			if (g_start_pressStartToggle)
				tp_drawString(G_START_PRESS_POSITION, G_START_PRESS_CHAR_SCALE, G_COLOR_WHITE, G_START_PRESS_THICKNESS, G_START_PRESS_SPACING, TP_NO_SPACING, TP_ALIGNMENT_CENTER, G_START_PRESS_TEXT);
			
			break;
		case GAME_STATE_PLAY:
			//Render UI
				//Score
					qd_drawOutlineRect(G_GAME_SCORE_BOX_POSITION, G_GAME_SCORE_BOX_SCALE, G_GAME_BOX_THICKNESS, G_COLOR_WHITE);

					tp_drawString(G_GAME_SCORE_TITLE_TEXT_POSITION, G_GAME_SCORE_TITLE_TEXT_SCALE, G_COLOR_WHITE, G_GAME_TEXT_THICKNESS_BOLD, G_GAME_TEXT_CHAR_SPACING, TP_NO_SPACING, TP_ALIGNMENT_CENTER, G_GAME_SCORE_TITLE_TEXT);
					tp_drawString(G_GAME_SCORE_TEXT_POSITION, G_GAME_SCORE_TEXT_SCALE, G_COLOR_WHITE, G_GAME_TEXT_THICKNESS_STANDARD, G_GAME_TEXT_CHAR_SPACING, TP_NO_SPACING, TP_ALIGNMENT_CENTER, G_GAME_SCORE_TEXT);

				//Next
					qd_drawOutlineRect(G_GAME_NEXT_BOX_POSITION, G_GAME_NEXT_BOX_SCALE, G_GAME_BOX_THICKNESS, G_COLOR_WHITE);

					tp_drawString(G_GAME_NEXT_TITLE_TEXT_POSITION, G_GAME_NEXT_TITLE_TEXT_SCALE, G_COLOR_WHITE, G_GAME_TEXT_THICKNESS_BOLD, G_GAME_TEXT_CHAR_SPACING, TP_NO_SPACING, TP_ALIGNMENT_CENTER, G_GAME_NEXT_TITLE_TEXT);

				//Hold
					qd_drawOutlineRect(G_GAME_HOLD_BOX_POSITION, G_GAME_HOLD_BOX_SCALE, G_GAME_BOX_THICKNESS, G_COLOR_WHITE);

					tp_drawString(G_GAME_HOLD_TITLE_TEXT_POSITION, G_GAME_HOLD_TITLE_TEXT_SCALE, G_COLOR_WHITE, G_GAME_TEXT_THICKNESS_BOLD, G_GAME_TEXT_CHAR_SPACING, TP_NO_SPACING, TP_ALIGNMENT_CENTER, G_GAME_HOLD_TITLE_TEXT);

				//Stats
					qd_drawOutlineRect(G_GAME_STATS_BOX_POSITION, G_GAME_STATS_BOX_SCALE, G_GAME_BOX_THICKNESS, G_COLOR_WHITE);

					tp_drawString(G_GAME_STATS_TITLE_TEXT_POSITION, G_GAME_STATS_TITLE_TEXT_SCALE, G_COLOR_WHITE, G_GAME_TEXT_THICKNESS_BOLD, G_GAME_TEXT_CHAR_SPACING, TP_NO_SPACING, TP_ALIGNMENT_CENTER, G_GAME_STATS_TITLE_TEXT);

					//I
					tp_drawString(G_GAME_STATS_I_ELEMENT_TEXT_POSITION, G_GAME_STATS_ELEMENT_TEXT_CHAR_SCALE, G_COLOR_WHITE, G_GAME_TEXT_THICKNESS_STANDARD, G_GAME_TEXT_CHAR_SPACING, TP_NO_SPACING, TP_ALIGNMENT_CENTER, G_GAME_STATS_I_BLOCK_TEXT);

					//J
					tp_drawString(G_GAME_STATS_J_ELEMENT_TEXT_POSITION, G_GAME_STATS_ELEMENT_TEXT_CHAR_SCALE, G_COLOR_WHITE, G_GAME_TEXT_THICKNESS_STANDARD, G_GAME_TEXT_CHAR_SPACING, TP_NO_SPACING, TP_ALIGNMENT_CENTER, G_GAME_STATS_J_BLOCK_TEXT);

					//L
					tp_drawString(G_GAME_STATS_L_ELEMENT_TEXT_POSITION, G_GAME_STATS_ELEMENT_TEXT_CHAR_SCALE, G_COLOR_WHITE, G_GAME_TEXT_THICKNESS_STANDARD, G_GAME_TEXT_CHAR_SPACING, TP_NO_SPACING, TP_ALIGNMENT_CENTER, G_GAME_STATS_L_BLOCK_TEXT);

					//O
					tp_drawString(G_GAME_STATS_O_ELEMENT_TEXT_POSITION, G_GAME_STATS_ELEMENT_TEXT_CHAR_SCALE, G_COLOR_WHITE, G_GAME_TEXT_THICKNESS_STANDARD, G_GAME_TEXT_CHAR_SPACING, TP_NO_SPACING, TP_ALIGNMENT_CENTER, G_GAME_STATS_O_BLOCK_TEXT);

					//S
					tp_drawString(G_GAME_STATS_S_ELEMENT_TEXT_POSITION, G_GAME_STATS_ELEMENT_TEXT_CHAR_SCALE, G_COLOR_WHITE, G_GAME_TEXT_THICKNESS_STANDARD, G_GAME_TEXT_CHAR_SPACING, TP_NO_SPACING, TP_ALIGNMENT_CENTER, G_GAME_STATS_S_BLOCK_TEXT);

					//T
					tp_drawString(G_GAME_STATS_T_ELEMENT_TEXT_POSITION, G_GAME_STATS_ELEMENT_TEXT_CHAR_SCALE, G_COLOR_WHITE, G_GAME_TEXT_THICKNESS_STANDARD, G_GAME_TEXT_CHAR_SPACING, TP_NO_SPACING, TP_ALIGNMENT_CENTER, G_GAME_STATS_T_BLOCK_TEXT);

					//Z
					tp_drawString(G_GAME_STATS_Z_ELEMENT_TEXT_POSITION, G_GAME_STATS_ELEMENT_TEXT_CHAR_SCALE, G_COLOR_WHITE, G_GAME_TEXT_THICKNESS_STANDARD, G_GAME_TEXT_CHAR_SPACING, TP_NO_SPACING, TP_ALIGNMENT_CENTER, G_GAME_STATS_Z_BLOCK_TEXT);

			//Render Game
					b_drawSingle(v2_new(SCR_WIDTH / 2.0, SCR_HEIGHT / 2.0), v2_new(500, 300), G_COLOR_BLUE);

					//Grid
					qd_drawOutlineRect(G_GRID_POSITION, G_GRID_OUTLINE_SCALE, G_GRID_OUTLINE_THICKNESS, G_COLOR_WHITE);

					g_drawGridLines();
				
			break;
	}
}

void g_drawGridLines() {
	const float width = SCR_WIDTH / 400.0;

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
	if (G_GAME_SCORE + additionalScore >= G_GAME_MAXIMUM_SCORE) {
		G_GAME_SCORE = G_GAME_MAXIMUM_SCORE;
	}
	else {
		G_GAME_SCORE += additionalScore;
	}

	unsigned int temp = G_GAME_SCORE;

	for (short i = G_GAME_SCORE_TEXT_LENGTH - 1; i >= 0; i--) {
		unsigned int digit;

		digit = temp % 10;

		G_GAME_SCORE_TEXT[i] = digit + '0';

		temp /= 10;
	}
}

void g_incrementStat(unsigned char block) {
	char* text;

	unsigned short temp;

	switch (block) {
		case B_I_BLOCK:
			if (G_GAME_STATS_I_BLOCK_COUNT + 1 > G_GAME_STATS_MAXIMUM_COUNT)
				G_GAME_STATS_I_BLOCK_COUNT = G_GAME_STATS_MAXIMUM_COUNT;
			else
				G_GAME_STATS_I_BLOCK_COUNT++;

			temp = G_GAME_STATS_I_BLOCK_COUNT;

			text = G_GAME_STATS_I_BLOCK_TEXT;

			break;
		case B_J_BLOCK:
			if (G_GAME_STATS_J_BLOCK_COUNT + 1 > G_GAME_STATS_MAXIMUM_COUNT)
				G_GAME_STATS_J_BLOCK_COUNT = G_GAME_STATS_MAXIMUM_COUNT;
			else
				G_GAME_STATS_J_BLOCK_COUNT++;

			temp = G_GAME_STATS_J_BLOCK_COUNT;

			text = G_GAME_STATS_J_BLOCK_TEXT;

			break;
		case B_L_BLOCK:
			if (G_GAME_STATS_L_BLOCK_COUNT + 1 > G_GAME_STATS_MAXIMUM_COUNT)
				G_GAME_STATS_L_BLOCK_COUNT = G_GAME_STATS_MAXIMUM_COUNT;
			else
				G_GAME_STATS_L_BLOCK_COUNT++;

			temp = G_GAME_STATS_L_BLOCK_COUNT;

			text = G_GAME_STATS_L_BLOCK_TEXT;

			break;
		case B_O_BLOCK:
			if (G_GAME_STATS_O_BLOCK_COUNT + 1 > G_GAME_STATS_MAXIMUM_COUNT)
				G_GAME_STATS_O_BLOCK_COUNT = G_GAME_STATS_MAXIMUM_COUNT;
			else
				G_GAME_STATS_O_BLOCK_COUNT++;

			temp = G_GAME_STATS_O_BLOCK_COUNT;

			text = G_GAME_STATS_O_BLOCK_TEXT;

			break;
		case B_S_BLOCK:
			if (G_GAME_STATS_S_BLOCK_COUNT + 1 > G_GAME_STATS_MAXIMUM_COUNT)
				G_GAME_STATS_S_BLOCK_COUNT = G_GAME_STATS_MAXIMUM_COUNT;
			else
				G_GAME_STATS_S_BLOCK_COUNT++;

			temp = G_GAME_STATS_S_BLOCK_COUNT;

			text = G_GAME_STATS_S_BLOCK_TEXT;

			break;
		case B_T_BLOCK:
			if (G_GAME_STATS_T_BLOCK_COUNT + 1 > G_GAME_STATS_MAXIMUM_COUNT)
				G_GAME_STATS_T_BLOCK_COUNT = G_GAME_STATS_MAXIMUM_COUNT;
			else
				G_GAME_STATS_T_BLOCK_COUNT++;

			temp = G_GAME_STATS_T_BLOCK_COUNT;

			text = G_GAME_STATS_T_BLOCK_TEXT;

			break;
		case B_Z_BLOCK:
			if (G_GAME_STATS_Z_BLOCK_COUNT + 1 > G_GAME_STATS_MAXIMUM_COUNT)
				G_GAME_STATS_Z_BLOCK_COUNT = G_GAME_STATS_MAXIMUM_COUNT;
			else
				G_GAME_STATS_Z_BLOCK_COUNT++;

			temp = G_GAME_STATS_Z_BLOCK_COUNT;

			text = G_GAME_STATS_Z_BLOCK_TEXT;

			break;
		default:
			printf("WARNING: invalid block type passed to g_incrementStat\n");
			return;
	}

	for (short i = G_GAME_STATS_NUM_LENGTH - 1; i >= 0; i--) {
		unsigned short digit;

		digit = temp % 10;

		text[i] = digit + '0';

		temp /= 10;
	}
}