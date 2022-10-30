#ifndef _BARRERA_INCLUDE
#define _BARRERA_INCLUDE

#include "Sprite.h"


class Barrera
{
public:
	void init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram, string& file);
	void update(int deltaTime);
	void render();
	void setExplotar();

private:
	Texture spritesheet;
	bool explotar;
	Sprite* sprite;
	glm::ivec2 tileMapDispl;
};

#endif // _BARRERA_INCLUDE