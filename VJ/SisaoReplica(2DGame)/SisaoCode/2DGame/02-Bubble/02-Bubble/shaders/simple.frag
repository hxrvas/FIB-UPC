#version 330

uniform vec4 color;

out vec4 outColor;

void main()
{
	if (gl_FragCoord.y <= 480)
	{
	outColor = vec4(0.7, 0.9, 1.0, 1.0)*color * texColor;
	}
	else {
	outColor = color * texColor;
	}
}
