#version 330 core

uniform mat4 u_modelMatrix;

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

void main()
{
    gl_Position = u_modelMatrix*vec4(aPos, 1.0);
}