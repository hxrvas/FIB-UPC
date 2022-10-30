#version 330 core

in vec4 frontColor;
out vec4 fragColor;
in vec3 vert;

uniform vec3 origin = vec3(1,0,0);
uniform vec3 axis = vec3 (0,1,0);
uniform float slice = 0.1;

void main()
{
    vec3 a = normalize(axis);
    vec3 R = origin + axis*dot(vert, a);
    int d =int(distance(vert, R)/slice);

    if (mod(d, 2) == 0)
    {
    fragColor = vec4(0, 1, 1, 1);
    }
    else
    {
        fragColor = vec4(0,0,1,1);
    }
}
