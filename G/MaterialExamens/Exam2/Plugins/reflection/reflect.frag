#version 330 core

in vec2 vtexCoord;
out vec4 fragColor;

uniform sampler2D sampler0;
uniform float time;
uniform float SIZE;

void main()
{
	///*
	vec2 st = (gl_FragCoord.xy - vec2(0.5)) / SIZE;
    float a = 1.0/SIZE;
    fragColor = texture(sampler0, st);
    fragColor.rgb *= .8;
	//*/
}
