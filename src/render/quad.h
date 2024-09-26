#ifndef _QUAD_H_
#define _QUAD_H_

#include <glad/glad.h>

#include "../util/util.h"

#include "../math/mat4.h"
#include "../math/vec2.h"

#include "shader.h"
#include "texture.h"

static unsigned int vertexArrayObject;

void qd_init();

void qd_drawRect(unsigned int shaderID, unsigned int textureID, vec2 position, vec2 scale, float rotation, vec3 color);

#endif