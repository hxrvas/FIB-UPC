#ifndef _CACTUS_PINCHO_INCLUDE
#define _CACTUS_PINCHO_INCLUDE

#include "Sprite.h"


class CactusPincho
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

#endif // _CACTUS_PINCHO_INCLUDE