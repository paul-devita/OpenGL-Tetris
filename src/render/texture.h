#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include <glad/glad.h>

#include "../util/resourceManager.h"

/*
Creates and returns the ID of a texture in OpenGL.
Frees the given image struct.
*/
unsigned int tx_genTexture(Image* image);

/*
Binds the texture corresponding to the provided textureID.
*/
void tx_bindTexture(const unsigned int textureID);

/*
Sets the active texture
*/
void tx_activeTexture(const unsigned char index);

#endif