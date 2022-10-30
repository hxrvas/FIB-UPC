#ifndef _CAIXA_INCLUDE
#define _CAIXA_INCLUDE

#include "Sprite.h"
#include "TileMap.h"
#include "Player.h"
#include <irrKlang.h>

#if defined(WIN32)
#include <conio.h>
#else
#include "../common/conio.h"
#endif

using namespace irrklang;

class Caixa
{
public:
	
	void init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram, string& file);
	void update(int deltaTime);
	void render();
	void setPosition(const glm::vec2 &p);
	void setTileMap(TileMap *tileMap);
	void setPlayer(Player *p);
	glm::ivec2 getPos();
	bool getFloating();
private:
	bool floating;
	int force, contador;
	bool movingleft, movingright;
	Texture spritesheet;
	Sprite* sprite;
	ISoundEngine* engine;
	glm::ivec2 tileMapDispl, pos;
	TileMap *map;
	Player* player;
};

#endif // _CAIXA_INCLUDE