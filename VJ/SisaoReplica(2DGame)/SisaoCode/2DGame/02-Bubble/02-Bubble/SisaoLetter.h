#ifndef _SISAOLETTER_INCLUDE
#define _SISAOLETTER_INCLUDE

#include "Sprite.h"
#include "SisaoLetter.h"



class SisaoLetter
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

#endif // _SISAOLETTER_INCLUDE
