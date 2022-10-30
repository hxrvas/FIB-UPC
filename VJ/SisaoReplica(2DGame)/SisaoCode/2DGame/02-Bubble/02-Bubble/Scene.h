#ifndef _SCENE_INCLUDE
#define _SCENE_INCLUDE


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
#include "Explosio.h"
#include "Enemic.h"
#include <irrKlang.h>

// Scene contains all the entities of our game.
// It is responsible for updating and render them.

#if defined(WIN32)
#include <conio.h>
#else
#include "../common/conio.h"
#endif

using namespace irrklang;

class Scene
{

public:
	Scene();
	~Scene();

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
	Cactus *cactus1, *cactus2, *cactus3, *cactus4, *cactus5, *cactus6, *cactus7, *cactus8, *cactus9, *cactus10, *cactus11, *cactus12, *cactus13, *cactus14, *cactus15, *cactus16, *cactus17;
	CactusPincho *cactusp1, *cactusp2, *cactusp3, *cactusp4, *cactusp5;
	Palmera *palmera1, *palmera2, *palmera3, *palmera4, *palmera5, *palmera6;
	Bandera *bandera, *bandera2;
	Enemic *enemic;
	Explosio *explosio1, *explosio2;
	ISoundEngine* engine;
	ShaderProgram texProgram;
	GLuint vaoFons, vboTex, vboFons;
	GLint posLocation, texCoordLocation;
	Texture texFons;
	bool death1, death2;
	float currentTime;
	glm::mat4 projection;

};


#endif // _SCENE_INCLUDE

