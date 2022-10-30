#version 330 core
        
layout(triangles) in;
layout(triangle_strip, max_vertices = 36) out;

in vec4 vfrontColor[];
in vec3 vnormal[];
out vec4 gfrontColor;
uniform mat4 projectionMatrix;
uniform float disp = 0.05;
void main( void )
{
//triangle1
	gfrontColor = vfrontColor[0]*normalize(vnormal[0]).z;
    gl_Position = projectionMatrix*gl_in[0].gl_Position;
    EmitVertex();
    gfrontColor = vfrontColor[1]*normalize(vnormal[1]).z;
    gl_Position = projectionMatrix*gl_in[1].gl_Position;
    EmitVertex();
	vec3 BR =gl_in[0].gl_Position.xyz+gl_in[1].gl_Position.xyz+gl_in[2].gl_Position.xyz;
	BR = BR/3;
	vec3 N = normalize((normalize(vnormal[0])+normalize(vnormal[1])+normalize(vnormal[2])/3));
	gfrontColor = vec4(1.0);
	gl_Position = projectionMatrix*vec4(BR+N*disp, 1);
	EmitVertex();
    EndPrimitive();
//triangle2
	gfrontColor = vfrontColor[1]*normalize(vnormal[1]).z;
    gl_Position = projectionMatrix*gl_in[1].gl_Position;
    EmitVertex();
    gfrontColor = vfrontColor[2]*normalize(vnormal[2]).z;
    gl_Position = projectionMatrix*gl_in[2].gl_Position;
    EmitVertex();
	gfrontColor = vec4(1.0);
	gl_Position = projectionMatrix*vec4(BR+N*disp, 1);
	EmitVertex();
    EndPrimitive();
//triangle3
	gfrontColor = vfrontColor[0]*normalize(vnormal[0]).z;
    gl_Position = projectionMatrix*gl_in[0].gl_Position;
    EmitVertex();
    gfrontColor = vfrontColor[2]*normalize(vnormal[2]).z;
    gl_Position = projectionMatrix*gl_in[2].gl_Position;
    EmitVertex();
	gfrontColor = vec4(1.0);
	gl_Position = projectionMatrix*vec4(BR+N*disp, 1);
	EmitVertex();
    EndPrimitive();

}
