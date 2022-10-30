#version 330 core

layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec3 color;
layout (location = 3) in vec2 texCoord;


out vec2 vtexCoord;
out vec3 V;
uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat3 normalMatrix;
uniform float time;
uniform float speed = 0.5;

void main()
{

    mat3 rotate = mat3(vec3(cos(speed*time), 0, -sin(speed*time)), vec3(0, 1, 0), vec3(sin(speed*time), 0, cos(speed*time)));
    vtexCoord = texCoord;
      V = (modelViewMatrix*vec4(rotate*vertex, 1)).xyz;
    gl_Position = modelViewProjectionMatrix * vec4(rotate*vertex, 1.0);
}
