#version 330 core

in vec4 frontColor;
out vec4 fragColor;
in vec2 vtexCoord;
vec4 red = vec4(1,0,0,1);
vec4 yellow = vec4(1,1,0,1);
float a = 1/9.0;


void main()
{

    if(fract(vtexCoord.s) < a)
    {
        fragColor = yellow;
    }
    else if( 2*a <= fract(vtexCoord.s) && fract(vtexCoord.s) < 3*a)
    {
        fragColor = yellow;
    }

    else if( 4*a <= fract(vtexCoord.s) && fract(vtexCoord.s) < 5*a)
    {
        fragColor = yellow;
    }

    else if( 6*a <= fract(vtexCoord.s) && fract(vtexCoord.s) < 7*a)
    {
        fragColor = yellow;
    }

    else if( 8*a <= fract(vtexCoord.s) && fract(vtexCoord.s) < 9*a)
    {
        fragColor = yellow;
    }

    else
    {
        fragColor =red;
    }
}
