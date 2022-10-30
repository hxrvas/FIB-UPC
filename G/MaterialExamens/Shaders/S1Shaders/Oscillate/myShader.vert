#version 330 core

layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec3 color;
layout (location = 3) in vec2 texCoord;

out vec4 frontColor;
out vec2 vtexCoord;

uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat3 normalMatrix;

uniform float time;
uniform bool eyespace = true;
uniform vec3 boundingBoxMax;
uniform vec3 boundingBoxMin;
float d;
float r;
float y;

void main()
{
	r = distance(boundingBoxMax,boundingBoxMin)/2.f;
	if (eyespace) {
		vec4 aux = modelViewMatrix * vec4(vertex,1.0);
		y = aux.y;
	}
	else y = vertex.y;
	d = (r/10)*y;
    vec3 N = normalize(normalMatrix * normal);
    frontColor = vec4(color,1.0);
    vtexCoord = texCoord;
    vec3 vertexD = vertex + normal*d*sin(time);
    gl_Position = modelViewProjectionMatrix * vec4(vertexD, 1.0);
}
