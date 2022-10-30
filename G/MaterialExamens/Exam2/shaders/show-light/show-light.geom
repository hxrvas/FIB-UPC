#version 330 core
        
layout(triangles) in;
layout(triangle_strip, max_vertices = 36) out;

in vec4 vfrontColor[];
out vec4 gfrontColor;
out vec2 gtexCoord;

uniform vec4 lightPosition;
uniform mat4 projectionMatrix;
uniform float w = 0.3;

void main( void )
{



	for( int i = 0 ; i < 3 ; i++ )
	{
		gfrontColor = vfrontColor[i];
		gtexCoord = vec2(-1,-1);
		gl_Position = gl_in[i].gl_Position;
		EmitVertex();
	}
    EndPrimitive();
    
     if (gl_PrimitiveIDIn == 0)
    {
        gl_Position = (projectionMatrix*lightPosition)+vec4(-w,-w,0,0);
        gtexCoord = vec2(0,0);
        EmitVertex();
        gl_Position = (projectionMatrix*lightPosition)+vec4(w,-w,0,0);
        gtexCoord = vec2(1,0);
        EmitVertex();
        gl_Position = (projectionMatrix*lightPosition)+vec4(-w,w,0,0);
        gtexCoord = vec2(0,1);
        EmitVertex();
        gl_Position = (projectionMatrix*lightPosition)+vec4(w,w,0,0);
        gtexCoord = vec2(1,1);
        EmitVertex();
        EndPrimitive();
    }
}
