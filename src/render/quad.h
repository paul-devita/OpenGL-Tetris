#ifndef _QUAD_H_
#define _QUAD_H_

#include <glad/glad.h>

#include "../util/util.h"
#include "../util/window.h"

#include "../math/mat4.h"
#include "../math/vec2.h"

#include "shader.h"
#include "texture.h"

#define SOLID_VERTEX_SHADER_PATH "../resources/shaders/solidVertexShader.vert"
#define SOLID_FRAGMENT_SHADER_PATH "../resources/shaders/solidFragmentShader.frag"

#define TEX_VERTEX_SHADER_PATH "../resources/shaders/texVertexShader.vert"
#define TEX_FRAGMENT_SHADER_PATH "../resources/shaders/texFragmentShader.frag"

static unsigned int tex_VAO;
static unsigned int solid_VAO;

static unsigned int solidShaderID;
static unsigned int texShaderID;

/*
Inits the quad-drawing functionality of the library
Establishes the vertex array objects to tectured and solid color rendering
*/
void qd_init();

/*
Draws a rect and applies the given texture
*/
void qd_drawTexturedRect(unsigned int textureID, vec2 position, vec2 scale, float rotation, vec3 color);

/*
Draws a rect of a solid color
*/
void qd_drawSolidRect(vec2 position, vec2 scale, float rotation, vec3 color);

/*
Draws the outline of a rect with a given stroke thickness
Equivalent to 4 qd_drawSolidRect calls
*/
void qd_drawOutlineRect(vec2 position, vec2 scale, float strokeWidth, vec3 color);

#endif