#include "game.h"

void g_init() {
	shaderID = sh_genShaderProgram("../resources/shaders/vertexShaderSource.vert", "../resources/shaders/fragmentShaderSource.frag");

	sh_useShaderProgram(shaderID);

	mat4 ortho = m4_ortho2D(SCR_WIDTH, SCR_HEIGHT);

	int i = 0;

	sh_modifyShaderUniformi(shaderID, "image", &i, 1);
	sh_modifyShaderUniformMatrix4x4(shaderID, "ortho", &ortho);

	textureID = tx_genTexture("../resources/textures/awesomeface.png", TX_TRUE);
}

void g_processInput(float deltaTime) {

}

void g_processGameTic(float deltaTime) {

}

void g_render() {
	vec2 pos = { 300, 300 };
	vec2 scale = { 100, 100 };

	vec3 color = { 0, 1, 0 };

	qd_drawRect(shaderID, textureID, pos, scale, 45, color);
}