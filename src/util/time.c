#include "time.h"

static float prevTime = 0;
static float dTime = 0;

void tm_initTime() {
	float currentTime = (float) glfwGetTime();

	prevTime = currentTime;
}

void tm_updateDeltaTime() {
	float currentTime = (float) glfwGetTime();

	dTime = currentTime - prevTime;
	prevTime = currentTime;
}

float tm_deltaTime() {
	return dTime;
}