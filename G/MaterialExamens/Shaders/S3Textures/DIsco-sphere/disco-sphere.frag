#version 330 core

in vec3 V;
out vec4 fragColor;
uniform sampler2D sampler;
in vec2 vtexCoord;
void main()
{
    vec3 normal=normalize(cross(dFdx(V), dFdy(V)));
    fragColor = abs((texture(sampler, normal.xy))*normal.z);
}
