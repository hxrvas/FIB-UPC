#include <iostream>
#include <cmath>
#include <glm/gtc/matrix_transform.hpp>
#include "MenuInit.h"
#include "Game.h"
#include "TileMap.h"
#include <GL/glew.h>
#include <GL/glut.h>
#include <windows.h>


#define SCREEN_X 32
#define SCREEN_Y 16

#define INIT_PLAYER_X_TILES 10
#define INIT_PLAYER_Y_TILES 9

#define INIT_PLAYER2_X_TILES 10
#define INIT_PLAYER2_Y_TILES 17


MenuInit::MenuInit()
{
	map = NULL;
	player = NULL;
	player2 = NULL;
	cactusp1 = NULL;
	cactusp2 = NULL;
	palmera1 = NULL;
	palmera2 = NULL;
	sol1 = NULL;
	sol2 = NULL;
	cactus1 = NULL;
	cactus2 = NULL;
	cactus3 = NULL;
	cactus4 = NULL;
	cactus5 = NULL;
	cactus6 = NULL;
	cactus7 = NULL;
	cactus8 = NULL;
	cactus9 = NULL;
	cactus10 = NULL;
	cactus11 = NULL;
	cactus12 = NULL;
	sisaoLetter = NULL;
	caixaT = NULL;
	caixa1 = NULL;
	caixa2 = NULL;
	caixa3 = NULL;
	caixa4 = NULL;
	caixa5 = NULL;
	caixa6 = NULL;
	caixa7 = NULL;
}

MenuInit::~MenuInit()
{
	if (map != NULL)
		delete map;
	if (player != NULL)
		delete player;
	if (player2 != NULL)
		delete player2;
	if (cactusp1 != NULL)
		delete cactusp1;
	if (cactusp2 != NULL)
		delete cactusp2;
	if (palmera1 != NULL)
		delete palmera1;
	if (palmera2 != NULL)
		delete palmera2;
	if (sol1 != NULL)
		delete sol1;
	if (sol2 != NULL)
		delete sol2;
	if (cactus1 != NULL)
		delete cactus1;
	if (cactus2 != NULL)
		delete cactus2;
	if (cactus3 != NULL)
		delete cactus3;
	if (cactus4 != NULL)
		delete cactus4;
	if (cactus5 != NULL)
		delete cactus5;
	if (cactus6 != NULL)
		delete cactus6;
	if (cactus7 != NULL)
		delete cactus7;
	if (cactus8 != NULL)
		delete cactus8;
	if (cactus9 != NULL)
		delete cactus9;
	if (cactus10 != NULL)
		delete cactus10;
	if (cactus11 != NULL)
		delete cactus11;
	if (cactus12 != NULL)
		delete cactus12;
	if (sisaoLetter != NULL)
		delete sisaoLetter;
	if (caixaT != NULL)
		delete caixaT;
	if (caixa1 != NULL)
		delete caixa1;
	if (caixa2 != NULL)
		delete caixa2;
	if (caixa3 != NULL)
		delete caixa3;
	if (caixa4 != NULL)
		delete caixa4;
	if (caixa5 != NULL)
		delete caixa5;
	if (caixa6 != NULL)
		delete caixa6;
	if (caixa7 != NULL)
		delete caixa7;
}

void MenuInit::Reload()
{
	if (map != NULL)
		delete map;
	if (player != NULL)
		delete player;
	if (player2 != NULL)
		delete player2;
	if (cactusp1 != NULL)
		delete cactusp1;
	if (cactusp2 != NULL)
		delete cactusp2;
	if (palmera1 != NULL)
		delete palmera1;
	if (palmera2 != NULL)
		delete palmera2;
	if (sol1 != NULL)
		delete sol1;
	if (sol2 != NULL)
		delete sol2;
	if (cactus1 != NULL)
		delete cactus1;
	if (cactus2 != NULL)
		delete cactus2;
	if (cactus3 != NULL)
		delete cactus3;
	if (cactus4 != NULL)
		delete cactus4;
	if (cactus5 != NULL)
		delete cactus5;
	if (cactus6 != NULL)
		delete cactus6;
	if (cactus7 != NULL)
		delete cactus7;
	if (cactus8 != NULL)
		delete cactus8;
	if (cactus9 != NULL)
		delete cactus9;
	if (cactus10 != NULL)
		delete cactus10;
	if (cactus11 != NULL)
		delete cactus11;
	if (cactus12 != NULL)
		delete cactus12;
	if (sisaoLetter != NULL)
		delete sisaoLetter;
	if (caixaT != NULL)
		delete caixaT;
	if (caixa1 != NULL)
		delete caixa1;
	if (caixa2 != NULL)
		delete caixa2;
	if (caixa3 != NULL)
		delete caixa3;
	if (caixa4 != NULL)
		delete caixa4;
	if (caixa5 != NULL)
		delete caixa5;
	if (caixa6 != NULL)
		delete caixa6;
	if (caixa7 != NULL)
		delete caixa7;
	engine->stopAllSounds();
	init();
}

