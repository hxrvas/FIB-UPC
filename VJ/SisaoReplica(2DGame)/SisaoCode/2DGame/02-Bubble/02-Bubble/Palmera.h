#ifndef _PALMERA_INCLUDE
#define _PALMERA_INCLUDE

#include "Sprite.h"


class Palmera
{
public:
	void init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram, string file);
	void update(int deltaTime);
	void render();

private:
	Texture spritesheet;
	Sprite* sprite;
	glm::ivec2 tileMapDispl;
};

#endif // _PALMERA_INCLUDE