#version 330 core
in vec3 gNormal;
in vec3 gPos;
out vec4 fragColor;
uniform sampler2D grass_top, grass_side1;
uniform mat3 normalMatrix; 
uniform float d;
const vec4 GREY=vec4(vec3(0.8), 1);

void main() {
  vec3 N=normalize(normalMatrix*gNormal); 
  fragColor=GREY*N.z;

  if (N.z != 0) {
    vec2 texCoord = vec2(4*(gPos.x-gPos.y), gPos.z/d);
    vec4 color = texture(grass_side1, texCoord);
    if (color.a < 0.1) discard;
    else fragColor = color;
  }
  else {
    vec2 texCoord = 4*gPos.xy;
    fragColor = texture(grass_top, texCoord);
  }
}
