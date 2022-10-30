#ifndef _PLAYER_INCLUDE
#define _PLAYER_INCLUDE


#include "Sprite.h"
#include "TileMap.h"
#include <irrKlang.h>

// Player is basically a Sprite that represents the player. As such it has
// all properties it needs to track its movement, jumping, and collisions.

#if defined(WIN32)
#include <conio.h>
#else
#include "../common/conio.h"
#endif

using namespace irrklang;

class Player
{

public:
	void init(const glm::ivec2 &tileMapPos, ShaderProgram &shaderProgram);
	void update(int deltaTime);
	void render();
	
	void setTileMap(TileMap *tileMap);
	void setPosition(const glm::vec2 &pos);
	
	bool collisionleft(const glm::ivec2 &pos, const glm::ivec2 &size) const;
	bool collisionright(const glm::ivec2 &pos, const glm::ivec2 &size) const;
	bool collisiondownEnemic(const glm::ivec2 &pos, const glm::ivec2 &size);

	glm::ivec2 getPos();
	float getX();

	bool imDead();
	bool bandera();
	bool inter();

	void setbJumping();
	
	bool collisionMoveDown(int caixa);

	void setPosCaixa(glm::ivec2 pos);
	void setPosCaixa2(glm::ivec2 pos);
	void treureSons();
	void setGodMode(bool g);
	void setDead();
	void sethasWon(bool b);
	bool gethasWon();
private:
	bool godMode, hasWon;
	bool bJumping, dead, band, inte,caminant;
	glm::ivec2 tileMapDispl, posPlayer, posCaixa, posCaixa2;
	ISoundEngine* engine;
	int jumpAngle, startY;
	Texture spritesheet;
	Sprite *sprite;
	TileMap *map;
	bool pressed;


};


#endif // _PLAYER_INCLUDE


