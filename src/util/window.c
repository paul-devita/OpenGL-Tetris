#include "window.h"

GLFWwindow* window = NULL;

void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

int windowInit() {
	if (!glfwInit()) {
		updateWindowErrorLog(GLFW_INIT_ERROR);
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GLFW_MAJOR_VERSION);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GLFW_MINOR_VERSION);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, SCR_TITLE, NULL, NULL);

	if (!window) {
		updateWindowErrorLog(GLFW_WINDOW_ERROR);
		return -2;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		updateWindowErrorLog(GLAD_LOAD_ERROR);
		return -3;
	}

	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);

	return 1;
}

void windowTerminate() {
	clearWindowErrorLog();

	glfwTerminate();
}

//------------------------------------------------------------------------------------

void updateWindowErrorLog(const char* message) {
	size_t length = 1;

	for (char* c = message; *c != '\0'; c++)
		length++;

	free(errorLog);

	errorLog = malloc(sizeof(char) * length);

	if (!errorLog) {
		fprintf(stderr, "ERROR: out of memory\n");
		return;
	}

	for (int i = 0; i < length; i++) {
		char c = message[i];

		errorLog[i] = c;
	}
}

char* getWindowError() {
	return errorLog;
}

void clearWindowErrorLog() {
	free(errorLog);
}