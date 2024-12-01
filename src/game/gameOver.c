#include "gameOver.h"

void go_init() {
	//Transition
	go_transitionFinished = GO_FALSE;

	go_blocksStart = G_END_GAME_BLOCKS_START;

	//Title
	unsigned int titleTextLength = 0;
	for (int i = 0; GO_TITLE_TEXT[i] != '\0'; i++)
		titleTextLength++;

	GO_TITLE_CHAR_SCALE.x = (GO_TITLE_WIDTH - ((titleTextLength - 1) * GO_TITLE_CHAR_THICKNESS)) / titleTextLength;
	GO_TITLE_CHAR_SCALE.y = SCR_HEIGHT / (float)5;

	//Button Selection
	ButtonSelector* buttonData = (ButtonSelector*)malloc(2 * sizeof(ButtonSelector));

	if (buttonData == NULL) {
		printf("ERROR: go_init: out of memory\n");
		exit(-1);
	}

	ButtonSelector* restartButton = &buttonData[0];
	ButtonSelector* quitButton = &buttonData[1];

	//Restart Button
	unsigned int restartButtonLength = 0;
	for (char* c = GO_RESTART_TEXT; *c != '\0'; c++)
		restartButtonLength++;

	restartButton->length = restartButtonLength;

	restartButton->pos = (vec2*)(&GO_RESTART_POSITION);

	restartButton->next = quitButton;
	restartButton->prev = quitButton;

	restartButton->id = GO_BUTTON_RESTART;

	go_originalSelection = restartButton;

	//Quit Button
	unsigned int quitButtonLength = 0;
	for (int i = 0; GO_QUIT_TEXT[i] != '\0'; i++)
		quitButtonLength++;

	quitButton->length = quitButtonLength;

	quitButton->pos = (vec2*)(&GO_QUIT_POSITION);

	quitButton->next = restartButton;
	quitButton->prev = restartButton;

	quitButton->id = GO_BUTTON_QUIT;

	//Set Current
	go_currentSelection = restartButton;
}

void go_update(float deltaTime) {
	if (!go_transitionFinished) {
		//Pre Transition

		const float MOVEMENT_DELAY = 0.1f;

		static float movementTimer = 0;

		static unsigned char movementCount = 0;

		movementTimer += deltaTime;

		if (movementTimer >= MOVEMENT_DELAY) {
			go_blocksStart.y -= G_END_GAME_BLOCK_SIZE;

			movementCount++;
			movementTimer = 0;
		}

		if (movementCount >= G_END_GAME_BLOCKS_VERTICAL_COUNT) {

			go_transitionFinished = GO_TRUE;
			movementCount = 0;
			movementTimer = 0;
		}
	}
	else {
		//Post Transition

		bt_updateVisibilityToggle(deltaTime, &go_selectionVisibilityToggle);

		go_processInput();
	}
}

