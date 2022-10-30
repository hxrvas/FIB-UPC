#version 330 core

in vec4 frontColor;
out vec4 fragColor;
in vec2 vtexCoord;

float M_PI = 3.1416;
uniform sampler2D map;
uniform float time;
uniform float a = 0.5;

void main()
{
    vec4 color = texture(map, vtexCoord);
    float m = max(color.r, color.g);
    m = max(m, color.b);
    vec2 u = vec2(m);

    float theta = 2*M_PI*time;
    mat2 rot = mat2(cos(theta), sin(theta), -sin(theta), cos(theta));
    u = rot*u;
    vec2 offset = (a/100.0)*u;
    fragColor = texture(map, vtexCoord+offset);
}
