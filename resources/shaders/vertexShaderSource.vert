#version 330 core

layout (location = 0) in vec2 pos;
layout (location = 1) in vec2 tex;

out vec2 texCords;

uniform mat4 model;
uniform mat4 ortho;

void main() {
	texCords = tex;
	gl_Position = ortho * model * vec4(pos, 0.0f, 1.0f);
}