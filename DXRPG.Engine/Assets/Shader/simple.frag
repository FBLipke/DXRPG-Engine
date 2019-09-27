#version 330

in vec4 pColor;

out vec4 outColor;

void main(void) {
	outColor = vec4(pColor.x, pColor.y, pColor.z, pColor.w);
}
