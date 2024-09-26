#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include <glad/glad.h>

#include "../util/resourceManager.h"

/*
Creates and returns the ID of a texture in OpenGL.
Frees the given image struct.
*/
unsigned int genTexture(Image* image);

/*
Binds the texture corresponding to the provided textureID.
*/
void bindTexture(const unsigned int textureID);

#endif