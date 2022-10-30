#ifndef _MENUINIT_INCLUDE
#define _MENUINIT_INCLUDE


#include <glm/glm.hpp>
#include "ShaderProgram.h"
#include "TileMap.h"
#include "Player.h"
#include "CactusPincho.h"
#include "Palmera.h"
#include "Player2.h"
#include "Sol.h"
#include "Cactus.h"
#include "SisaoLetter.h"
#include "Caixa.h"
#include "CaixaInteractiva.h"
#include <irrKlang.h>


// Scene contains all the entities of our game.
// It is responsible for updating and render them.

#if defined(WIN32)
#include <conio.h>
#else
#include "../common/conio.h"
#endif

using namespace irrklang;


class MenuInit
{

public:
	MenuInit();
	~MenuInit();

	void Reload();
	void init();
	int update(int deltaTime);
	void render();
	void deleteEngine();
private:
	void initShaders();

private:
	TileMap *map;
	Player *player;
	Player2 *player2;
	Sol *sol1, *sol2;
	CactusPincho *cactusp1, *cactusp2;
	Palmera *palmera1, *palmera2;
	Cactus *cactus1, *cactus2, *cactus3, *cactus4, *cactus5, *cactus6, *cactus7, *cactus8, *cactus9, *cactus10, *cactus11, *cactus12;
	SisaoLetter *sisaoLetter;
	Caixa *caixa1, *caixa2;
	CaixaInteractiva *caixaT, *caixa3, *caixa4, *caixa5, *caixa6, *caixa7;
	ISoundEngine* engine;
	ShaderProgram texProgram;
	GLuint vaoFons, vboTex, vboFons;
	GLint posLocation, texCoordLocation;
	Texture texFons;
	bool pressed;
	float currentTime;
	glm::mat4 projection;
	//es un contador del nivell seleccionat a les caixes
	int cont, cont_aux;

};

#endif // _MENUINIT _INCLUDE


