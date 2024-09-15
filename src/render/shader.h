#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

#include "../util/resourceManager.h"

#define INFO_BUFFER_SIZE 512

#define U_INT 0
#define U_FLOAT 1

unsigned int genShaderProgram(const char* vPath, const char* fPath);

void useShaderProgram(const unsigned int shaderID);

void modifyShaderUniform(const unsigned int shaderID, const unsigned char type, void* value);

#endif