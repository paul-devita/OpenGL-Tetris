#ifndef _TIME_H_
#define _TIME_H_

#include <GLFW/glfw3.h>

static double prevTime;
static double dTime;

/*
Initializes the timing functionality for the game.
*/
void tm_initTime();

/*
Updates the timing values of the game.
Called at the start of every frame.
*/
void tm_updateDeltaTime();

/*
Returns the time difference between the last frame and the current frame.
*/
double tm_deltaTime();

#endif