#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "game/game.h"

#include "util/window.h"
#include "util/time.h"

#include "render/quad.h"
#include "render/shader.h"
#include "render/texture.h"

int main(int argc, char* argv[]) {
	if (win_windowInit() < 0) { return -1; }

	float lastTime = 0;

	qd_init();
	g_init();
	tm_initTime();

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