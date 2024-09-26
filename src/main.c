#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "util/window.h"
#include "util/time.h"


int main(int argc, char* argv[]) {
	if (windowInit() < 0) { return -1; }

	initTime();

	while (!glfwWindowShouldClose(window)) {
		updateDeltaTime();
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	windowTerminate();
	return 0;
}