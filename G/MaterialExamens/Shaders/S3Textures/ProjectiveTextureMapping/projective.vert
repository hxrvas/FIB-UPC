
#version 330 core

layout (location=0) in vec3 vertex;
layout (location=1) in vec3 normal;

out vec3 N;
out vec2 vtexCoord;
out float w;
uniform mat4 modelViewProjectionMatrix;
uniform mat3 normalMatrix;

void main() {
  vec4 PC=modelViewProjectionMatrix*vec4(vertex, 1);
  PC = 0.5*PC+vec4(0.5);
  w = PC.w;
  vtexCoord=PC.xy;
  N=normalize(normalMatrix*normal);
  gl_Position=modelViewProjectionMatrix*vec4(vertex, 1);
}
