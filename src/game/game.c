#include "game.h"

vec2 pos = { SCR_WIDTH / 2, SCR_HEIGHT / 2 };
vec2 scale = { 150, 150 };

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
	if (win_checkKey(GLFW_KEY_W)) 
		pos.y -= 25;
	if (win_checkKey(GLFW_KEY_S))
		pos.y += 25;
	if (win_checkKey(GLFW_KEY_D))
		pos.x += 25;
	if (win_checkKey(GLFW_KEY_A))
		pos.x -= 25;

	if (win_checkKey(GLFW_KEY_E)) {
		scale.x += 25;
		scale.y += 25;
	}
	if (win_checkKey(GLFW_KEY_Q)) {
		scale.x -= 25;
		scale.y -= 25;
	}
}

void g_processGameTic(float deltaTime) {

}

void g_render() {
	vec3 color = { 0, 1, 0 };

	qd_drawRect(shaderID, textureID, pos, scale, 0, color);
}