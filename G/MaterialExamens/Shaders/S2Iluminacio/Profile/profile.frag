#version 330 core

in vec4 frontColor;
out vec4 fragColor;
in vec4 viewCoord;
in vec3 viewNormal;

uniform float epsilon = 0.1;
uniform float light = 0.5;

vec4 groc = vec4(1, 1, 1, 1);

void main()
{
    float dproduct = dot(normalize(vec3(viewCoord)), normalize(viewNormal));
    if(abs(dproduct) < epsilon)
    {
        fragColor = groc;
    }
    else {
        fragColor = light*frontColor*viewNormal.z;
    }
}