void go_render() {
	//Post Transition

	//Title
	tp_drawString(GO_TITLE_POSITION, GO_TITLE_CHAR_SCALE, COLOR_WHITE, GO_TITLE_CHAR_THICKNESS, GO_TITLE_CHAR_THICKNESS, TP_NO_SPACING, TP_ALIGNMENT_CENTER, GO_TITLE_TEXT);

	//Restart 
	tp_drawString(GO_RESTART_POSITION, GO_BUTTON_CHAR_SCALE, COLOR_WHITE, GO_BUTTON_TEXT_THICKNESS, GO_BUTTON_TEXT_THICKNESS, TP_NO_SPACING, TP_ALIGNMENT_CENTER, GO_RESTART_TEXT);

	//Quit
	tp_drawString(GO_QUIT_POSITION, GO_BUTTON_CHAR_SCALE, COLOR_WHITE, GO_BUTTON_TEXT_THICKNESS, GO_BUTTON_TEXT_THICKNESS, TP_NO_SPACING, TP_ALIGNMENT_CENTER, GO_QUIT_TEXT);

	//Selector
	if (go_selectionVisibilityToggle) {
		static const vec2 s = { GO_BUTTON_CHAR_SCALE_Y, GO_BUTTON_CHAR_SCALE_Y };

		vec2 p;

		unsigned int length = go_currentSelection->length;

		p.y = go_currentSelection->pos->y;

		if (length % 2 != 0) {
			float dx = (GO_BUTTON_CHAR_SCALE.x / (float)2) + ((length / 2) * (GO_BUTTON_CHAR_SCALE.x + GO_BUTTON_TEXT_THICKNESS)) + GO_BUTTON_CHAR_SCALE.y;

			p.x = go_currentSelection->pos->x - dx;
			qd_drawTexturedRect(bt_getSelectorTextureID(), &p, (vec2*)(&s), 0, c_getColorByIndex(COLOR_INDEX_WHITE));

			p.x = go_currentSelection->pos->x + dx;
			qd_drawTexturedRect(bt_getSelectorTextureID(), &p, (vec2*)(&s), 180, c_getColorByIndex(COLOR_INDEX_WHITE));
		}
		else {
			float dx = (GO_BUTTON_TEXT_THICKNESS / (float)2) + (((length / 2) - 1) * GO_BUTTON_TEXT_THICKNESS) + ((length / 2) * GO_BUTTON_CHAR_SCALE.x) + GO_BUTTON_CHAR_SCALE.y;

			p.x = go_currentSelection->pos->x - dx;
			qd_drawTexturedRect(bt_getSelectorTextureID(), &p, (vec2*)(&s), 0, c_getColorByIndex(COLOR_INDEX_WHITE));

			p.x = go_currentSelection->pos->x + dx;
			qd_drawTexturedRect(bt_getSelectorTextureID(), &p, (vec2*)(&s), 180, c_getColorByIndex(COLOR_INDEX_WHITE));
		}
	}

	if (!go_transitionFinished) {
		//Pre Transition

		vec2 pos = go_blocksStart;

		for (unsigned int i = 0; i < G_END_GAME_BLOCKS_VERTICAL_COUNT; i++) {
			for (int j = 0; j < (int)(sizeof(unsigned char) * 8); j++) {
				b_drawDummyBlock(&pos, G_END_GAME_BLOCK_SIZE, COLOR_INDEX_WHITE);

				pos.x += G_END_GAME_BLOCK_SIZE;
			}

			pos.y += G_END_GAME_BLOCK_SIZE;
			pos.x = go_blocksStart.x;
		}
	}
}

void go_processInput() {
	static unsigned char enterKey = GO_FALSE;
	static unsigned char escapeKey = GO_FALSE;

	static unsigned char wKey = GO_FALSE;
	static unsigned char upKey = GO_FALSE;

	static unsigned char sKey = GO_FALSE;
	static unsigned char downKey = GO_FALSE;

	if (!enterKey && win_checkKey(GLFW_KEY_ENTER)) {
		//Key Down Event

		enterKey = GO_TRUE;
	}
	else if (enterKey && win_checkKey(GLFW_KEY_ENTER)) {
		//Key Held Event
	}
	else if (enterKey && !win_checkKey(GLFW_KEY_ENTER)) {
		//Key Up Event

		switch (go_currentSelection->id) {
			case GO_BUTTON_RESTART:
				sm_changeState(SM_STARTING_STATE);
				break;
			case GO_BUTTON_QUIT:
				sm_changeState(SM_TITLE_STATE);
				break;
			default:
				printf("WARNING: gp_processInput: invalid button id\n");
				break;
		}

		enterKey = GO_FALSE;
	}

	//Move to previous button
	if ((!wKey && win_checkKey(GLFW_KEY_W)) || (!upKey && win_checkKey(GLFW_KEY_UP))) {
		//Key Down Event

		wKey = GO_TRUE;
		upKey = GO_TRUE;
	}
	else if ((wKey && win_checkKey(GLFW_KEY_W)) || (upKey && win_checkKey(GLFW_KEY_UP))) {
		//Key Held Event
	}
	else if ((wKey && !win_checkKey(GLFW_KEY_W)) || (upKey && !win_checkKey(GLFW_KEY_UP))) {
		//Key Up Event

		go_currentSelection = go_currentSelection->prev;

		bt_restartVisibility(&go_selectionVisibilityToggle);

		wKey = GO_FALSE;
		upKey = GO_FALSE;
	}

	//Move to next button
	if ((!sKey && win_checkKey(GLFW_KEY_S)) || (!downKey && win_checkKey(GLFW_KEY_DOWN))) {
		//Key Down Event

		sKey = GO_TRUE;
		downKey = GO_TRUE;
	}
	else if ((sKey && win_checkKey(GLFW_KEY_S)) || (downKey && win_checkKey(GLFW_KEY_DOWN))) {
		//Key Held Event
	}
	else if ((sKey && !win_checkKey(GLFW_KEY_S)) || (downKey && !win_checkKey(GLFW_KEY_DOWN))) {
		//Key Up Event

		go_currentSelection = go_currentSelection->next;

		bt_restartVisibility(&go_selectionVisibilityToggle);

		sKey = GO_FALSE;
		downKey = GO_FALSE;
	}
}