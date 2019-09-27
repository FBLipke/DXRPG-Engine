#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texcoord

out vec3 pPosition;
out vec3 pColor;

uniform vec3 color;
uniform mat4 proj;
uniform mat4 view;

void main(void) {
	pPosition = position;
	pColor = color;
	gl_Position =  proj * vec4(position, 1.0f);
}
