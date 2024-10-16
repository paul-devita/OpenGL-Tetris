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

extern unsigned char keys[KEY_COUNT / (sizeof(unsigned char) * 8)];

/*
Called by GLFW when the window is resized by the user
*/
void win_framebufferSizeCallback(GLFWwindow* window, int width, int height);

/*
Called by GLFW when a key is pressed.
Saves the key in its designated bit in keys array.
1 indicates a pressed key and 0 indicates a released key
*/
void win_keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);

/*
Checks the bit of the designated key.
Returns a value greated than 0 if the key is pressed.
Returns 0 if the key is not pressed.
*/
unsigned char win_checkKey(int key);

/*
Init GLFW and glad and save the created window in the window extern variable.
Returns a negative value on failure, and each value has a different meaning:
-1 pertains to GLFW init failure
-2 pertains to GLfW window failure
-3 pertains to GLAD load failure
*/
char win_windowInit();

/*
Clears the color buffer bit
*/
void win_clear();

/*
Closes the window and calls win_windowTerminate()
*/
void win_close();

/*
Terminates GLFW and deallocates all window-related functionality
*/
void win_windowTerminate();

#endif