#version 330 core

layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec3 color;
layout (location = 3) in vec2 texCoord;

out vec2 vtexCoord;

out vec4 vertexClipping;

uniform mat4 modelViewProjectionMatrix;
uniform mat3 normalMatrix;

void main()
{
    vtexCoord = vec2(texCoord.s, texCoord.t);
    gl_Position = modelViewProjectionMatrix * vec4(vec3(vertex.x,vertex.y*0.5, vertex.z), 1.0);
}
