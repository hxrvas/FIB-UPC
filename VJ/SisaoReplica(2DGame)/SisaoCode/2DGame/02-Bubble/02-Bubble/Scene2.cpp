#include <iostream>
#include <cmath>
#include <glm/gtc/matrix_transform.hpp>
#include "Scene2.h"
#include "Game.h"
#include <Windows.h>


#define SCREEN_X 32
#define SCREEN_Y 16

#define INIT_PLAYER_X_TILES 53
#define INIT_PLAYER_Y_TILES 8

#define INIT_PLAYER2_X_TILES 53
#define INIT_PLAYER2_Y_TILES 18


Scene2::Scene2()
{
	map = NULL;
	player = NULL;
	player2 = NULL;
	cactusp1 = NULL;
	cactusp2 = NULL;
	cactusp3 = NULL;
	cactusp4 = NULL;
	cactusp5 = NULL;
	cactusp6 = NULL;
	cactusp7 = NULL;
	palmera1 = NULL;
	palmera2 = NULL;
	palmera3 = NULL;
	palmera4 = NULL;
	palmera5 = NULL;
	palmera6 = NULL;
	bandera = NULL;
	bandera2 = NULL;
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
	interruptor = NULL;
	barrera1 = NULL;
	barrera2 = NULL;
	barrera3 = NULL;
	explosio1 = NULL;
	explosio2 = NULL;
}

Scene2::~Scene2()
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
	if (cactusp3 != NULL)
		delete cactusp3;
	if (cactusp4 != NULL)
		delete cactusp4;
	if (cactusp5 != NULL)
		delete cactusp5;
	if (cactusp6 != NULL)
		delete cactusp6;
	if (cactusp7 != NULL)
		delete cactusp7;
	if (palmera1 != NULL)
		delete palmera1;
	if (palmera2 != NULL)
		delete palmera2;
	if (palmera3 != NULL)
		delete palmera3;
	if (palmera4 != NULL)
		delete palmera4;
	if (palmera5 != NULL)
		delete palmera5;
	if (palmera6 != NULL)
		delete palmera6;
	if (sol1 != NULL)
		delete sol1;
	if (sol2 != NULL)
		delete sol2;
	if (bandera != NULL)
		delete bandera;
	if (bandera2 != NULL)
		delete bandera2;
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
	if (interruptor != NULL)
		delete interruptor;
	if (barrera1 != NULL)
		delete barrera1;
	if (barrera2 != NULL)
		delete barrera2;
	if (barrera3 != NULL)
		delete barrera3;
	if (explosio1 != NULL)
		delete explosio1;
	if (explosio2 != NULL)
		delete explosio2;
}

void Scene2::Reload()
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
	if (cactusp3 != NULL)
		delete cactusp3;
	if (cactusp4 != NULL)
		delete cactusp4;
	if (cactusp5 != NULL)
		delete cactusp5;
	if (cactusp6 != NULL)
		delete cactusp6;
	if (cactusp7 != NULL)
		delete cactusp7;
	if (palmera1 != NULL)
		delete palmera1;
	if (palmera2 != NULL)
		delete palmera2;
	if (palmera3 != NULL)
		delete palmera3;
	if (palmera4 != NULL)
		delete palmera4;
	if (palmera5 != NULL)
		delete palmera5;
	if (palmera6 != NULL)
		delete palmera6;
	if (sol1 != NULL)
		delete sol1;
	if (sol2 != NULL)
		delete sol2;
	if (bandera != NULL)
		delete bandera;
	if (bandera2 != NULL)
		delete bandera2;
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
	if (interruptor != NULL)
		delete interruptor;
	if (barrera1 != NULL)
		delete barrera1;
	if (barrera2 != NULL)
		delete barrera2;
	if (barrera3 != NULL)
		delete barrera3;
	if (explosio1 != NULL)
		delete explosio1;
	if (explosio2 != NULL)
		delete explosio2;
	engine->stopAllSounds();
	init();
}

