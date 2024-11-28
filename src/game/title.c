#include "title.h"

void ti_init() {
	//Init Title Values
	unsigned int G_START_TITLE_TEXT_LENGTH = 0;

	for (unsigned char* c = G_START_TITLE_TEXT; *c != TP_NULL; c++, G_START_TITLE_TEXT_LENGTH++) {}

	G_START_TITLE_CHAR_SCALE.x = ((7 * SCR_WIDTH / (float)8) - (G_START_TITLE_TEXT_LENGTH - 1) * G_START_TITLE_SPACING) / G_START_TITLE_TEXT_LENGTH;
	G_START_TITLE_CHAR_SCALE.y = SCR_HEIGHT / (float)4;

	//Init Button State
	ButtonSelector* buttonData = malloc(2 * sizeof(ButtonSelector));

	if (buttonData == NULL) {
		printf("ERROR: out of memory\n");
		exit(-1);
	}

	ButtonSelector* startButton = &buttonData[0];
	ButtonSelector* quitButton = &buttonData[1];

	//Start Button
	unsigned int startButtonLength = 0;
	for (char* c = TI_START_BUTTON_TEXT; *c != '\0'; c++)
		startButtonLength++;

	startButton->length = startButtonLength;

	startButton->pos = &TI_START_BUTTON_POS;

	startButton->next = quitButton;
	startButton->prev = quitButton;

	startButton->id = TI_BUTTON_START;

	//Quit Button
	unsigned int quitButtonLength = 0;
	for (char* c = TI_QUIT_BUTTON_TEXT; *c != '\0'; c++)
		quitButtonLength++;

	quitButton->length = quitButtonLength;

	quitButton->pos = &TI_QUIT_BUTTON_POS;

	quitButton->next = startButton;
	quitButton->prev = startButton;

	quitButton->id = TI_BUTTON_QUIT;

	//Button Current
	ti_buttonCurrent = startButton;
}

void ti_update(float deltaTime) {

	bt_updateVisibilityToggle(deltaTime, &ti_selectionVisibilityToggle);

	ti_processInput();
}

void ti_render() {
	//Render Title
	tp_drawString(G_START_TITLE_POSITION, G_START_TITLE_CHAR_SCALE, COLOR_WHITE, G_START_TITLE_THICKNESS, G_START_TITLE_SPACING, TP_NO_SPACING, TP_ALIGNMENT_CENTER, G_START_TITLE_TEXT);

	//Render Start Button
	tp_drawString(TI_START_BUTTON_POS, TI_BUTTON_CHAR_SCALE, COLOR_WHITE, TI_BUTTON_TEXT_THICKNESS, TI_BUTTON_CHAR_SPACING, TP_NO_SPACING, TP_ALIGNMENT_CENTER, TI_START_BUTTON_TEXT);

	//Render Quit Button
	tp_drawString(TI_QUIT_BUTTON_POS, TI_BUTTON_CHAR_SCALE, COLOR_WHITE, TI_BUTTON_TEXT_THICKNESS, TI_BUTTON_CHAR_SPACING, TP_NO_SPACING, TP_ALIGNMENT_CENTER, TI_QUIT_BUTTON_TEXT);

	if (ti_selectionVisibilityToggle) {
		static const vec2 s = { TI_BUTTON_CHAR_SCALE_Y, TI_BUTTON_CHAR_SCALE_Y };

		vec2 p;

		unsigned int length = ti_buttonCurrent->length;

		p.y = ti_buttonCurrent->pos->y;

		if (length % 2 != 0) {
			float dx = (TI_BUTTON_CHAR_SCALE.x / (float)2) + ((length / 2 ) * (TI_BUTTON_CHAR_SCALE.x + TI_BUTTON_CHAR_SPACING)) + TI_BUTTON_CHAR_SCALE.y;

			p.x = ti_buttonCurrent->pos->x - dx;
			qd_drawTexturedRect(bt_getSelectorTextureID(), &p, &s, 0, c_getColorByIndex(COLOR_INDEX_WHITE));

			p.x = ti_buttonCurrent->pos->x + dx;
			qd_drawTexturedRect(bt_getSelectorTextureID(), &p, &s, 180, c_getColorByIndex(COLOR_INDEX_WHITE));
		}
		else {
			float dx = (TI_BUTTON_CHAR_SPACING / (float)2) + (((length / 2) - 1) * TI_BUTTON_CHAR_SPACING) + ((length / 2) * TI_BUTTON_CHAR_SCALE.x) + TI_BUTTON_CHAR_SCALE.y;

			p.x = ti_buttonCurrent->pos->x - dx;
			qd_drawTexturedRect(bt_getSelectorTextureID(), &p, &s, 0, c_getColorByIndex(COLOR_INDEX_WHITE));

			p.x = ti_buttonCurrent->pos->x + dx;
			qd_drawTexturedRect(bt_getSelectorTextureID(), &p, &s, 180, c_getColorByIndex(COLOR_INDEX_WHITE));
		}
	}
}

void ti_processInput() {	
	static unsigned char enterKey = TI_FALSE;
	static unsigned char escapeKey = TI_FALSE;

	static unsigned char wKey = TI_FALSE;
	static unsigned char upKey = TI_FALSE;

	static unsigned char sKey = TI_FALSE;
	static unsigned char downKey = TI_FALSE;

	if (!enterKey && win_checkKey(GLFW_KEY_ENTER)) {
		//Key Down Event

		enterKey = TI_TRUE;
	}
	else if (enterKey && win_checkKey(GLFW_KEY_ENTER)) {
		//Key Held Event
	}
	else if (enterKey && !win_checkKey(GLFW_KEY_ENTER)) {
		//Key Up Event

		switch (ti_buttonCurrent->id) {
		case TI_BUTTON_START:
			sm_changeState(SM_STARTING_STATE);
			break;
		case TI_BUTTON_QUIT:
			win_close();
			break;
		default:
			printf("WARNING: ti_processInput: invalid button id\n");
			break;
		}

		enterKey = TI_FALSE;
	}

	//Move to previous button
	if ((!wKey && win_checkKey(GLFW_KEY_W)) || (!upKey && win_checkKey(GLFW_KEY_UP))) {
		//Key Down Event

		wKey = TI_TRUE;
		upKey = TI_TRUE;
	}
	else if ((wKey && win_checkKey(GLFW_KEY_W)) || (upKey && win_checkKey(GLFW_KEY_UP))) {
		//Key Held Event
	}
	else if ((wKey && !win_checkKey(GLFW_KEY_W)) || (upKey && !win_checkKey(GLFW_KEY_UP))) {
		//Key Up Event

		ti_buttonCurrent = ti_buttonCurrent->prev;

		bt_restartVisibility(&ti_selectionVisibilityToggle);

		wKey = TI_FALSE;
		upKey = TI_FALSE;
	}

	//Move to next button
	if ((!sKey && win_checkKey(GLFW_KEY_S)) || (!downKey && win_checkKey(GLFW_KEY_DOWN))) {
		//Key Down Event

		sKey = TI_TRUE;
		downKey = TI_TRUE;
	}
	else if ((sKey && win_checkKey(GLFW_KEY_S)) || (downKey && win_checkKey(GLFW_KEY_DOWN))) {
		//Key Held Event
	}
	else if ((sKey && !win_checkKey(GLFW_KEY_S)) || (downKey && !win_checkKey(GLFW_KEY_DOWN))) {
		//Key Up Event

		ti_buttonCurrent = ti_buttonCurrent->next;

		bt_restartVisibility(&ti_selectionVisibilityToggle);

		sKey = TI_FALSE;
		downKey = TI_FALSE;
	}
}