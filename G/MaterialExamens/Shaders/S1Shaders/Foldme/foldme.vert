#version 330 core

layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec3 color;
layout (location = 3) in vec2 texCoord;

out vec4 frontColor;


uniform mat4 modelViewProjectionMatrix;
uniform mat3 normalMatrix;
uniform float time;

float angle;
mat3 rot;
void main()
{
    angle = -time*texCoord.s;
    frontColor = vec4(0, 0, 1,1);
    rot = mat3(cos(angle), 0, -sin(angle), 0, 1, 0, sin(angle), 0, cos(angle));
    gl_Position = modelViewProjectionMatrix * vec4(rot*vertex, 1.0);
}