void Scene2::init()
{
	initShaders();
	godMode = false;
	engine = createIrrKlangDevice();
	engine->play2D("sounds/Fondo.mp3", true);

	//Creem el fons
	float x, y, width, height;
	x = 0.0;
	y = 0.0;
	width = 640.0;
	height = 480.0;
	float vertices[12] = { x, y, x + width, y, x + width, y + height, x, y, x + width, y + height, x, y + height };

	float texCoords[12] = { 0., 0., 1., 0., 1., 1., 0., 0., 1., 1., 0., 1. };

	apret = false;
	death1 = false;
	death2 = false;

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

	//Creem el sol
	string file1 = "images/SolInvertido.png";
	string file2 = "images/Sol.png";
	sol1 = new Sol();
	sol1->init(glm::ivec2(23 * 16, 10 * 16), texProgram, file1);

	sol2 = new Sol();
	sol2->init(glm::ivec2(23 * 16, 16 * 16), texProgram, file2);


	

	//Creació tilemap

	map = TileMap::createTileMap("levels/lvl2.txt", glm::vec2(SCREEN_X, SCREEN_Y), texProgram);
	player = new Player();
	player->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram);
	player->setPosition(glm::vec2(INIT_PLAYER_X_TILES * map->getTileSize(), INIT_PLAYER_Y_TILES * map->getTileSize()));
	player->setTileMap(map);

	player2 = new Player2();
	player2->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram);
	player2->setPosition(glm::vec2(INIT_PLAYER2_X_TILES * map->getTileSize(), INIT_PLAYER2_Y_TILES * map->getTileSize()));
	player2->setTileMap(map);


	explosio1 = new Explosio();
	string expl = "images/Explosio.png";
	explosio1->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, expl);
	explosio1->setPosition(glm::vec2(INIT_PLAYER_X_TILES * map->getTileSize(), INIT_PLAYER_Y_TILES * map->getTileSize()));
	explosio1->setTileMap(map);

	explosio2 = new Explosio();
	explosio2->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram, expl);
	explosio2->setPosition(glm::vec2(INIT_PLAYER2_X_TILES * map->getTileSize(), INIT_PLAYER2_Y_TILES * map->getTileSize()));
	explosio2->setTileMap(map);

	//creem bandera
	bandera = new Bandera();
	bandera->setId(1);
	bandera->init(glm::ivec2(17 * 16, 10 * 16), texProgram, "images/Bandera.png");
	bandera->setPlayer(player);
	bandera->setPlayer2(player2);

	bandera2 = new Bandera();
	bandera2->setId(2);
	bandera2->init(glm::ivec2(37 * 16, 18 * 16), texProgram, "images/BanderaInverted.png");
	bandera2->setPlayer(player);
	bandera2->setPlayer2(player2);

	//cactus
	string cactusB = "images/BigCactus.png";
	string cactusP = "images/SmallCactus.png";
	string cactusBI = "images/BigCactusInvertido.png";
	string cactusPI = "images/SmallCactusInvertido.png";

	cactus1 = new Cactus();
	cactus1->init(glm::ivec2(24 * 16, 13 * 16), texProgram, cactusP);
	cactus2 = new Cactus();
	cactus2->init(glm::ivec2(27 * 16, 13 * 16), texProgram, cactusB);
	cactus3 = new Cactus();
	cactus3->init(glm::ivec2(30 * 16, 11 * 16), texProgram, cactusB);
	cactus4 = new Cactus();
	cactus4->init(glm::ivec2(55 * 16, 11 * 16), texProgram, cactusP);
	cactus5 = new Cactus();
	cactus5->init(glm::ivec2(58 * 16, 11 * 16), texProgram, cactusB);
	cactus6 = new Cactus();
	cactus6->init(glm::ivec2(58 * 16, 18 * 16), texProgram, cactusBI);
	cactus7 = new Cactus();
	cactus7->init(glm::ivec2(55 * 16, 18 * 16), texProgram, cactusPI);
	cactus8 = new Cactus();
	cactus8->init(glm::ivec2(42 * 16, 18 * 16), texProgram, cactusPI);
	cactus9 = new Cactus();
	cactus9->init(glm::ivec2(40 * 16, 18 * 16), texProgram, cactusBI);
	cactus10 = new Cactus();
	cactus10->init(glm::ivec2(31 * 16, 20 * 16), texProgram, cactusPI);
	cactus11 = new Cactus();
	cactus11->init(glm::ivec2(32 * 16, 20 * 16), texProgram, cactusPI);
	cactus12 = new Cactus();
	cactus12->init(glm::ivec2(24 * 16, 24 * 16), texProgram, cactusPI);

	//cactuspincho
	string cactusf1 = "images/ObstaclecactusInverted.png";
	cactusp1 = new CactusPincho();
	cactusp1->init(glm::ivec2(33 * 16, 10 * 16), texProgram, cactusf1);
	cactusp2 = new CactusPincho();
	cactusp2->init(glm::ivec2(35 * 16, 10 * 16), texProgram, cactusf1);
	cactusp3 = new CactusPincho();
	cactusp3->init(glm::ivec2(34 * 16, 10 * 16), texProgram, cactusf1);
	cactusp4 = new CactusPincho();
	cactusp4->init(glm::ivec2(45 * 16, 12 * 16), texProgram, cactusf1);
	cactusp5 = new CactusPincho();
	cactusp5->init(glm::ivec2(47 * 16, 12 * 16), texProgram, cactusf1);
	cactusp6 = new CactusPincho();
	cactusp6->init(glm::ivec2(22 * 16, 20 * 16), texProgram, cactusf1);
	cactusp7 = new CactusPincho();
	cactusp7->init(glm::ivec2(24 * 16, 20 * 16), texProgram, cactusf1);

	//interruptor
	string inter = "images/SwitchInverted.png";
	interruptor = new Interruptor();
	interruptor->init(glm::ivec2(23 * 16, 18 * 16), texProgram, inter);

	//barrera
	string bar = "images/Bloc.png";
	barrera1 = new Barrera();
	barrera1->init(glm::ivec2(20 * 16+4, 10 * 16 + 8), texProgram,  bar);
	barrera2 = new Barrera();
	barrera2->init(glm::ivec2(20 * 16+4, 9 * 16), texProgram, bar);
	barrera3 = new Barrera();
	barrera3->init(glm::ivec2(20 * 16+4, 7 * 16 + 8), texProgram, bar);


	//pintem palmeras de fondo
	string fileB = "images/BigPalmera.png";
	string fileS = "images/SmallPalmera.png";
	string fileBI = "images/BigPalmeraI.png";
	string fileSI = "images/SmallPalmeraI.png";
	palmera1 = new Palmera();
	palmera1->init(glm::ivec2(38 * 16, 7 * 16), texProgram, fileB);

	palmera2 = new Palmera();
	palmera2->init(glm::ivec2(32 * 16, 20 * 16), texProgram, fileBI);

	palmera3 = new Palmera();
	palmera3->init(glm::ivec2(55 * 16, 7 * 16), texProgram, fileB);

	palmera4 = new Palmera();
	palmera4->init(glm::ivec2(55 * 16, 18 * 16), texProgram, fileBI);

	palmera5 = new Palmera();
	palmera5->init(glm::ivec2(23 * 16, 9 * 16), texProgram, fileS);

	palmera6 = new Palmera();
	palmera6->init(glm::ivec2(23 * 16, 24 * 16), texProgram, fileSI);
	

	currentTime = 0.0f;
}

