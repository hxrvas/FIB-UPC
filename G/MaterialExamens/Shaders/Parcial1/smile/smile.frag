#version 330 core

out vec4 fragColor;
in vec2 vtexCoord;
in vec3 N;

uniform sampler2D colormap;

const float radi = 0.05;

void main()
{
    vec2 C1 = vec2(0.34,0.65)-0.1*N.xy;
    vec2 C2 = vec2(0.66,0.65)-0.1*N.xy;
    
    float d1 = distance(vtexCoord,C1);
    float d2 = distance(vtexCoord,C2);
    if (d1 <= radi || d2 <= radi) fragColor=vec4(0);
    else fragColor = texture(colormap, vtexCoord);
}
