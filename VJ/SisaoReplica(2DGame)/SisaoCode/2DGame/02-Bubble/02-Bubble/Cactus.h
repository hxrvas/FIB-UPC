#ifndef _CACTUS_INCLUDE
#define _CACTUS_INCLUDE

#include "Sprite.h"


class Cactus
{
public:
	void init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram, string& file);
	void update(int deltaTime);
	void render();

private:
	Texture spritesheet;
	Sprite* sprite;
	glm::ivec2 tileMapDispl;
};

#endif // _CACTUS_INCLUDE