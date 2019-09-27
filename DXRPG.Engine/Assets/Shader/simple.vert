#version 330

layout (location = 0) in vec3 position;

out vec4 pColor;

uniform vec4 color;
uniform mat4 proj;
uniform mat4 view;

void main(void) {
	pColor = color;
	gl_Position =  proj * vec4(position, 1.0f);
}