void Scene2::update(int deltaTime)
{
	player->setGodMode(godMode);
	player2->setGodMode(godMode);

	if (player->imDead()) {
		death1 = true;
	}

	if (player2->imDead2()) {
		death2 = true;
	}


	currentTime += deltaTime;
	if (!death2 && !death1) {
		player->update(deltaTime);
		player2->update(deltaTime);
	}

	if ((player2->inter2()|| Game::instance().getKey(int('8'))) && !apret) {
		apret = true;
		map->setNoBloc();
		interruptor->apretar();
		barrera1->setExplotar();
		barrera2->setExplotar();
		barrera3->setExplotar();
	}


	currentTime += deltaTime;

	//moure camara
	projection = glm::ortho((((player->getX()+player2->getX())/2) - float(SCREEN_WIDTH / 2) / 2), (((player->getX() + player2->getX()) / 2) + float(SCREEN_WIDTH / 2) / 2), float((SCREEN_HEIGHT / 2) - 1), 0.f);

	//moure fons
	float vertices[12] = { (((player->getX() + player2->getX()) / 2) - float(SCREEN_WIDTH / 2) / 2) , 0.0, (((player->getX() + player2->getX()) / 2) + float(SCREEN_WIDTH / 2) / 2) , 0.0, (((player->getX() + player2->getX()) / 2) + float(SCREEN_WIDTH / 2) / 2), SCREEN_HEIGHT / 2 , (((player->getX() + player2->getX()) / 2) - float(SCREEN_WIDTH / 2) / 2), 0.0, (((player->getX() + player2->getX()) / 2) + float(SCREEN_WIDTH / 2) / 2), SCREEN_HEIGHT / 2, (((player->getX() + player2->getX()) / 2) - float(SCREEN_WIDTH / 2) / 2), SCREEN_HEIGHT / 2 };

	glBindVertexArray(vaoFons);
	glBindBuffer(GL_ARRAY_BUFFER, vboFons);
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), &vertices[0], GL_STATIC_DRAW);
	posLocation = texProgram.bindVertexAttribute("position", 2, 0, 0);


	bandera->update(deltaTime);
	bandera2->update(deltaTime);
	cactusp1->update(deltaTime);
	cactusp2->update(deltaTime);
	cactusp3->update(deltaTime);
	cactusp4->update(deltaTime);
	cactusp5->update(deltaTime);
	cactusp6->update(deltaTime);
	cactusp7->update(deltaTime);
	interruptor->update(deltaTime);
	barrera1->update(deltaTime);
	barrera2->update(deltaTime);
	barrera3->update(deltaTime);

	explosio1->setPosition(player->getPos());
	if (death1) explosio1->update(deltaTime);
	explosio2->setPosition(player2->getPos());
	if (death2) explosio2->update(deltaTime);

	if (bandera->getBandaux() && bandera2->getBandaux2()) {
		player->treureSons();
		player2->treureSons();
	}

	if (!player->gethasWon()) player->sethasWon(bandera->getBandaux() && bandera2->getBandaux2());
	if (!player2->gethasWon()) player2->sethasWon(bandera->getBandaux() && bandera2->getBandaux2());
}

