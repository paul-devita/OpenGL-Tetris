#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include <glad/glad.h>

#include "../util/resourceManager.h"

#define TX_TRUE 1
#define TX_FALSE 0

/*
Creates and returns the ID of a texture in OpenGL.
*/
unsigned int tx_genTexture(const char* path, const unsigned char alpha);

/*
Binds the texture corresponding to the provided textureID.
*/
void tx_bindTexture(const unsigned int textureID);

/*
Sets the active texture
*/
void tx_activeTexture(const unsigned char index);

#endif