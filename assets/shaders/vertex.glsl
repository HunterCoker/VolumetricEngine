#version 330 core

layout (location = 0) in vec3 a_Pos;
layout (location = 1) in vec3 a_Color;
layout (location = 2) in vec2 a_TexCoord;
layout (location = 3) in float a_TexID;

uniform mat4 u_ProjView;

out vec3 v_PosColor;

void main() {
    gl_Position = u_ProjView * vec4(a_Pos, 1.0);
    v_PosColor = a_Color;
}