#ifndef _ENEMIC_INCLUDE
#define _ENEMIC_INCLUDE

#include "Sprite.h"
#include "Player.h"

#include <irrKlang.h>


#if defined(WIN32)
#include <conio.h>
#else
#include "../common/conio.h"
#endif

using namespace irrklang;

class Enemic
{
public:
	void init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram, string& file);
	void update(int deltaTime);
	void render();
	void setPlayer(Player *p);
	void setPosition(const glm::vec2 &pos);

private:
	Texture spritesheet;
	Sprite* sprite;
	glm::ivec2 tileMapDispl, posEnemic;
	ISoundEngine* engine;
	bool moveLeft;
	Player* player;
};

#endif // _ENEMIC_INCLUDE