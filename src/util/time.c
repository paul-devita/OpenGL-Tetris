#include "time.h"

static float prevTime = 0;
static float dTime = 0;

void initTime() {
	float currentTime = (float) glfwGetTime();

	prevTime = currentTime;
}

void updateDeltaTime() {
	float currentTime = (float) glfwGetTime();

	dTime = currentTime - prevTime;
	prevTime = currentTime;
}

float deltaTime() {
	return dTime;
}