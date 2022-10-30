#ifndef _SCENE4_INCLUDE
#define _SCENE4_INCLUDE


#include <glm/glm.hpp>
#include "ShaderProgram.h"
#include "TileMap.h"
#include "Player.h"
#include "Cactus.h"
#include "CactusPincho.h"
#include "Palmera.h"
#include "Player2.h"
#include "Sol.h"
#include "Bandera.h"
#include "Interruptor.h"
#include "Barrera.h"
#include "Explosio.h"
#include <irrKlang.h>

// Scene contains all the entities of our game.
// It is responsible for updating and render them.

#if defined(WIN32)
#include <conio.h>
#else
#include "../common/conio.h"
#endif

using namespace irrklang;   

class Scene4
{

public:
	Scene4();
	~Scene4();

	void Reload();
	void init();
	void update(int deltaTime);
	void render();
	bool changeScene();
	void deleteEngine();
	void setGodMode(bool g);
private:
	void initShaders();

private:
	bool godMode;
	TileMap *map;
	Player *player;
	Player2 *player2;
	Sol *sol1, *sol2;
	Interruptor *i1, *i2;
	Barrera *b1, *b2, *b3, *b4, *b5, *b6;
	CactusPincho *cactusp1, *cactusp2, *cactusp3, *cactusp4, *cactusp5;
	Palmera *palmera1, *palmera2, *palmera3, *palmera4, *palmera5, *palmera6, *palmera7;
	Cactus *cactus1, *cactus2, *cactus3, *cactus4, *cactus5, *cactus6, *cactus7, *cactus8, *cactus9, *cactus10, *cactus11, *cactus12, *cactus13;
	Bandera *bandera, *bandera2;
	Explosio *explosio1, *explosio2;
	ISoundEngine* engine;
	ShaderProgram texProgram;
	GLuint vaoFons, vboTex, vboFons;
	GLint posLocation, texCoordLocation; 
	Texture texFons;
	float currentTime;
	bool death1, death2;
	bool apret1,apret2;
	glm::mat4 projection;

};

#endif // _SCENE4_INCLUDE


