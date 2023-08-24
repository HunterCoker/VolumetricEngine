#version 330 core

out vec4 FragColor;

in vec3 v_PosColor;

void main() {
	FragColor = vec4(v_PosColor, 1.0);
}