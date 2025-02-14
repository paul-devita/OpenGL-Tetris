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
unsigned int sh_genShaderProgram(const char* vPath, const char* fPath);

/*
Tells OpenGL to use the shader corresponding to the given ID
*/
void sh_useShaderProgram(const unsigned int shaderID);

/*
Modifies the specified float uniform.
Count specifies how many values are passed to a given uniform.
*/
void sh_modifyShaderUniformf(const unsigned int shaderID, const char* name, const float* value, ubyte count);

/*
Modifies the specified int uniform.
Count specifies how many values are passed to a given uniform.
*/
void sh_modifyShaderUniformi(const unsigned int shaderID, const char* name, const int* value, ubyte count);

/*
Modifies the specified mat4 uniform by passing a pointer to a mat4 struct.
The Matrix is converted from the C-standard row-major ordering to OpenGL compatible column-major ordering before passing the matrix to the uniform.
*/
void sh_modifyShaderUniformMatrix4x4(const unsigned int shaderID, const char* name, const mat4* matrix);

#endif