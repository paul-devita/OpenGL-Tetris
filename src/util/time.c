#include "time.h"

static double prevTime = 0;
static double dTime = 0;

void tm_initTime() {
	double currentTime = glfwGetTime();

	prevTime = currentTime;
}

void tm_updateDeltaTime() {
	double currentTime = glfwGetTime();

	dTime = currentTime - prevTime;
	prevTime = currentTime;
}

double tm_deltaTime() {
	return dTime;
}