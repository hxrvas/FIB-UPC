#version 330 core

in vec2 vtexCoord;
in vec4 frontColor;
out vec4 fragColor;

uniform float n = 8;

void main()
{
    int s = abs(int(floor(n*vtexCoord.x))%2);
    int t = abs(int(floor(n*vtexCoord.y))%2);
    if ((s) == (t))
    {
        fragColor = vec4(0.8);
    }
    
    else fragColor = vec4(0.0);
}
