#version 330 core

in vec4 frontColor;
out vec4 fragColor;

in vec2 vtexCoord;

float r = 0.225;
float M_PI = 3.1416;
vec2 centre = vec2(0.5f,0.5f);

vec2 centreLL = vec2(0.28,0.4);
vec2 centreLL2 = vec2(0.4,0.4);
float rLL = 0.2;

void main()
{

	//versio 1 -> NOTA SOBRE 8
	/*if (vtexCoord.x <= 0.5) {
		fragColor = vec4(0.,1.,1.,1.);
	}
	
	else {
		if (vtexCoord.y >= 0.5) {
			fragColor = vec4(1.,0.,0.,1.);
		}
		else fragColor = vec4(1.,1.,0.,1.);
	}*/
	
	
	//versio 2 -> NOTA SOBRE 9
	
	/*if (distance(centre,vec2(vtexCoord.x,vtexCoord.y*0.75+0.125)) <= r) {
		fragColor = vec4(1.,0.,0.,1.);
	}
	else {
		if (vtexCoord.y <= 0.33) fragColor = vec4(0.,0.,1.,1.);
		else if (vtexCoord.y <= 0.67 && vtexCoord.y > 0.33) fragColor = vec4(1.,1.,0.,1.);
		else fragColor = vec4(0.,0.6,0.3,1.);
	}*/
	
	//versio 3 -> NOTA SOBRE 10
	
	fragColor = vec4(0.5,0.7,0.3,1.);
	

	//per torbar les dimensions del cuadrat triemm una diferencia de x i despres
	//utilitzem la relacio de 4/3 que la multipliquem per aquesta diferencia per tal de tenir el que sumem i dividim a y
	if ((vtexCoord.x >= 0.6 && vtexCoord.x <= 0.825) && (vtexCoord.y >= 0.35 && vtexCoord.y <= 0.65)) discard;
	
	
	else if (distance(centreLL,vec2(vtexCoord.x,vtexCoord.y*0.75)) < rLL && !(distance(centreLL2,vec2(vtexCoord.x,vtexCoord.y*0.75)) < rLL)) discard;
	
	if (distance(centreLL2,vec2(vtexCoord.x,vtexCoord.y*0.75)) < rLL) fragColor = vec4(0.5,0.7,0.3,1.);
}
