#version 330 core

layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec3 color;
layout (location = 3) in vec2 texCoord;

out vec4 frontColor;
out vec2 vtexCoord;

uniform mat4 modelViewProjectionMatrix;
uniform mat3 normalMatrix;

uniform float time;

float scale;

void main()
{
	scale = 0.5+abs(sin(time));
    vec3 N = normalize(normalMatrix * normal);
    frontColor = vec4(color,1.0) * N.z;
    vtexCoord = texCoord;
    //calculem les coordenades en NDC fent perspective division
    vec4 vertexNDC = modelViewProjectionMatrix * vec4(vertex, 1.0);
    vertexNDC = vec4(vertexNDC.x*scale/vertexNDC.w,vertexNDC.y*scale/vertexNDC.w,vertexNDC.z/vertexNDC.w,1.0);
    gl_Position = vertexNDC;
}
