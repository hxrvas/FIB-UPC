
#version 330 core

layout(triangles) in;
layout(triangle_strip, max_vertices = 36) out;

in vec4 vfrontColor[];
in vec3 vnormal[];
out vec4 gfrontColor;
uniform mat4 modelViewProjectionMatrix;
uniform float time;
const float speed = 0.5;
const float angSpeed = 8.0;
void main( void )
{

    vec3 n = (vnormal[0]+ vnormal[1]+ vnormal[2])/3;
    vec3 T = vec3(speed*time*n);
    mat3 rotZ = mat3(vec3(cos(angSpeed*time),sin(angSpeed*time),0),vec3(-
    sin(angSpeed*time),cos(angSpeed*time),0),vec3(0,0,1));
    vec3 BT = gl_in[0].gl_Position.xyz+gl_in[1].gl_Position.xyz+gl_in[2].gl_Position.xyz;
    BT = BT/3;
	for( int i = 0 ; i < 3 ; i++)
	{
		gfrontColor = vfrontColor[i];
		vec3 vertex = gl_in[i].gl_Position.xyz-BT;
		vertex = rotZ * vertex;
		vertex = vertex+BT+T;
		gl_Position = modelViewProjectionMatrix*vec4(vertex, 1);
		EmitVertex();
	}
    EndPrimitive();
}
