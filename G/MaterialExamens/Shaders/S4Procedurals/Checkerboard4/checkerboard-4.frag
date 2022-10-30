#version 330 core

in vec2 vtexCoord;
in vec4 frontColor;
out vec4 fragColor;

uniform float n = 10 ;

void main()
{
    int s = abs(int(floor(n*10*vtexCoord.x))%10);
    int t = abs(int(floor(n*10*vtexCoord.y))%10);
    
    if ((s == 0) || (t == 0))
    {
        fragColor = vec4(1.0, 0, 0, 1);
    }
    
    else discard;
}
