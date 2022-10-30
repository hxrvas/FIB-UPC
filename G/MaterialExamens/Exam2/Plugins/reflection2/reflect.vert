#version 330 core

layout (location = 0) in vec3 vertex;
layout (location = 1) in vec2 texCoord;
//layout (location = 2) in vec3 normal;
//layout (location = 3) in vec3 color;
out vec2 vtexCoord;

uniform mat4 modelViewProjectionMatrix;
uniform vec3 bbmin;
uniform vec3 bbmax;

void main()
{
    //vtexCoord = texCoord;
    gl_Position = modelViewProjectionMatrix * vec4(vertex, 1.0);
}