void MenuInit::init()
{
	initShaders();

	engine = createIrrKlangDevice();
	engine->play2D("sounds/Fondo.mp3");

	//Creem el fons
	float x, y, width, height;
	x = 130.0;
	y = 0.0;
	width = 640.0;
	height = 480.0;
	float vertices[12] = { x, y, x + width, y, x + width, y + height, x, y, x + width, y + height, x, y + height };

	float texCoords[12] = { 0., 0., 1., 0., 1., 1., 0., 0., 1., 1., 0., 1. };

	glGenVertexArrays(1, &vaoFons);
	glBindVertexArray(vaoFons);
	glGenBuffers(1, &vboFons);
	glBindBuffer(GL_ARRAY_BUFFER, vboFons);
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), &vertices[0], GL_STATIC_DRAW);
	posLocation = texProgram.bindVertexAttribute("position", 2, 0, 0);
	glGenBuffers(1, &vboTex);
	glBindBuffer(GL_ARRAY_BUFFER, vboTex);
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), &texCoords[0], GL_STATIC_DRAW);
	texCoordLocation = texProgram.bindVertexAttribute("texCoord", 2, 0, 0);

	texFons.loadFromFile("images/Fondo640x480.png", TEXTURE_PIXEL_FORMAT_RGB);

	cont = 0;
	cont_aux = 0;
	pressed = false;

	//Creem el sol
	string file1 = "images/SolInvertido.png";
	string file2 = "images/Sol.png";
	sol1 = new Sol();
	sol1->init(glm::ivec2(23 * 16, 10 * 16), texProgram, file1);

	sol2 = new Sol();
	sol2->init(glm::ivec2(23 * 16, 16 * 16), texProgram, file2);

	//Creació tilemap

	map = TileMap::createTileMap("levels/Ini.txt", glm::vec2(SCREEN_X, SCREEN_Y), texProgram);
	player = new Player();
	player->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram);
	player->setPosition(glm::vec2(INIT_PLAYER_X_TILES * map->getTileSize(), INIT_PLAYER_Y_TILES * map->getTileSize()));
	player->setTileMap(map);

	player2 = new Player2();
	player2->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram);
	player2->setPosition(glm::vec2(INIT_PLAYER2_X_TILES * map->getTileSize(), INIT_PLAYER2_Y_TILES * map->getTileSize()));
	player2->setTileMap(map);

	string fileC1 = "images/Obstaclecactus.png";
	string fileC2 = "images/ObstaclecactusInverted.png";
	cactusp1 = new CactusPincho();
	cactusp1->init(glm::ivec2(40 * 16, 18 * 16), texProgram, fileC1);
	cactusp2 = new CactusPincho();
	cactusp2->init(glm::ivec2(40 * 16, 10 * 16), texProgram, fileC2);

	//pintem lletras de SISAO
	string file = "images/SisaoTitol.png";
	sisaoLetter = new SisaoLetter();
	sisaoLetter->init(glm::ivec2(17 * 16, 6 * 16), texProgram, file);


	string fileC = "images/Caixa.png";

	caixa1 = new Caixa();
	caixa1->init(glm::ivec2(44 * 16, 14 * 16), texProgram, fileC);

	caixa2 = new Caixa();
	caixa2->init(glm::ivec2(7 * 16, 14 * 16), texProgram, fileC);

	fileC = "images/CaixaT.png";
	caixaT = new CaixaInteractiva();
	caixaT->init(glm::ivec2(13 * 16, 25 * 16), texProgram, fileC);
	caixaT->seleccionar();

	fileC = "images/Caixa1.png";
	caixa3 = new CaixaInteractiva();
	caixa3->init(glm::ivec2(18 * 16, 25 * 16), texProgram, fileC);
	caixa3->deseleccionar();

	fileC = "images/Caixa2.png";
	caixa4 = new CaixaInteractiva();
	caixa4->init(glm::ivec2(23 * 16, 25 * 16), texProgram, fileC);
	caixa4->deseleccionar();

	fileC = "images/Caixa3.png";
	caixa5 = new CaixaInteractiva();
	caixa5->init(glm::ivec2(28 * 16, 25 * 16), texProgram, fileC);
	caixa5->deseleccionar();

	fileC = "images/Caixa4.png";
	caixa6 = new CaixaInteractiva();
	caixa6->init(glm::ivec2(33 * 16, 25 * 16), texProgram, fileC);
	caixa6->deseleccionar();

	fileC = "images/Caixa5.png";
	caixa7 = new CaixaInteractiva();
	caixa7->init(glm::ivec2(38 * 16, 25 * 16), texProgram, fileC);
	caixa7->deseleccionar();



	//pintem palmeras de fondo
	string fileB = "images/BigPalmera.png";
	string fileS = "images/SmallPalmera.png";

	palmera1 = new Palmera();
	palmera1->init(glm::ivec2(26 * 16, 3 * 16), texProgram, fileB);

	palmera2 = new Palmera();
	palmera2->init(glm::ivec2(23 * 16, 3 * 16), texProgram, fileS);


	string fileCg = "images/BigCactus.png";
	string fileCp = "images/SmallCactus.png";
	string fileCgi = "images/BigCactusInvertido.png";
	string fileCpi = "images/SmallCactusInvertido.png";

	cactus1 = new Cactus();
	cactus1->init(glm::ivec2(35 * 16, 7 * 16), texProgram, fileCg);

	cactus2 = new Cactus();
	cactus2->init(glm::ivec2(18 * 16, 7 * 16), texProgram, fileCg);

	cactus3 = new Cactus();
	cactus3->init(glm::ivec2(11 * 16, 13 * 16), texProgram, fileCg);

	cactus4 = new Cactus();
	cactus4->init(glm::ivec2(42 * 16, 13 * 16), texProgram, fileCg);

	cactus5 = new Cactus();
	cactus5->init(glm::ivec2(34 * 16, 7 * 16), texProgram, fileCp);

	cactus6 = new Cactus();
	cactus6->init(glm::ivec2(19 * 16, 7 * 16), texProgram, fileCp);

	cactus7 = new Cactus();
	cactus7->init(glm::ivec2(42 * 16, 16 * 16), texProgram, fileCgi);

	cactus8 = new Cactus();
	cactus8->init(glm::ivec2(11 * 16, 16 * 16), texProgram, fileCgi);

	cactus9 = new Cactus();
	cactus9->init(glm::ivec2(18 * 16, 16 * 16), texProgram, fileCgi);

	cactus10 = new Cactus();
	cactus10->init(glm::ivec2(35 * 16, 16 * 16), texProgram, fileCgi);

	cactus11 = new Cactus();
	cactus11->init(glm::ivec2(34 * 16, 16 * 16), texProgram, fileCpi);

	cactus12 = new Cactus();
	cactus12->init(glm::ivec2(19 * 16, 16 * 16), texProgram, fileCpi);




	projection = glm::ortho(130.0f, float(SCREEN_WIDTH / 2)+80.0f, float((SCREEN_HEIGHT / 2) - 1), 0.f);
	currentTime = 0.0f;
}

