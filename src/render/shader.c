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

void useShaderProgram(unsigned int shaderID) {
	glUseProgram(shaderID);
}

void modifyShaderUniform(unsigned int shaderID, const char* name, unsigned char type, const void* value, unsigned char count) {
	int location = glGetUniformLocation(shaderID, name);
	
	switch (type) {
		case UNIFORM_INT:
			switch (count) {
				case 1:
					glUniform1i(location, *(int*)value);
					break;
				case 2:
					glUniform2i(location, ((int*)value)[0], ((int*)value)[1]);
					break;
				case 3:
					glUniform3i(location, ((int*)value)[0], ((int*)value)[1], ((int*)value)[2]);
					break;
				case 4:
					glUniform4i(location, ((int*)value)[0], ((int*)value)[1], ((int*)value)[2], ((int*)value)[3]);
					break;
			}
			break;
		case UNIFORM_FLOAT:
			switch (count) {
				case 1:
					glUniform1f(location, *(float*)value);
					break;
				case 2:
					glUniform2f(location, ((float*)value)[0], ((float*)value)[1], ((float*)value)[2]);
					break;
				case 3:
					glUniform3f(location, ((float*)value)[0], ((float*)value)[1], ((float*)value)[2]);
					break;
				case 4:
					glUniform4f(location, ((float*)value)[0], ((float*)value)[1], ((float*)value)[2], ((float*)value)[3]);
					break;
			}
			break;
		case UNIFORM_MAT4:
			glUniformMatrix4fv(location, 1, GL_TRUE, value);
			break;
	}
}