#version 330

in vec3 position;
out vec4 pColor;

uniform vec4 color;
uniform mat4 proj;

void main(void) {
	pColor = color;
	gl_Position =  vec4(position, 1.0f);
}
