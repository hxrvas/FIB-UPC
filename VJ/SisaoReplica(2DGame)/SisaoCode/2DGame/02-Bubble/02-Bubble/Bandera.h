#ifndef _BANDERA_INCLUDE
#define _BANDERA_INCLUDE

#include "Sprite.h"
#include "Player.h"
#include "Player2.h"
#include <irrKlang.h>


#if defined(WIN32)
#include <conio.h>
#else
#include "../common/conio.h"
#endif

using namespace irrklang;


class Bandera
{
public:
	void init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram, string file);
	void update(int deltaTime);
	void render();
	void setPlayer(Player *play);
	void setPlayer2(Player2 *play2);
	void setId(int idt);
	bool getBandaux();
	bool getBandaux2();
	bool endFrame();
private:
	Texture spritesheet;
	Sprite* sprite;
	Player* player;
	Player2* player2;
	ISoundEngine* engine;
	glm::ivec2 tileMapDispl;
	bool band_aux = false;
	bool band2_aux = false;
	int id;
};

#endif // _BANDERA _INCLUDE
