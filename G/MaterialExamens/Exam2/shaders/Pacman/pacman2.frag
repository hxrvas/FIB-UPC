#version 330 core

in vec4 frontColor;
out vec4 fragColor;
in vec2 vtexCoord;
uniform sampler2D colorman0;

float n = 15;
float x = n*vtexCoord.x;
float y = n*vtexCoord.y;

vec2 GHOST = vec2((x/6.)+(ceil(6-x))/6., y);

vec2 PACMAN = vec2((x/6.)+(ceil(7-x))/6., y);

vec2 BLACK = vec2((x/6.)+(ceil(8-x))/6., y);

vec2 LINE_H = vec2((x/6.)+(ceil(9-x))/6., y);
vec2 LINE_V = vec2((y/6.)+(ceil(9-y))/6., x);

vec2 CORNER_UR = vec2((x/6.)+(ceil(10-x))/6., y);
vec2 CORNER_UL = vec2((x/6.)+(ceil(10-x))/6., y);
vec2 CORNER_DR = vec2((x/6.)+(ceil(10-x))/6., y);
vec2 CORNER_DL = vec2((x/6.)+(ceil(10-x))/6., y);

vec2 POINT= vec2((x/6.)+(ceil(11-x))/6., y);



void main()
{

    if (vtexCoord.x <= 1/15. || vtexCoord.x >= 14/15.) {
        fragColor = texture(colorman0, LINE_V);
    }

    else if (vtexCoord.y <= 1/15. || vtexCoord.y >= 14/15.) {
        fragColor = texture(colorman0, LINE_H);
    }

    else if (vtexCoord.x >= 4/15. && vtexCoord.x <= 5/15. && vtexCoord.y >= 5/15. && vtexCoord.y <= 6/15.) {
        fragColor = texture(colorman0, PACMAN);
    }

    else if (vtexCoord.x >= 2/15. && vtexCoord.x <= 3/15. && vtexCoord.y >= 5/15. && vtexCoord.y <= 6/15.) {
        fragColor = texture(colorman0, GHOST);
    }

    else if (vtexCoord.x >= 5/15. && vtexCoord.x <= 6/15. && vtexCoord.y >= 5/15. && vtexCoord.y <= 6/15.) {
        fragColor = texture(colorman0, GHOST);
    }

    else if (int(floor(x))%6 == 4) {
        fragColor = texture(colorman0, BLACK);
    }

    else if (int(floor(y))%2 == 0) {
        fragColor = texture(colorman0, LINE_H);
    }

    else {
        fragColor = texture(colorman0, POINT);
    }
}
