#version 330

uniform vec4 color;
uniform sampler2D tex;

in vec2 texCoordFrag;
out vec4 outColor;

void main()
{
	// Discard fragment if texture sample has alpha < 0.5
	// otherwise compose the texture sample with the fragment's interpolated color
	vec4 texColor = texture(tex, texCoordFrag);
	if(texColor.a < 0.5f)
		discard;

	if (gl_FragCoord.y <= 480)
	{
	outColor = vec4(0.7, 0.9, 1.0, 1.0)*color * texColor;
	}
	else {
	outColor = color * texColor;
	}
	
}