int MenuInit::update(int deltaTime)
{
	if (Game::instance().getSpecialKey(GLUT_KEY_LEFT) && pressed == false)  {
		pressed = true;
		engine->play2D("sounds/MenuMove.wav", false);
		if (cont > 0) --cont;
	}
	else if (Game::instance().getSpecialKey(GLUT_KEY_RIGHT) && pressed == false) {
		pressed = true;
		engine->play2D("sounds/MenuMove.wav", false);
		if (cont < 5) ++cont;
	}
	else if (!Game::instance().getSpecialKey(GLUT_KEY_LEFT) && !Game::instance().getSpecialKey(GLUT_KEY_RIGHT)) pressed = false;

	if (Game::instance().getKey(32)) {
		engine->stopAllSounds();
		engine->play2D("sounds/Win.wav", false);
		Sleep(1000);
		engine->drop(); // delete engine
		if (caixaT->isSeleccionat()) {
			return 0;
		}
		if (caixa3->isSeleccionat()) {
			return 1;	
		}
		if (caixa4->isSeleccionat()) {
			return 2;
		}
		if (caixa5->isSeleccionat()) {
			return 3;
		}
		if (caixa6->isSeleccionat()) {
			return 4;
		}
		if (caixa7->isSeleccionat()) {
			return 5;
		}
	}

	if (cont != cont_aux) {
		cont_aux = cont;
		if (cont == 0) {
			caixaT->seleccionar();
			caixa3->deseleccionar();
		}
		if (cont == 1) {
			caixaT->deseleccionar();
			caixa3->seleccionar();
			caixa4->deseleccionar();
		}
		else if (cont == 2) {
			caixa3->deseleccionar();
			caixa4->seleccionar();
			caixa5->deseleccionar();
		}
		if (cont == 3) {
			caixa4->deseleccionar();
			caixa5->seleccionar();
			caixa6->deseleccionar();
		}
		if (cont == 4) {
			caixa5->deseleccionar();
			caixa6->seleccionar();
			caixa7->deseleccionar();
		}
		if (cont == 5) {
			caixa7->seleccionar();
			caixa6->deseleccionar();
		}
	}


	currentTime += deltaTime;
	
	
	sisaoLetter->update(deltaTime);

	caixaT->update(deltaTime);
	caixa3->update(deltaTime);
	caixa4->update(deltaTime);
	caixa5->update(deltaTime);
	caixa6->update(deltaTime);
	caixa7->update(deltaTime);


	cactusp1->update(deltaTime);
	cactusp2->update(deltaTime);
	

	return -1;
}

