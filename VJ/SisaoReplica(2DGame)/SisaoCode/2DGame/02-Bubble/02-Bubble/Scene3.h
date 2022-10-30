#ifndef _SCENE3_INCLUDE
#define _SCENE3_INCLUDE


#include <glm/glm.hpp>
#include "ShaderProgram.h"
#include "TileMap.h"
#include "Player.h"
#include "CactusPincho.h"
#include "Cactus.h"
#include "Palmera.h"
#include "Player2.h"
#include "Sol.h"
#include "Bandera.h"
#include "Caixa.h"
#include "Caixa2.h"
#include "Explosio.h"
#include "Splash.h"
#include <irrKlang.h>

// Scene contains all the entities of our game.
// It is responsible for updating and render them.

#if defined(WIN32)
#include <conio.h>
#else
#include "../common/conio.h"
#endif

using namespace irrklang;


class Scene3
{

public:
	Scene3();
	~Scene3();

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
	Caixa *caixa;
	Caixa2 *caixa2;
	TileMap *map;
	Player *player;
	Player2 *player2;
	Sol *sol1, *sol2;
	Palmera *palmera1, *palmera2, *palmera3, *palmera4;
	Cactus *cactus1, *cactus2, *cactus3, *cactus4, *cactus5, *cactus6, *cactus7, *cactus8, *cactus9, *cactus10, *cactus11, *cactus12, *cactus13;
	Bandera *bandera, *bandera2;
	Explosio *explosio1, *explosio2;
	Splash *splash1, *splash2;
	ISoundEngine* engine;
	ShaderProgram texProgram;
	GLuint vaoFons, vboTex, vboFons;
	GLint posLocation, texCoordLocation;
	Texture texFons;
	float currentTime;
	bool death1, death2;
	glm::mat4 projection;

};

#endif // _SCENE3_INCLUDE


