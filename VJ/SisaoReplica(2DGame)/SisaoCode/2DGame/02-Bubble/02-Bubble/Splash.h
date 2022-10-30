#ifndef _SPLASH_INCLUDE
#define _SPLASH_INCLUDE

#include "Sprite.h"
#include "TileMap.h"


class Splash
{
public:
	void init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram, string file);
	void update(int deltaTime);
	void render();
	void setPosition(const glm::vec2 &pos);
	void setTileMap(TileMap *tileMap);
	void play();
	void setR(bool b);
private:
	bool r;
	Texture spritesheet;
	Sprite* sprite;
	glm::ivec2 tileMapDispl;
	glm::ivec2 posPlayer;
	TileMap *map;
};

#endif // _SPLASH_INCLUDE