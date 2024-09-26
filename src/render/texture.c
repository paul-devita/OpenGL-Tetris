#include "texture.h"

unsigned int tx_genTexture(Image* image) {
	if (!image) return 0;

	unsigned int result;

	glGenTextures(1, &result);
	glBindTexture(GL_TEXTURE_2D, result);

	glTexParameteri(result, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(result, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(result, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(result, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	int width = image->width;
	int height = image->height;
	unsigned char* data = image->data;

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	rm_freeImage(image);

	return result;
}

void tx_bindTexture(const unsigned int textureID) {
	glBindTexture(GL_TEXTURE_2D, textureID);
}