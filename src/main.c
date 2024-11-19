#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "game/game.h"
#include "game/block.h"

#include "util/window.h"
#include "util/time.h"
#include "util/random.h"

#include "render/quad.h"
#include "render/shader.h"
#include "render/texture.h"

int main(int argc, char* argv[]) {
	//init GLFW and GLAD
	if (win_windowInit() < 0) { return -1; }

	//init header files
	qd_init();
	r_init();
	b_init();
	g_init();
	tm_initTime();

	//Game loop
	while (!glfwWindowShouldClose(window)) {
		tm_updateDeltaTime();

		g_update(tm_deltaTime());

		g_render();
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	win_windowTerminate();
	return 0;
}