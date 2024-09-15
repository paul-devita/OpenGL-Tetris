#include "shader.h"

unsigned int genShaderProgram(const char* vPath, const char* fPath) {
	char* vShaderSource = readTextFile(vPath);
	
	char buffer[INFO_BUFFER_SIZE];
	int success;

	unsigned int vShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vShader, 1, &vShaderSource, NULL);
	glCompileShader(vShader);
	free(vShaderSource);

	glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(vShader, INFO_BUFFER_SIZE, NULL, buffer);
		printf("ERROR: failed to compile vertex shader\n%s\n", buffer);
		return 0;
	}

	char* fShaderSource = readTextFile(fPath);

	unsigned int fShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fShader, 1, &fShaderSource, NULL);
	glCompileShader(fShader);
	free(fShaderSource);

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

void useShaderProgram(const unsigned int shaderID) {
	glUseProgram(shaderID);
}

void modifyShaderUniform(const unsigned int shaderID, const unsigned char type, void* value) {

}