#version 330 core
        
layout(triangles) in;
layout(triangle_strip, max_vertices = 36) out;

in vec4 vfrontColor[];
out vec4 gfrontColor;
uniform vec3 boundingBoxMin;
uniform vec3 boundingBoxMax;
float R = distance(boundingBoxMin, boundingBoxMax)/2;
vec3 C = vec3((boundingBoxMin.x+ boundingBoxMax.x)/2,(boundingBoxMin.y+ boundingBoxMax.y)/2, (boundingBoxMin.z+ boundingBoxMax.z)/2);
float Y = boundingBoxMin.y;
uniform mat4 modelViewProjectionMatrix;
 
void main( void )
{
    if(gl_PrimitiveIDIn == 0) 
    {
        gfrontColor = vec4(0.0, 1.0, 1.0, 1.0);
        gl_Position = modelViewProjectionMatrix*vec4(C.x-R, Y-0.01, C.z-R, 1.);
        EmitVertex();
        gfrontColor = vec4(0.0, 1.0, 1.0, 1.0);
        gl_Position = modelViewProjectionMatrix*vec4(C.x+R, Y-0.01, C.z-R, 1.);
        EmitVertex();
        gfrontColor = vec4(0.0, 1.0, 1.0, 1.0);
        gl_Position = modelViewProjectionMatrix*vec4(C.x-R, Y-0.01, C.z+R, 1.);
        EmitVertex();
         gfrontColor = vec4(0.0, 1.0, 1.0, 1.0);
        gl_Position = modelViewProjectionMatrix*vec4(C.x+R, Y-0.01, C.z+R, 1.);
        EmitVertex();
        EndPrimitive();
    }
    
	for( int i = 0 ; i < 3 ; i++ )
	{
		gfrontColor = vfrontColor[i];
		gl_Position = modelViewProjectionMatrix * gl_in[i].gl_Position;
		EmitVertex();
	}
    EndPrimitive();
    
    for( int i = 0 ; i < 3 ; i++ )
	{
		gfrontColor = vec4(0.0, 0.0, 0.0, 1.0);
		vec4 P = gl_in[i].gl_Position;
		P.y = Y;
 		gl_Position = modelViewProjectionMatrix*P;
		EmitVertex();
	}
    EndPrimitive();
}
