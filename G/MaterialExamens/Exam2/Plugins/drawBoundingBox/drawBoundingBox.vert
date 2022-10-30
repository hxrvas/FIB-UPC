#version 330 core
layout (location = 0) in vec3 vertex;
uniform mat4 modelViewProjectionMatrix;
uniform vec3 translate;
uniform vec3 scale;

vec3 translateb = vec3(0.5,0.,0.5);
void main()
{
    vec3 V = vertex-translateb;
    V = V*scale;
    V = V+translate;

	gl_Position    = modelViewProjectionMatrix * vec4(V,1.0);
}

