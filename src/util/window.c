#include "window.h"

unsigned char keys[KEY_COUNT / (sizeof(unsigned char) * 8)];

GLFWwindow* window = NULL;

void win_framebufferSizeCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void win_keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
	if (key >= 0 && key <= KEY_COUNT) {
		int index = (key / (sizeof(unsigned char) * 8)) - 1;
		int bit = key % (sizeof(unsigned char) * 8);

		unsigned char setBit = 0x1 << bit;

		printf("Found index '%d' and bit '%d' for key '%d'\n", index, bit, key);

		if (action == GLFW_PRESS) {
			keys[index] = (unsigned char)keys[index] | setBit;
		}
		else if (action == GLFW_RELEASE) {
			setBit = ~setBit;
			keys[index] = (unsigned char)keys[index] & setBit;
		}
	}
}

unsigned char win_checkKey(int key) {
	int index = (key / (sizeof(unsigned char) * 8)) - 1;
	int bit = key % (sizeof(unsigned char) * 8);

	unsigned char mask = 0x1 << bit;
	unsigned char result = (unsigned char)keys[index] & mask;

	printf("checked key '%d' found '%d'\n", key, result);

	return result;
}

signed char win_windowInit() {
	if (!glfwInit()) {
		printf("ERROR: failed to init GLFW\n");
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GLFW_MAJOR_VERSION);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GLFW_MINOR_VERSION);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, SCR_TITLE, NULL, NULL);

	if (!window) {
		printf("ERROR: failed to create GLFW window\n");
		return -2;
	}

	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window, win_keyCallback);
	glfwSetFramebufferSizeCallback(window, win_framebufferSizeCallback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		printf("ERROR: failed to load GLAD\n");
		return -3;
	}

	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);

	for (unsigned short i = 0; i < KEY_COUNT / (sizeof(unsigned char) * 8); i++)
		keys[i] = 0x00;

	return 1;
}

void win_clear() {
	glClear(GL_COLOR_BUFFER_BIT);
}

void win_windowTerminate() {
	glfwTerminate();
}