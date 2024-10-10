#include "texture.h"

unsigned int tx_genTexture(const char* path, const unsigned char alpha) {
    Image image = rm_readImageFile(path, alpha);

	unsigned int result;

	glGenTextures(1, &result);
	glBindTexture(GL_TEXTURE_2D, result);

	glTexParameteri(result, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(result, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(result, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(result, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	int width = image.width;
	int height = image.height;
	unsigned char* data = image.data;

    int internalFormat;
    int imageFormat;

    if (alpha) {
        internalFormat = GL_RGBA;
        imageFormat = GL_RGBA;
    }
    else {
        internalFormat = GL_RGB;
        imageFormat = GL_RGB;
    }

	glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, imageFormat, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	rm_freeImageData(&image);

	return result;
}

void tx_bindTexture(const unsigned int textureID) {
	glBindTexture(GL_TEXTURE_2D, textureID);
}

void tx_activeTexture(const unsigned char index) {
    switch (index) {
        case 0:
            glActiveTexture(GL_TEXTURE0);
            break;
        case 1:
            glActiveTexture(GL_TEXTURE1);
            break;
        case 2:
            glActiveTexture(GL_TEXTURE2);
            break;
        case 3:
            glActiveTexture(GL_TEXTURE3);
            break;
        case 4:
            glActiveTexture(GL_TEXTURE4);
            break;
        case 5:
            glActiveTexture(GL_TEXTURE5);
            break;
        case 6:
            glActiveTexture(GL_TEXTURE6);
            break;
        case 7:
            glActiveTexture(GL_TEXTURE7);
            break;
        case 8:
            glActiveTexture(GL_TEXTURE8);
            break;
        case 9:
            glActiveTexture(GL_TEXTURE9);
            break;
        case 10:
            glActiveTexture(GL_TEXTURE10);
            break;
        case 11:
            glActiveTexture(GL_TEXTURE11);
            break;
        case 12:
            glActiveTexture(GL_TEXTURE12);
            break;
        case 13:
            glActiveTexture(GL_TEXTURE13);
            break;
        case 14:
            glActiveTexture(GL_TEXTURE14);
            break;
        case 15:
            glActiveTexture(GL_TEXTURE15);
            break;
        case 16:
            glActiveTexture(GL_TEXTURE16);
            break;
        default:
            break;
    }
}