#ifndef _EXPLOSIO_INCLUDE
#define _EXPLOSIO_INCLUDE

#include "Sprite.h"
#include "TileMap.h"


class Explosio
{
public:
	void init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram, string file);
	void update(int deltaTime);
	void render();
	void setPosition(const glm::vec2 &pos);
	int numSprite();
	void setTileMap(TileMap *tileMap);


private:
	Texture spritesheet;
	Sprite* sprite;
	glm::ivec2 tileMapDispl;
	glm::ivec2 posPlayer;
	TileMap *map;
};

#endif // _EXPLOSIO_INCLUDE