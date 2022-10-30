#version 330 core

in vec4 gfrontColor;
in vec2 gtexCoord;
out vec4 fragColor;
uniform sampler2D colorMap;

void main()
{
    if (gtexCoord.s > 0)
    {
    vec4 color = texture(colorMap, gtexCoord);
    if (color.a < 0.1) discard;
    else fragColor = color*color.a;
    }
    else fragColor = gfrontColor;
}