void Scene2::render()
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


	palmera1->render();
	palmera2->render();
	
	palmera3->render();
	palmera4->render();
	palmera5->render();
	palmera6->render();
	
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

	cactusp1->render();
	cactusp2->render();
	cactusp3->render();
	cactusp4->render();
	cactusp5->render();
	cactusp6->render();
	cactusp7->render();

	interruptor->render();

	barrera1->render();
	barrera2->render();
	barrera3->render();

	bandera->render();
	bandera2->render();

	if (!death1) {
		player->render();
	}

	if (!death2) {
		player2->render();
	}

	if (death1) {
		explosio1->render();
		if (explosio1->numSprite() == 1) {
			engine->stopAllSounds();
			player->treureSons();
			player2->treureSons();
			engine->play2D("sounds/Death.wav", false);
		}
		if (explosio1->numSprite() == 16) {
			Sleep(500);
			Reload();
		}
	}
	if (death2) {
		explosio2->render();
		if (explosio2->numSprite() == 1) {
			engine->stopAllSounds();
			player->treureSons();
			player2->treureSons();
			engine->play2D("sounds/Death.wav", false);
		}
		if (explosio2->numSprite() == 16) {
			Sleep(500);
			Reload();
		}
	}
}

void Scene2::initShaders()
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

bool Scene2::changeScene() {
	if (bandera->endFrame() && bandera2->endFrame()) {
		engine->stopAllSounds();
		engine->play2D("sounds/Win.wav", false);
		Sleep(1000);
		engine->drop();
		return 1;

	}
	return 0;
}

void Scene2::deleteEngine()
{
	player->treureSons();
	player2->treureSons();
	engine->drop();
}

void Scene2::setGodMode(bool g)
{
	godMode = g;
}