#version 330 core
layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 normal;

out vec4 frontColor;

uniform float lambda;
uniform mat4 modelViewProjectionMatrix;
uniform mat3 normalMatrix;

vec4 RED = vec4(1,0,0,1);
vec4 GREEN = vec4(0,1,0,1);
void main()
{
    vec3 N = normalize(normal*normalMatrix);
    frontColor = mix(RED, GREEN, lambda)*N.z;
	gl_Position = modelViewProjectionMatrix * vec4(vertex,1.0);
}

