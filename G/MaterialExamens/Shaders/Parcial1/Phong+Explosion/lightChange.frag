#version 330 core

out vec4 fragColor;
in vec3 Vx;
in vec3 N;
in vec2 vtexCoord;

uniform sampler2D colorMap; 
uniform vec4 lightSpecular;
uniform vec4 lightPosition;
uniform vec4 matSpecular;
uniform float matShininess;
uniform float time;

vec4 LD, MD;

//model de Phong
vec4 light(vec3 N, vec3 V, vec3 L, vec4 LD,vec4 MD) {
  N=normalize(N);
  V=normalize(V);
  L=normalize(L);
  vec3 R=normalize(2*dot(N, L)*N-L);
  float NdotL=max(0, dot(N, L));
  float RdotV=max(0, dot(R, V));
  float ldiff=NdotL;
  float lspec=0; 
  if (NdotL>0) lspec=pow(RdotV, matShininess); 
  return MD*LD*ldiff + matSpecular*lightSpecular*lspec;
}

void main()
{
	if (int(time)%2 == 0) { 
	//la tercera component del mix ha d'estar entre 0 i 1
		LD = vec4(vec3(mix(0,0.8,fract(time))),1);
	}
	else {
		LD = vec4(vec3(mix(0.8,0,fract(time))),1);
	}
	
	//dividim entre 2 ja que ho volem mostrar un slice de dos segons i 12 pq tenim 12 imatges
	int frame = int(mod(time/2, 12));
	
	//trobem la colocacio dels frames dintre la graella
	//es mouran d'adalt abaix aixi que la divisio sera a x i el residu a y
	int x = frame/3;
	int y = frame%3;
	
	//en cas de que volguessim que es mogues en horitzontal seria:
	/*
		int x = frame%4;
		int y = 2 - frame/4;
	*/
	
	vec2 texCoord = vtexCoord*vec2(1.0/4,1.0/3);
	//ho passem a coordenades de textura
	texCoord.x += x/4.0;
	texCoord.y += y/3.0;
	
	MD = texture(colorMap,texCoord);
	
    vec3 V = -Vx;
	vec3 L = lightPosition.xyz-Vx;
    fragColor = light(N,V,L,LD,MD);
}
