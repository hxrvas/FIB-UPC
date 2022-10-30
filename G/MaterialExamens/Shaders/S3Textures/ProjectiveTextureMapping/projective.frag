#version 330 core

in vec4 frontColor;
out vec4 fragColor;
in vec2 vtexCoord;
in vec3 N;
in float w;
uniform sampler2D sampler;
void main()
{
    fragColor = texture(sampler, vtexCoord/w)*N.z;
}
