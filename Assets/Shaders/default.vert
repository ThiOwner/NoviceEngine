#version 330 core

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

out vec3 vNormal;
out vec3 vPosition;

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

void main()
{
    mat3 normalMatrix = transpose(inverse(mat3(u_view * u_model)));

    vNormal = normalMatrix * aNormal;
    vPosition = vec3(u_view * u_model * vec4(aPos, 1.0));

    gl_Position = u_projection * u_view * u_model * vec4(aPos, 1.0);
}