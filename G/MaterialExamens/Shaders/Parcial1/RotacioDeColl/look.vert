#version 330 core

layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec3 color;
layout (location = 3) in vec2 texCoord;

out vec4 frontColor;
out vec2 vtexCoord;

uniform mat4 modelViewProjectionMatrix;
uniform mat3 normalMatrix;
uniform vec2 mousePosition; 
uniform float mouseOverrideX = -1.;
uniform vec2 viewport = vec2(800,600); // width & height 

float angle;
vec3 vertexR, normalR;

void main()
{
	if (mouseOverrideX < 0.) {
		//l'angle estara en radiants entre -1 i 1
		angle = ((mousePosition.x*2.)/viewport.x)-1.;
	}
	else {
		angle = ((mouseOverrideX*2.)/viewport.x)-1.;
	}
	
	mat3 rotate = mat3(vec3(cos(angle),0,-sin(angle)),vec3(0,1,0),vec3(sin(angle),0,cos(angle)));
	
	if (vertex.y >= 1.45) {
		vertexR = rotate*vertex;
		float t = smoothstep(1.45,1.55,vertex.y);
		vertexR = mix(vertex,vertexR,t);
		normalR = rotate*normal;
		normalR = mix(normal,normalR,t);
	}
	else {
		normalR = normal;
		vertexR = vertex;
	}
	
	//passem a eye space
	vec3 N = normalize(normalMatrix * normalR);
	
	frontColor = vec4(N.z,N.z,N.z,1.0);
	
    gl_Position = modelViewProjectionMatrix * vec4(vertexR, 1.0);
}
