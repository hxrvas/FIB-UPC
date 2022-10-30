#version 330 core

out vec4 fragColor;

in vec2 vtexCoord;
in vec4 vertexClipping;

uniform sampler2D digits;

void main()
{
	
	vec2 texCoord = vtexCoord;

	if (vtexCoord.x <= 0.17f) {
		texCoord.x = 0.4f + vtexCoord.x*(6.f/10.f);
		fragColor = texture(digits,texCoord);
		if (fragColor.a < 0.5f) discard;
		else fragColor = vec4(0.,0.,1.,1.);
	}
	
	else if ((vtexCoord.x > 0.17f) && (vtexCoord.x <= 0.33f)) {
	//el desplaçament es -0.1 perque ja començarem aquesta cantitat adelantats
		texCoord.x = 0.5f + vtexCoord.x*(6.f/10.f);
		fragColor = texture(digits,texCoord);
		if (fragColor.a < 0.5f) discard;
		else fragColor = vec4(0.,0.,1.,1.);
	}
	
	else if ((vtexCoord.x > 0.33f) && (vtexCoord.x <= 0.5f)) {
		texCoord.x = 0.f + vtexCoord.x*(6.f/10.f);
		fragColor = texture(digits,texCoord);
		if (fragColor.a < 0.5f) discard;
		else fragColor = vec4(0.,0.,1.,1.);
	}
	
	else if ((vtexCoord.x > 0.5f) && (vtexCoord.x <= 0.67f)) {
		texCoord.x = 0.5f + vtexCoord.x*(6.f/10.f);
		fragColor = texture(digits,texCoord);
		if (fragColor.a < 0.5f) discard;
		else fragColor = vec4(0.,0.,1.,1.);
	}
	
	else if ((vtexCoord.x > 0.67f) && (vtexCoord.x <= 0.83f)) {
		texCoord.x = 0.f + vtexCoord.x*(6.f/10.f);
		fragColor = texture(digits,texCoord);
		if (fragColor.a < 0.5f) discard;
		else fragColor = vec4(0.,0.,1.,1.);
	}
	
	else if ((vtexCoord.x > 0.83f) && (vtexCoord.x <= 1.0f)){
		texCoord.x = 0.2f + vtexCoord.x*(6.f/10.f);
		fragColor = texture(digits,texCoord);
		if (fragColor.a < 0.5f) discard;
		else fragColor = vec4(0.,0.,1.,1.);
	}

}
