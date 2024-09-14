#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readShader(char* path) {
	FILE* file_ptr;
	char buffer[250];
	char* dest = NULL;

	file_ptr = fopen(path, "r");

	if (file_ptr == NULL) {
		fprintf(stderr, "ERROR::SHADER::UNABLE_TO_READ_FILE\n");
		return NULL;
	}

	if (fgets(buffer, 250, file_ptr) != NULL) {

		int len = strlen(buffer);

		dest = malloc(len * sizeof(char));

		if (dest == NULL) {
			fprintf(stderr, "ERROR::SHADER::UNABLE_TO_ALLOCATE_MEMORY\n");
			return NULL;
		}

		strncpy(dest, buffer, len);

		while (fgets(buffer, 250, file_ptr) != NULL) {
			int prev_len = len;
			int cur_len = strlen(buffer);
			len += cur_len;

			char* old_block = dest;
			dest = realloc(dest, len * sizeof(char));

			if (dest == NULL) {
				fprintf(stderr, "ERROR::SHADER::UNABLE_TO_ALLOCATE_MEMORY\n");
				free(old_block);
				return NULL;
			}

			char* c = dest + prev_len;

			strncpy(c, buffer, cur_len);
		}

		char* old_block = dest;
		dest = realloc(dest, (len + 1) * sizeof(char));

		if (dest == NULL) {
			fprintf(stderr, "ERROR::SHADER::UNABLE_TO_ALLOCATE_MEMORY\n");
			free(old_block);
			return NULL;
		}

		dest[len] = '\0';
	}

	fclose(file_ptr);
	return dest;
}

unsigned int genShaderProgram(char* vertexShaderSourcePath, char* fragmentShaderSourcePath) {
	char *vertexShaderSource = readShader(vertexShaderSourcePath);
	char *fragmentShaderSource = readShader(fragmentShaderSourcePath);

	int success;
	char buffer[512];

	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, buffer);
		fprintf(stderr, "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s\n", buffer);
		return -1;
	}

	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, buffer);
		fprintf(stderr, "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n%s\n", buffer);
		return -1;
	}

	unsigned int shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, buffer);
		fprintf(stderr, "ERROR::SHADER::PROGRAM::LINKING_FAILED\n%s\n", buffer);
		return -1;
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	free(vertexShaderSource);
	free(fragmentShaderSource);

	return shaderProgram;
}


#endif
