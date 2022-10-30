#ifndef _SCENE2_INCLUDE
#define _SCENE2_INCLUDE


#include <glm/glm.hpp>
#include "ShaderProgram.h"
#include "TileMap.h"
#include "Player.h"
#include "CactusPincho.h"
#include "Palmera.h"
#include "Player2.h"
#include "Sol.h"
#include "Bandera.h"
#include "Cactus.h"
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


class Scene2
{

public:
	Scene2();
	~Scene2();

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
	CactusPincho *cactusp1, *cactusp2, *cactusp3 , *cactusp4, *cactusp5, *cactusp6, *cactusp7;
	Cactus *cactus1, *cactus2, *cactus3, *cactus4, *cactus5, *cactus6, *cactus7, *cactus8, *cactus9, *cactus10, *cactus11, *cactus12;
	Palmera *palmera1, *palmera2, *palmera3, *palmera4, *palmera5, *palmera6;
	Bandera *bandera, *bandera2;
	Explosio *explosio1, *explosio2;
	Interruptor *interruptor;
	Barrera *barrera1, *barrera2, *barrera3;
	ISoundEngine* engine;
	ShaderProgram texProgram;
	GLuint vaoFons, vboTex, vboFons;
	GLint posLocation, texCoordLocation;
	Texture texFons;
	float currentTime;
	bool apret;
	bool death1, death2;
	glm::mat4 projection;

};

#endif // _SCENE2_INCLUDE


