#include "gameOver.h"

void go_init() {
	go_transitionFinished = GO_FALSE;

	go_blocksStart = G_END_GAME_BLOCKS_START;
}

void go_update(float deltaTime) {
	if (!go_transitionFinished) {
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

	}
}

void go_processInput() {

}

void go_render() {
	if (!go_transitionFinished) {
		vec2 pos = go_blocksStart;

		for (int i = 0; i < G_END_GAME_BLOCKS_VERTICAL_COUNT; i++) {
			for (int j = 0; j < (int)(sizeof(unsigned char) * 8); j++) {
				b_drawDummyBlock(&pos, G_END_GAME_BLOCK_SIZE, COLOR_INDEX_WHITE);

				pos.x += G_END_GAME_BLOCK_SIZE;
			}

			pos.y += G_END_GAME_BLOCK_SIZE;
			pos.x = go_blocksStart.x;
		}
	}
}