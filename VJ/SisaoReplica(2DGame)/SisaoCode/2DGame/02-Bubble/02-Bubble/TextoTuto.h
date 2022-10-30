#ifndef _TEXTOTUTO_INCLUDE
#define _TEXTOTUTO_INCLUDE

#include "Sprite.h"


class TextoTuto
{
public:
	void init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram);
	void update(int deltaTime);
	void render();

private:
	Texture spritesheet;
	Sprite* sprite;
	glm::ivec2 tileMapDispl;
};

#endif // _TEXTOTUTO_INCLUDE