#version 330

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texCoord;

out vec2 pTexCoord;

uniform mat4 proj;

void main(void) {
	pTexCoord = texCoord;
	gl_Position =  proj * vec4(position, 1.0f);
}
