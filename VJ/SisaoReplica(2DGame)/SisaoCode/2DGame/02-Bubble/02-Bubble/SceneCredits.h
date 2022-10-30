#ifndef _SCENECREDITS_INCLUDE
#define _SCENECREDITS_INCLUDE


#include <glm/glm.hpp>
#include "ShaderProgram.h"
#include "TileMap.h"
#include "Player.h"
#include "CactusPincho.h"
#include "Palmera.h"
#include "Player2.h"
#include "Sol.h"
#include "Bandera.h"
#include "Sprite.h"
#include <irrKlang.h>

// Scene contains all the entities of our game.
// It is responsible for updating and render them.

#if defined(WIN32)
#include <conio.h>
#else
#include "../common/conio.h"
#endif

using namespace irrklang;


class SceneCredits
{

public:
	SceneCredits();
	~SceneCredits();

	void init();
	void update(int deltaTime);
	void render();
	bool changeScene();
	void deleteEngine();

private:
	void initShaders();

private:

	ShaderProgram texProgram;
	GLuint vaoFons, vboTex, vboFons;
	GLint posLocation, texCoordLocation;
	Texture texFons;
	float currentTime;
	ISoundEngine* engine;
	glm::mat4 projection;
	Texture spritesheet;
	Sprite* sprite;
	int currenty;
};

#endif // _SCENECREDITS _INCLUDE


