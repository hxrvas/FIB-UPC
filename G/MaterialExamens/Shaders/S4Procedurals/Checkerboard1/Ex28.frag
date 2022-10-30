#version 330 core

in vec2 vtexCoord;
in vec4 frontColor;
out vec4 fragColor;

void main()
{
    int s = abs(int(floor(8*vtexCoord.x))%2);
    int t = abs(int(floor(8*vtexCoord.y))%2);
    if ((s) == (t))
    {
        fragColor = vec4(0.8);
    }
    
    else fragColor = vec4(0.0);
}
