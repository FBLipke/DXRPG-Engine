#version 330

in vec3 pPosition;
in vec3 pColor;

out vec4 outColor;

void main(void) {
	outColor = vec4(pColor.x, pColor.y, pColor.z, 1.0f);
}
