#include "quad.h"

void qd_init() {
	unsigned int VBO;

	const float vertices[] = {
		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,

		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f,
		1.0f, 1.0f, 1.0f, 1.0f
	};

	glGenVertexArrays(1, &vertexArrayObject);
	glBindVertexArray(vertexArrayObject);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void qd_drawRect(unsigned int shaderID, unsigned int textureID, vec2 position, vec2 scale, float rotation_deg, vec3 color) {
	sh_useShaderProgram(shaderID);

	mat4 model = IDENTITY_M4;

	model = m4_translate(&model, v3_new(position.x, position.y, 1.0f));
	model = m4_rotate(&model, rotation_deg, AXIS_Z_V3);
	model = m4_translate(&model, v3_new(-scale.x / 2, -scale.y / 2, 0.0f));
	model = m4_scale(&model, v3_new(scale.x, scale.y, 1.0f));

	sh_modifyShaderUniformMatrix4x4(shaderID, "model", &model);
	sh_modifyShaderUniformf(shaderID, "spriteColor", v3_asArray(&color), SIZE_V3);

	tx_activeTexture(0);
	tx_bindTexture(textureID);

	glBindVertexArray(vertexArrayObject);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}
