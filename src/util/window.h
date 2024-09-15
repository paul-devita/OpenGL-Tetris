#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdlib.h>
#include <stdio.h>

#define GLFW_MAJOR_VERSION 3
#define GLFW_MINOR_VERSION 3

#define SCR_WIDTH 1000
#define SCR_HEIGHT 1000

#define SCR_TITLE "Tetris"

#define KEY_COUNT 1024

extern GLFWwindow* window;

extern unsigned char* keys[KEY_COUNT / (sizeof(unsigned char) * 8)];

/*
Called by GLFW when the window is resized by the user
*/
void framebufferSizeCallback(GLFWwindow* window, int width, int height);

/*
Called by GLFW when a key is pressed.
Saves the key in its designated bit in keys array.
1 indicates a pressed key and 0 indicates a released key
*/
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);

/*
Checks the bit of the designated key.
Returns a value greated than 0 if the key is pressed.
Returns 0 if the key is not pressed.
*/
signed char checkKey(int key);

/*
Init GLFW and glad and save the created window in the window extern variable.
Returns a negative value on failure, and each value has a different meaning:
-1 pertains to GLFW init failure
-2 pertains to GLfW window failure
-3 pertains to GLAD load failure
*/
signed char windowInit();

void windowTerminate();

//------------------------------------------------------------------------------------

#define GLFW_INIT_ERROR "ERROR: failed to init GLFW\n"
#define GLFW_WINDOW_ERROR "ERROR: failed to create GLFW window\n"

#define GLAD_LOAD_ERROR "ERROR: failed to load GLAD\n"

static char* errorLog;

void updateWindowErrorLog(const char* message);

char* getWindowError();

void clearWindowErrorLog();

#endif