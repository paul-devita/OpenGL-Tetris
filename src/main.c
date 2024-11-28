#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "game/stateManager.h"

#include "util/window.h"
#include "util/time.h"
#include "util/random.h"
#include "util/button.h"

#include "render/quad.h"

int main(int argc, char* argv[]) {
	//init GLFW and GLAD
	if (win_windowInit() < 0) { return -1; }

	//init header files
	qd_init();
	r_init();
	bt_init();
	sm_init();
	tm_initTime();

	//Game loop
	while (!glfwWindowShouldClose(window)) {
		tm_updateDeltaTime();

		sm_update(tm_deltaTime());

		sm_fixedUpdate(tm_deltaTime());

		sm_render();
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	win_windowTerminate();
	return 0;
}