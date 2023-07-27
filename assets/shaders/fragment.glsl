#version 330 core

out vec4 FragColor;

uniform vec3 u_Color;
in vec3 Normal;

uniform vec3 u_LightPos;
uniform vec3 u_LightColor;

void main() {
	// float AmbientStrength = 0.1;
	// vec3 Ambient = u_LightColor * AmbientStrength;

	FragColor = vec4(u_Color, 1.0);
}