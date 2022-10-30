#version 330 core
        
layout(triangles) in;
layout(triangle_strip, max_vertices = 36) out;

in vec4 vfrontColor[];
out vec4 gfrontColor;

uniform vec3 boundingBoxMin, boundingBoxMax;
uniform mat4 modelViewMatrix;
uniform mat4 modelViewProjectionMatrix;

vec4 RED = vec4(1,0,0,1);
vec4 BLUE = vec4(0,0,1,1);
vec4 GREEN = vec4(0,1,0,1);

void boxVertex(vec3 V, vec3 translate, vec3 translateb, vec3 scale, vec4 color) {
        V -= translateb;
        V *= scale;
        V += translate;

        gfrontColor = color;
        gl_Position = modelViewProjectionMatrix*vec4(V, 1);
        EmitVertex();
}

void main( void )
{
	for( int i = 0 ; i < 3 ; i++ )
	{
		gfrontColor = vfrontColor[i];
		gl_Position = gl_in[i].gl_Position;
		EmitVertex();
	}
    EndPrimitive();


    if (gl_PrimitiveIDIn == 0)
    {
        vec3 translate = vec3((boundingBoxMax.x+boundingBoxMin.x)/2, boundingBoxMin.y, (boundingBoxMax.z+boundingBoxMin.z)/2);
        vec3 translateb = vec3(0.5,0.,0.5);
        vec3 scale = vec3(boundingBoxMax.x-boundingBoxMin.x, boundingBoxMax.y-boundingBoxMin.y, boundingBoxMax.z-boundingBoxMin.z);

        boxVertex(vec3(1,0,0), translate, translateb, scale, RED);
        boxVertex(vec3(1,0,1), translate, translateb, scale, RED);
        boxVertex(vec3(1,1,0), translate, translateb, scale, RED);
        boxVertex(vec3(1,1,1), translate, translateb, scale, RED);
        EndPrimitive();

        boxVertex(vec3(0,0,0), translate, translateb, scale, GREEN);
        boxVertex(vec3(1,0,0), translate, translateb, scale, GREEN);
        boxVertex(vec3(0,0,1), translate, translateb, scale, GREEN);
        boxVertex(vec3(1,0,1), translate, translateb, scale, GREEN);
        EndPrimitive();

        boxVertex(vec3(0,1,1), translate, translateb, scale, RED);
        boxVertex(vec3(0,1,0), translate, translateb, scale, RED);
        boxVertex(vec3(0,0,1), translate, translateb, scale, RED);
        boxVertex(vec3(0,0,0), translate, translateb, scale, RED);
        EndPrimitive();

        boxVertex(vec3(0,0,0), translate, translateb, scale, BLUE);
        boxVertex(vec3(1,0,0), translate, translateb, scale, BLUE);
        boxVertex(vec3(0,1,0), translate, translateb, scale, BLUE);
        boxVertex(vec3(1,1,0), translate, translateb, scale, BLUE);
        EndPrimitive();
    }
}
