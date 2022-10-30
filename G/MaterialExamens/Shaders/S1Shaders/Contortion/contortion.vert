#version 330 core

layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec3 color;
layout (location = 3) in vec2 texCoord;

out vec4 frontColor;
out vec2 vtexCoord;

uniform mat4 modelViewProjectionMatrix;
uniform mat3 normalMatrix;

uniform float pi = 3.141592;
uniform float amp = 0.5;
uniform float freq = 0.25;
uniform float time;


void main()
{
    float angle = (vertex.y-0.5)*sin(time);


    vec3 N = normalize(normalMatrix * normal);
    mat3 rotate = mat3(vec3(1, 0, 0), vec3(0, cos(angle), sin(angle)), vec3(0, -sin(angle), cos(angle)));
    
    vec3 translacio1 = vec3(0,-1,0);
    vec3 translacio2 = vec3(0,+1,0);
    frontColor = vec4(color,1.0);
    vtexCoord = texCoord;
    if(vertex.y >0.5)
    {
        gl_Position = modelViewProjectionMatrix * vec4((rotate*(vertex+translacio1))+translacio2, 1.0);
    }
    else 
    {
        gl_Position = modelViewProjectionMatrix * vec4(vertex, 1.0);
    }
} 
