#version 330 core

layout (location = 0) in vec4 data;

out vec2 texCords;

uniform mat4 model;
uniform mat4 ortho;

void main() {
	texCords = data.zw;
	gl_Position = ortho * model * vec4(data.xy, 0.0f, 1.0f);
}