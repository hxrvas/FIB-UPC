#version 330 core
        
layout(triangles) in;
layout(triangle_strip, max_vertices = 36) out;

in vec4 vfrontColor[];
out vec4 gfrontColor;
uniform vec3 boundingBoxMin;
float Y = boundingBoxMin.y;
uniform mat4 modelViewProjectionMatrix;

uniform float time;

int n = int(floor(100*time));

void main( void )
{
if (gl_PrimitiveIDIn <= n)  {
	for( int i = 0 ; i < 3 ; i++)
	{
		gfrontColor = vfrontColor[i];
		gl_Position = modelViewProjectionMatrix * gl_in[i].gl_Position;
		EmitVertex();
	}
    EndPrimitive();
    }
}
