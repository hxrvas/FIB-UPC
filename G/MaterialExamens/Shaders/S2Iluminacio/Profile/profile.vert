#version 330 core

layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec3 color;
layout (location = 3) in vec2 texCoord;

out vec4 frontColor;
out vec2 vtexCoord;
out vec4 viewCoord;
out vec3 viewNormal;
uniform mat4 modelViewMatrix;
uniform mat4 modelViewProjectionMatrix;
uniform mat3 normalMatrix;

void main()
{
    viewCoord = modelViewMatrix * vec4(vertex, 1.);
    vec3 N = normalize(normalMatrix * normal);
    viewNormal = N;
    frontColor = vec4(1);
    gl_Position = modelViewProjectionMatrix * vec4(vertex, 1.0);
}
