#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "../math/vec2.h"

#include "../render/texture.h"
#include "../render/quad.h"

typedef struct {
	vec2* pos;
	struct ButtonSelector* next;
	struct ButtonSelector* prev;
	unsigned int length;
	unsigned char id;
} ButtonSelector;

#define BT_BUTTON_SELECTOR_PATH "../resources/textures/selection.png"

static unsigned int BT_BUTTON_SELECTOR_TEXTURE_ID;

#define BT_SELECTION_VISIBILITY_INTERVAL 0.5f
static float bt_selectionVisibilityTimer = 0;

void bt_init();

void bt_updateVisibilityToggle(float deltaTime, unsigned char* visibilityToggle);

void bt_restartVisibility(unsigned char* visibilityToggle);

unsigned int bt_getSelectorTextureID();

#endif