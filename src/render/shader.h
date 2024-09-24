#ifndef _SHADER_H_
#define _SHADER_H_

#include <glad/glad.h>

#include "../util/resourceManager.h"

#define INFO_BUFFER_SIZE 512

#define UNIFORM_INT 0
#define UNIFORM_FLOAT 1

#define UNIFORM_MAT4 2

/*
Creates a shader program containing the source code of the provided vertex and fragment shader files.
Returns the ID of the shader upon succes or 0 upon failure.
*/
unsigned int genShaderProgram(const char* vPath, const char* fPath);

/*
Tells OpenGL to use the shader corresponding to the given ID
*/
void useShaderProgram(const unsigned int shaderID);

/*
Modifies the value of the specified uniform according to the name of the uniform, type specified, value, and count provided.
*/
void modifyShaderUniform(const unsigned int shaderID, const char* name, const unsigned char type, void* value, unsigned char count);

#endif