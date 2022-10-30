#ifndef _SOL_INCLUDE
#define _SOL_INCLUDE

#include "Sprite.h"


class Sol
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

#endif // _SOL_INCLUDE