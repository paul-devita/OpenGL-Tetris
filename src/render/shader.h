#ifndef _SHADER_H_
#define _SHADER_H_

#include <glad/glad.h>

#include "../util/util.h"
#include "../util/resourceManager.h"

#include "../math/mat4.h"

#define INFO_BUFFER_SIZE 512

/*
Creates a shader program containing the source code of the provided vertex and fragment shader files.
Returns the ID of the shader upon succes or 0 upon failure.
*/
unsigned int genShaderProgram(const char* vPath, const char* fPath);

/*
Tells OpenGL to use the shader corresponding to the given ID
*/
void useShaderProgram(const unsigned int shaderID);

void modifyShaderUniformf(const unsigned int shaderID, const char* name, const float* value, ubyte count);

void modifyShaderUniformi(const unsigned int shaderID, const char* name, const int* value, ubyte count);

void modiyShaderUniformMatrix4x4(const unsigned int shaderID, const char* name, const mat4 matrix);

#endif