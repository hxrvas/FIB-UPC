#version 330 core

in vec4 frontColor;
out vec4 fragColor;

uniform sampler2D explosion;
in vec2 vtexCoord;
uniform float time;


void main()
{

    vec2 oset = vec2((0%8)*1./8., (0%6)*1./6.);

    fragColor = texture(explosion, vec2(vtexCoord.s/8, (vtexCoord.t/6)+oset));
    fragColor = fragColor.a*fragColor;
}
 
