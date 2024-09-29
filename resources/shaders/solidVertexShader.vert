#version 330 core

layout (location = 0) in vec2 pos;

uniform mat4 model;
uniform mat4 ortho;

void main() {
	gl_Position = ortho * model * vec4(pos.xy, 0.0f, 1.0f);
}