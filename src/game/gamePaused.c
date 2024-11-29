#include "gamePaused.h"

void gp_init() {
	unsigned int titleTextLength = 0;

	for (char* c = GP_TITLE_TEXT; *c != '\0'; c++)
		titleTextLength++;

	GP_TITLE_CHAR_SCALE.x = (GP_TITLE_WIDTH - ((titleTextLength - 1) * GP_TITLE_CHAR_THICKNESS)) / titleTextLength;
	GP_TITLE_CHAR_SCALE.y = SCR_HEIGHT / (float)5;

	//Button Selection
	ButtonSelector* buttonData = (ButtonSelector*)malloc(3 * sizeof(ButtonSelector));

	if (buttonData == NULL) {
		printf("ERROR: gp_init: out of memory\n");
		exit(-1);
	}

	ButtonSelector* resumeButton = &buttonData[0];
	ButtonSelector* restartButton = &buttonData[1];
	ButtonSelector* quitButton = &buttonData[2];

	//Resume Button
	unsigned int resumeButtonLength = 0;
	for (char* c = GP_BUTTON_RESUME_TEXT; *c != '\0'; c++)
		resumeButtonLength++;

	resumeButton->length = resumeButtonLength;

	resumeButton->pos = &GP_RESUME_POSITION;

	resumeButton->next = restartButton;
	resumeButton->prev = quitButton;

	resumeButton->id = GP_BUTTON_RESUME;

	gp_originalSelection = resumeButton;

	//Restart Button
	unsigned int restartButtonLength = 0;
	for (char* c = GP_RESTART_TEXT; *c != '\0'; c++)
		restartButtonLength++;

	restartButton->length = restartButtonLength;

	restartButton->pos = &GP_RESTART_POSITION;

	restartButton->next = quitButton;
	restartButton->prev = resumeButton;

	restartButton->id = GP_BUTTON_RESTART;

	//Quit Button
	unsigned int quitButtonLength = 0;
	for (char* c = GP_QUIT_TEXT; *c != '\0'; c++)
		quitButtonLength++;

	quitButton->length = quitButtonLength;

	quitButton->pos = &GP_QUIT_POSITION;

	quitButton->next = resumeButton;
	quitButton->prev = restartButton;

	quitButton->id = GP_BUTTON_QUIT;

	//Set Current
	gp_currentButton = resumeButton;
}

void gp_update(float deltaTime) {
	bt_updateVisibilityToggle(deltaTime, &gp_selectionVisibilityToggle);

	gp_processInput();
}

void gp_render() {
	//Title
	tp_drawString(GP_TITLE_POSITION, GP_TITLE_CHAR_SCALE, COLOR_WHITE, GP_TITLE_CHAR_THICKNESS, GP_TITLE_CHAR_THICKNESS, TP_NO_SPACING, TP_ALIGNMENT_CENTER, GP_TITLE_TEXT);

	//Resume
	tp_drawString(GP_RESUME_POSITION, GP_BUTTON_CHAR_SCALE, COLOR_WHITE, GP_BUTTON_TEXT_THICKNESS, GP_BUTTON_TEXT_THICKNESS, TP_NO_SPACING, TP_ALIGNMENT_CENTER, GP_BUTTON_RESUME_TEXT);

	//Restart
	tp_drawString(GP_RESTART_POSITION, GP_BUTTON_CHAR_SCALE, COLOR_WHITE, GP_BUTTON_TEXT_THICKNESS, GP_BUTTON_TEXT_THICKNESS, TP_NO_SPACING, TP_ALIGNMENT_CENTER, GP_RESTART_TEXT);

	//Quit
	tp_drawString(GP_QUIT_POSITION, GP_BUTTON_CHAR_SCALE, COLOR_WHITE, GP_BUTTON_TEXT_THICKNESS, GP_BUTTON_TEXT_THICKNESS, TP_NO_SPACING, TP_ALIGNMENT_CENTER, GP_QUIT_TEXT);

	//Selection
	if (gp_selectionVisibilityToggle) {
		static const vec2 s = { GP_BUTTON_CHAR_SCALE_Y, GP_BUTTON_CHAR_SCALE_Y };

		vec2 p;

		unsigned int length = gp_currentButton->length;

		p.y = gp_currentButton->pos->y;

		if (length % 2 != 0) {
			float dx = (GP_BUTTON_CHAR_SCALE.x / (float)2) + ((length / 2) * (GP_BUTTON_CHAR_SCALE.x + GP_BUTTON_TEXT_THICKNESS)) + GP_BUTTON_CHAR_SCALE.y;

			p.x = gp_currentButton->pos->x - dx;
			qd_drawTexturedRect(bt_getSelectorTextureID(), &p, &s, 0, c_getColorByIndex(COLOR_INDEX_WHITE));

			p.x = gp_currentButton->pos->x + dx;
			qd_drawTexturedRect(bt_getSelectorTextureID(), &p, &s, 180, c_getColorByIndex(COLOR_INDEX_WHITE));
		}
		else {
			float dx = (GP_BUTTON_TEXT_THICKNESS / (float)2) + (((length / 2) - 1) * GP_BUTTON_TEXT_THICKNESS) + ((length / 2) * GP_BUTTON_CHAR_SCALE.x) + GP_BUTTON_CHAR_SCALE.y;

			p.x = gp_currentButton->pos->x - dx;
			qd_drawTexturedRect(bt_getSelectorTextureID(), &p, &s, 0, c_getColorByIndex(COLOR_INDEX_WHITE));

			p.x = gp_currentButton->pos->x + dx;
			qd_drawTexturedRect(bt_getSelectorTextureID(), &p, &s, 180, c_getColorByIndex(COLOR_INDEX_WHITE));
		}
	}
}