void MenuInit::render()
{
	glm::mat4 modelview;

	texProgram.use();
	texProgram.setUniformMatrix4f("projection", projection);
	texProgram.setUniform4f("color", 1.0f, 1.0f, 1.0f, 1.0f);
	modelview = glm::mat4(1.0f);
	texProgram.setUniformMatrix4f("modelview", modelview);
	texProgram.setUniform2f("texCoordDispl", 0.f, 0.f);

	glEnable(GL_TEXTURE_2D);
	texFons.use();
	glBindVertexArray(vaoFons);
	glEnableVertexAttribArray(posLocation);
	glEnableVertexAttribArray(texCoordLocation);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glDisable(GL_TEXTURE_2D);

	sol1->render();
	sol2->render();
	map->render();


	cactusp1->render();
	cactusp2->render();
	palmera2->render();
	palmera1->render();
	cactus1->render();
	cactus2->render();
	cactus3->render();
	cactus4->render();
	cactus5->render();
	cactus6->render();
	cactus7->render();
	cactus8->render();
	cactus9->render();
	cactus10->render();
	cactus11->render();
	cactus12->render();
	caixa1->render();
	caixa2->render();
	caixaT->render();
	caixa3->render();
	caixa4->render();
	caixa5->render();
	caixa6->render();
	caixa7->render();
	sisaoLetter->render();


	player->render();
	player2->render();
}

void MenuInit::initShaders()
{
	Shader vShader, fShader;

	vShader.initFromFile(VERTEX_SHADER, "shaders/texture.vert");
	if (!vShader.isCompiled())
	{
		cout << "Vertex Shader Error" << endl;
		cout << "" << vShader.log() << endl << endl;
	}
	fShader.initFromFile(FRAGMENT_SHADER, "shaders/texture.frag");
	if (!fShader.isCompiled())
	{
		cout << "Fragment Shader Error" << endl;
		cout << "" << fShader.log() << endl << endl;
	}
	texProgram.init();
	texProgram.addShader(vShader);
	texProgram.addShader(fShader);
	texProgram.link();
	if (!texProgram.isLinked())
	{
		cout << "Shader Linking Error" << endl;
		cout << "" << texProgram.log() << endl << endl;
	}
	texProgram.bindFragmentOutput("outColor");
	vShader.free();
	fShader.free();
}

void MenuInit::deleteEngine()
{
	engine->drop();
}