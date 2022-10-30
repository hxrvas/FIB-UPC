#version 330 core

in vec4 frontColor;
out vec4 fragColor;
in vec2 vtexCoord;

vec2 centre = vec2(0.5, 0.5);
float radi = 0.2;

void main()
{
    float d=length(vec2(vtexCoord.x-0.5, vtexCoord.y-0.5));
    fragColor=vec4(1.0, vec2(smoothstep(0.2, 0.205, d)), 1.0);
}

