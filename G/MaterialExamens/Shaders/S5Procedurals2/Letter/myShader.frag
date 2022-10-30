#version 330 core

in vec4 frontColor;
out vec4 fragColor;

in vec2 vtexCoord;


void main()
{
	  if ((vtexCoord.x >= 0.15 && vtexCoord.x <= 0.25 && vtexCoord.y >= 0.8) || 
	  (vtexCoord.x >= 0.75 && vtexCoord.x <= 0.85 && vtexCoord.y >= 0.8)) 	{
	  		fragColor = vec4(1.,0.,0.,1.);
	  	}
	  	else if ((vtexCoord.x >= 0.15 && vtexCoord.x <= 0.25 && vtexCoord.y < 0.2) || 
	  (vtexCoord.x >= 0.75 && vtexCoord.x <= 0.85 && vtexCoord.y < 0.2)) 	{
	  		fragColor = vec4(1.,0.,0.,1.);
	  	}
	  	else if ((vtexCoord.x > 0.25 && vtexCoord.x <= 0.35 && vtexCoord.y < 0.8 && vtexCoord.y > 0.7) || (vtexCoord.x > 0.65 && vtexCoord.x <= 0.75 && vtexCoord.y < 0.8 && vtexCoord.y > 0.7))fragColor = vec4(1.,0.,0.,1.);
	  	else if ((vtexCoord.x > 0.25 && vtexCoord.x <= 0.35 && vtexCoord.y < 0.2 && vtexCoord.y > 0.3) || (vtexCoord.x > 0.65 && vtexCoord.x <= 0.75 && vtexCoord.y < 0.2 && vtexCoord.y > 0.3)) fragColor = vec4(1.,0.,0.,1.);
  
  else discard;
}
