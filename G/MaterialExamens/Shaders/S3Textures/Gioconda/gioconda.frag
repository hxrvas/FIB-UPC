#version 330 core

in vec4 frontColor;
out vec4 fragColor;
in vec2 vtexCoord;
uniform sampler2D sampler;
uniform float time;

vec2 ull = vec2(0.393, 0.652);
vec2 offset = vec2(0.057, -0.172);
float radi = 0.025;

void main()
{
    float d = distance(vtexCoord, ull);
    if(fract(time) <= 0.5)
    {
        fragColor = texture(sampler, vtexCoord);
    }
    else
    {
        if (d <= radi)
        {
            fragColor = texture(sampler, vtexCoord+offset);
        }
        else fragColor = texture(sampler, vtexCoord);
    }
}