void gp_processInput() {
	static unsigned char enterKey = GP_FALSE;
	static unsigned char escapeKey = GP_FALSE;

	static unsigned char wKey = GP_FALSE;
	static unsigned char upKey = GP_FALSE;

	static unsigned char sKey = GP_FALSE;
	static unsigned char downKey = GP_FALSE;

	if (!enterKey && win_checkKey(GLFW_KEY_ENTER)) {
		//Key Down Event

		enterKey = GP_TRUE;
	}
	else if (enterKey && win_checkKey(GLFW_KEY_ENTER)) {
		//Key Held Event
	}
	else if (enterKey && !win_checkKey(GLFW_KEY_ENTER)) {
		//Key Up Event

		switch (gp_currentButton->id) {
			case GP_BUTTON_RESUME:
				sm_changeState(SM_GAME_STATE);
				break;
			case GP_BUTTON_RESTART:
				sm_changeState(SM_STARTING_STATE);
				break;
			case GP_BUTTON_QUIT:
				sm_changeState(SM_TITLE_STATE);
				break;
			default:
				printf("WARNING: gp_processInput: invalid button id\n");
				break;
		}

		enterKey = GP_FALSE;
	}

	//Move to previous button
	if ((!wKey && win_checkKey(GLFW_KEY_W)) || (!upKey && win_checkKey(GLFW_KEY_UP))) {
		//Key Down Event

		wKey = GP_TRUE;
		upKey = GP_TRUE;
	}
	else if ((wKey && win_checkKey(GLFW_KEY_W)) || (upKey && win_checkKey(GLFW_KEY_UP))) {
		//Key Held Event
	}
	else if ((wKey && !win_checkKey(GLFW_KEY_W)) || (upKey && !win_checkKey(GLFW_KEY_UP))) {
		//Key Up Event

		gp_currentButton = gp_currentButton->prev;

		bt_restartVisibility(&gp_selectionVisibilityToggle);

		wKey = GP_FALSE;
		upKey = GP_FALSE;
	}

	//Move to next button
	if ((!sKey && win_checkKey(GLFW_KEY_S)) || (!downKey && win_checkKey(GLFW_KEY_DOWN))) {
		//Key Down Event

		sKey = GP_TRUE;
		downKey = GP_TRUE;
	}
	else if ((sKey && win_checkKey(GLFW_KEY_S)) || (downKey && win_checkKey(GLFW_KEY_DOWN))) {
		//Key Held Event
	}
	else if ((sKey && !win_checkKey(GLFW_KEY_S)) || (downKey && !win_checkKey(GLFW_KEY_DOWN))) {
		//Key Up Event

		gp_currentButton = gp_currentButton->next;

		bt_restartVisibility(&gp_selectionVisibilityToggle);

		sKey = GP_FALSE;
		downKey = GP_FALSE;
	}
}