#version 330 core

in vec2 vtexCoord;
in vec4 frontColor;
out vec4 fragColor;

vec2 C = vec2(0.5, 0.5);
float radi = 0.2;
void main()
{

    float d = distance(C, vtexCoord);
    
     fragColor = vec4(smoothstep(radi-0.002, radi + 0.002, d), 0., 0., 0.);

}
