#version 330 core

in vec4 frontColor;
out vec4 fragColor;
in vec2 vtexCoord;
uniform int textureSize = 1024;
uniform int edgeSize = 1;
uniform float threshold = 0.05;
uniform sampler2D tex;

vec4 left;
vec4 right;
vec4 top;
vec4 bot;

void main()
{
    left = texture(tex, vtexCoord + edgeSize*vec2(-1,0)/textureSize);
    right = texture(tex, vtexCoord + edgeSize*vec2(1,0)/textureSize);
    bot = texture(tex, vtexCoord + edgeSize*vec2(0,-1)/textureSize);
    top = texture(tex, vtexCoord + edgeSize*vec2(0,1)/textureSize);

    float GX = distance(right, left);
    float GY = distance(top, bot);

    float x = length(vec2(GX, GY));

    if ( x > threshold)
    {
        fragColor = vec4(0);
    }
    else {
        fragColor = texture(tex, vtexCoord);
    }
}
