#version 330 core
        
layout(triangles) in;
layout(triangle_strip, max_vertices = 36) out;

in vec4 viewvertex[];
out vec4 gfrontColor;
uniform vec4 ProjectionMatrix;

vec4 red = vec4(1., 0., 0., 1.);
vec4 yellow = vec4(1., 1., 0., 1.);
const float areamax = 0.0007;
void main( void )

{
    vec3 u = viewvertex[1].xyz-viewvertex[0].xyz;
    vec3 v = viewvertex[2].xyz-viewvertex[0].xyz;
    float d = length(cross(u,v))/2.;
    d /= areamax;
    
    vec4 color = mix(red, yellow, d);
	for( int i = 0 ; i < 3 ; i++ )
	{
		gfrontColor = color;
		gl_Position = gl_in[i].gl_Position;
		EmitVertex();
	}
    EndPrimitive();
}
