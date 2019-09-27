#version 330

in vec2 texCoord;
out vec4 outColor;

uniform sampler2D pTexture;

void main(void) {
	outColor = texture(pTexture, texCoord);
}
