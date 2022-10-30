#version 330 core
        
layout(triangles) in;
layout(triangle_strip, max_vertices = 36) out;

in vec4 vfrontColor[];
in vec3 vnormal[];
out vec4 gfrontColor;
uniform mat4 modelViewProjectionMatrix;
uniform float time;
const float speed = 0.5;

void main( void )
{
    
    vec3 n = (vnormal[0]+ vnormal[1]+ vnormal[2])/3; 
    vec3 T = vec3(speed*time*n);  
   
	for( int i = 0 ; i < 3 ; i++ ) 
	{

		gfrontColor = vfrontColor[i]; 
		vec3 vertex = gl_in[i].gl_Position.xyz+T; 
		gl_Position = modelViewProjectionMatrix*vec4(vertex, 1);
		EmitVertex();
	}
    EndPrimitive(); 
}
