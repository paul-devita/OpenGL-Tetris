#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdio.h>

#include "util/window.h"

int main(int argc, char* argv[]) {
	if (windowInit() < 0) {
		char* errorLog = getWindowError();
		printf(errorLog);
		clearWindowErrorLog();
		return -1;
	}

	while (!glfwWindowShouldClose(window)) {
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	windowTerminate();
	return 0;
}