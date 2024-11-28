#include "button.h"

void bt_init() {
	BT_BUTTON_SELECTOR_TEXTURE_ID = tx_genTexture(BT_BUTTON_SELECTOR_PATH, TX_TRUE);
}

void bt_updateVisibilityToggle(float deltaTime, unsigned char* visibilityToggle) {
	bt_selectionVisibilityTimer += deltaTime;

	if (bt_selectionVisibilityTimer >= BT_SELECTION_VISIBILITY_INTERVAL) {
		if (*visibilityToggle) {
			*visibilityToggle = 0;
		}
		else {
			*visibilityToggle = 1;
		}

		bt_selectionVisibilityTimer = 0;
	}
}

void bt_restartVisibility(unsigned char* visibilityToggle) {
	*visibilityToggle = 1;

	bt_selectionVisibilityTimer = 0;
}

unsigned int bt_getSelectorTextureID() {
	return BT_BUTTON_SELECTOR_TEXTURE_ID;
}
