#include "quad.h"

void qd_init() {
	unsigned int tex_VBO;
	unsigned int solid_VBO;

	mat4 ortho = m4_ortho2D(SCR_WIDTH, SCR_HEIGHT);

	const float tex_vertices[] = {
		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,

		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f,
		1.0f, 1.0f, 1.0f, 1.0f
	};

	const float solid_vertices[] = {
		0.0f, 1.0f,
		1.0f, 0.0f,
		0.0f, 0.0f,

		0.0f, 1.0f,
		1.0f, 0.0f,
		1.0f, 1.0f
	};

	glGenVertexArrays(1, &tex_VAO);
	glBindVertexArray(tex_VAO);

	glGenBuffers(1, &tex_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, tex_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(tex_vertices), tex_vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	texShaderID = sh_genShaderProgram(TEX_VERTEX_SHADER_PATH, TEX_FRAGMENT_SHADER_PATH);

	sh_useShaderProgram(texShaderID);

	int i = 0;

	sh_modifyShaderUniformi(texShaderID, "image", &i, 1);
	sh_modifyShaderUniformMatrix4x4(texShaderID, "ortho", &ortho);

	glGenVertexArrays(1, &solid_VAO);
	glBindVertexArray(solid_VAO);

	glGenBuffers(1, &solid_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, solid_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(solid_vertices), solid_vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	solidShaderID = sh_genShaderProgram(SOLID_VERTEX_SHADER_PATH, SOLID_FRAGMENT_SHADER_PATH);

	sh_useShaderProgram(solidShaderID);

	sh_modifyShaderUniformMatrix4x4(solidShaderID, "ortho", &ortho);
}

void qd_drawTexturedRect(unsigned int textureID, vec2 position, vec2 scale, float rotation_deg, vec3 color) {
	sh_useShaderProgram(texShaderID);

	mat4 model = IDENTITY_M4;

	model = m4_translate(&model, v3_new(position.x, position.y, (float) 1));
	model = m4_rotate(&model, rotation_deg, AXIS_Z_V3);
	model = m4_translate(&model, v3_new(-scale.x / (double) 2, -scale.y / (double) 2, (float) 0));
	model = m4_scale(&model, v3_new(scale.x, scale.y, (float) 1));

	sh_modifyShaderUniformMatrix4x4(texShaderID, "model", &model);
	sh_modifyShaderUniformf(texShaderID, "spriteColor", v3_asArray(&color), SIZE_V3);

	tx_activeTexture(0);
	tx_bindTexture(textureID);

	glBindVertexArray(tex_VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}

void qd_drawSolidRect(vec2 position, vec2 scale, float rotation_deg, vec3 color) {
	sh_useShaderProgram(solidShaderID);

	mat4 model = IDENTITY_M4;

	model = m4_translate(&model, v3_new(position.x, position.y, (float) 1));
	model = m4_rotate(&model, rotation_deg, AXIS_Z_V3);
	model = m4_translate(&model, v3_new(-scale.x / (double) 2, -scale.y / (double) 2, (float) 0));
	model = m4_scale(&model, v3_new(scale.x, scale.y, (float) 1));

	sh_modifyShaderUniformMatrix4x4(solidShaderID, "model", &model);
	sh_modifyShaderUniformf(solidShaderID, "solidColor", v3_asArray(&color), SIZE_V3);

	glBindVertexArray(solid_VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}

void qd_drawOutlineRect(vec2 position, vec2 scale, float strokeWidth, vec3 color) {
	vec2 p, s;
	
	float swm2 = strokeWidth * 2;
	float swd2 = strokeWidth / (float)2;

	float dx = (scale.x / (float)2) - swd2;
	float dy = (scale.y / (float)2) - swd2;

	//Top
	p.x = position.x;
	p.y = position.y - dy;

	if (p.y < position.y - (scale.y / (float)2)) {
		qd_drawSolidRect(position, scale, 0, color);
		return;
	}

	s.x = scale.x - swm2;
	s.y = strokeWidth;
	qd_drawSolidRect(p, s, 0, color);

	//Bottom
	p.x = position.x;
	p.y = position.y + dy;

	if (p.y > position.y + (scale.y / (float)2)) {
		qd_drawSolidRect(position, scale, 0, color);
		return;
	}

	s.x = scale.x - swm2;
	s.y = strokeWidth;
	qd_drawSolidRect(p, s, 0, color);

	//Left
	p.x = position.x - dx;

	if (p.x < position.x - (scale.x / (float)2)) {
		qd_drawSolidRect(position, scale, 0, color);
		return;
	}

	p.y = position.y;
	s.x = strokeWidth;
	s.y = scale.y;
	qd_drawSolidRect(p, s, 0, color);

	//Right
	p.x = position.x + dx;

	if (p.x > position.x + (scale.x / (float)2)) {
		qd_drawSolidRect(position, scale, 0, color);
		return;
	}

	p.y = position.y;
	s.x = strokeWidth;
	s.y = scale.y;
	qd_drawSolidRect(p, s, 0, color);
}