#include "shader.h"

unsigned int genShaderProgram(const char* vPath, const char* fPath) {
	char* vShaderSource = rm_readTextFile(vPath);
	
	char buffer[INFO_BUFFER_SIZE];
	int success;

	unsigned int vShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vShader, 1, &vShaderSource, NULL);
	glCompileShader(vShader);
	
	rm_freeTextFile(vShaderSource);

	glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(vShader, INFO_BUFFER_SIZE, NULL, buffer);
		printf("ERROR: failed to compile vertex shader\n%s\n", buffer);
		return 0;
	}

	char* fShaderSource = rm_readTextFile(fPath);

	unsigned int fShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fShader, 1, &fShaderSource, NULL);
	glCompileShader(fShader);
	
	rm_freeTextFile(fShaderSource);

	glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(fShader, INFO_BUFFER_SIZE, NULL, buffer);
		printf("ERROR: failed to compile fragment shader\n%s\n", buffer);
		return 0;
	}

	unsigned int shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vShader);
	glAttachShader(shaderProgram, fShader);
	glLinkProgram(shaderProgram);

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

	if (!success) {
		glGetProgramInfoLog(shaderProgram, INFO_BUFFER_SIZE, NULL, buffer);
		printf("ERROR: failed to compile fragment shader\n%s\n", buffer);
		return 0;
	}

	glDeleteShader(vShader);
	glDeleteShader(fShader);

	return shaderProgram;
}

void useShaderProgram(unsigned int shaderID) {
	glUseProgram(shaderID);
}

void modifyShaderUniformf(const unsigned int shaderID, const char* name, const float* value, ubyte count) {
	int location = glGetUniformLocation(shaderID, name);
	
	switch (count) {
		case 1:
			glUniform1f(location, *value);
			break;
		case 2:
			glUniform2f(location, value[0], value[1]);
			break;
		case 3:
			glUniform3f(location, value[0], value[1], value[2]);
			break;
		case 4:
			glUniform4f(location, value[0], value[1], value[2], value[3]);
			break;
	}
}

void modifyShaderUniformi(const unsigned int shaderID, const char* name, const int* value, ubyte count) {
	int location = glGetUniformLocation(shaderID, name);

	switch (count) {
		case 1:
			glUniform1i(location, *value);
			break;
		case 2:
			glUniform2i(location, value[0], value[1]);
			break;
		case 3:
			glUniform3i(location, value[0], value[1], value[2]);
			break;
		case 4:
			glUniform4i(location, value[0], value[1], value[2], value[3]);
			break;
	}
}

void modifyShaderUniformMatrix4x4(const unsigned int shaderID, const char* name, const mat4* matrix) {
	int location = glGetUniformLocation(shaderID, name);

	float values[4][4];

	for (ubyte r = 0; r < SIZE_M4; r++) {
		for (ubyte c = 0; c < SIZE_M4; c++) {
			values[c][r] = matrix->values[r][c];
		}
	}

	glUniformMatrix4fv(location, 1, GL_FALSE, values);
}