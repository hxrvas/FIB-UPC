#include <cmath>
#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include "Player.h"
#include "Game.h"


#define JUMP_ANGLE_STEP 4
#define JUMP_HEIGHT 80
#define FALL_STEP 5


enum PlayerAnims
{
	STAND_LEFT, STAND_RIGHT, MOVE_LEFT, MOVE_RIGHT, JUMP_UP_RIGHT, JUMP_DOWN_RIGHT, JUMP_UP_LEFT, JUMP_DOWN_LEFT
};


void Player::init(const glm::ivec2 &tileMapPos, ShaderProgram &shaderProgram)
{
	hasWon = false;
	godMode = false;
	posCaixa.x = -1;
	posCaixa.y = -1;
	posCaixa2.x = -1;
	posCaixa2.y = -1;
	bJumping = false;
	dead = false;
	inte = false;
	pressed = false;
	caminant = false;

	engine = createIrrKlangDevice();
	spritesheet.loadFromFile("images/sisao.png", TEXTURE_PIXEL_FORMAT_RGBA);
	sprite = Sprite::createSprite(glm::ivec2(32, 32), glm::vec2(0.125, 0.125), &spritesheet, &shaderProgram);
	sprite->setNumberAnimations(8);
	
		sprite->setAnimationSpeed(STAND_LEFT, 10);
		sprite->addKeyframe(STAND_LEFT, glm::vec2(0.25f, 0.f));
		sprite->addKeyframe(STAND_LEFT, glm::vec2(0.25f, 0.125f));
		sprite->addKeyframe(STAND_LEFT, glm::vec2(0.25f, 0.25f));
		sprite->addKeyframe(STAND_LEFT, glm::vec2(0.25f, 0.375f));
		sprite->addKeyframe(STAND_LEFT, glm::vec2(0.25f, 0.5f));
		sprite->addKeyframe(STAND_LEFT, glm::vec2(0.25f, 0.625f));
		
		sprite->setAnimationSpeed(STAND_RIGHT, 10);
		sprite->addKeyframe(STAND_RIGHT, glm::vec2(0.375f, 0.f));
		sprite->addKeyframe(STAND_RIGHT, glm::vec2(0.375f, 0.125f));
		sprite->addKeyframe(STAND_RIGHT, glm::vec2(0.375f, 0.25f));
		sprite->addKeyframe(STAND_RIGHT, glm::vec2(0.375f, 0.375f));
		sprite->addKeyframe(STAND_RIGHT, glm::vec2(0.375f, 0.5f));
		sprite->addKeyframe(STAND_RIGHT, glm::vec2(0.375f, 0.625f));
		
		sprite->setAnimationSpeed(MOVE_LEFT, 12);
		sprite->addKeyframe(MOVE_LEFT, glm::vec2(0.f, 0.f));
		sprite->addKeyframe(MOVE_LEFT, glm::vec2(0.f, 0.125f));
		sprite->addKeyframe(MOVE_LEFT, glm::vec2(0.f, 0.25f));
		sprite->addKeyframe(MOVE_LEFT, glm::vec2(0.f, 0.375f));
		sprite->addKeyframe(MOVE_LEFT, glm::vec2(0.f, 0.5f));
		sprite->addKeyframe(MOVE_LEFT, glm::vec2(0.f, 0.625f));
		
		sprite->setAnimationSpeed(MOVE_RIGHT, 12);
		sprite->addKeyframe(MOVE_RIGHT, glm::vec2(0.125, 0.f));
		sprite->addKeyframe(MOVE_RIGHT, glm::vec2(0.125, 0.125f));
		sprite->addKeyframe(MOVE_RIGHT, glm::vec2(0.125, 0.25f));
		sprite->addKeyframe(MOVE_RIGHT, glm::vec2(0.125, 0.375f));
		sprite->addKeyframe(MOVE_RIGHT, glm::vec2(0.125, 0.5f));
		sprite->addKeyframe(MOVE_RIGHT, glm::vec2(0.125, 0.625f));

		sprite->setAnimationSpeed(JUMP_UP_RIGHT, 8);
		sprite->addKeyframe(JUMP_UP_RIGHT, glm::vec2(0.5, 0.f));


		sprite->setAnimationSpeed(JUMP_DOWN_RIGHT, 8);
		sprite->addKeyframe(JUMP_DOWN_RIGHT, glm::vec2(0.5, 0.125f));

		sprite->setAnimationSpeed(JUMP_UP_LEFT, 8);
		sprite->addKeyframe(JUMP_UP_LEFT, glm::vec2(0.625, 0.f));


		sprite->setAnimationSpeed(JUMP_DOWN_LEFT, 8);
		sprite->addKeyframe(JUMP_DOWN_LEFT, glm::vec2(0.625, 0.125f));
	
		
	sprite->changeAnimation(0);
	tileMapDispl = tileMapPos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + posPlayer.x), float(tileMapDispl.y + posPlayer.y)));
	
}

void Player::update(int deltaTime)
{

	if (!hasWon) {

		sprite->update(deltaTime);

		if (Game::instance().getSpecialKey(GLUT_KEY_LEFT))
		{
			if (caminant == false) {
				caminant = true;
				engine->play2D("sounds/Run.wav", true);
			}
			if (sprite->animation() != MOVE_LEFT)
				sprite->changeAnimation(MOVE_LEFT);
			posPlayer.x -= 3;
			if ((map->changeStateLeft(posPlayer, glm::ivec2(32, 32))) == 1)
			{
				if (!godMode)
				{
					dead = true;
				}
			}
			else if ((map->changeStateLeft(posPlayer, glm::ivec2(32, 32))) == 2)
			{
				band = true;
			}
			else if ((map->changeStateLeft(posPlayer, glm::ivec2(32, 32))) == 3)
			{
				inte = true;
			}
			else if (map->collisionMoveLeft(posPlayer, glm::ivec2(32, 32)))
			{
				posPlayer.x += 3;
			}
			else band = false;
		}


		else if (Game::instance().getSpecialKey(GLUT_KEY_RIGHT))
		{
			if (caminant == false) {
				caminant = true;
				engine->play2D("sounds/Run.wav", true);
			}
			if (sprite->animation() != MOVE_RIGHT)
				sprite->changeAnimation(MOVE_RIGHT);
			posPlayer.x += 3;
			if ((map->changeStateRight(posPlayer, glm::ivec2(32, 32))) == 1)
			{
				if (!godMode)
				{
					dead = true;
				}
			}

			else if ((map->changeStateRight(posPlayer, glm::ivec2(32, 32))) == 2)
			{
				band = true;
			}

			else if ((map->changeStateLeft2(posPlayer, glm::ivec2(32, 32))) == 3)
			{
				inte = true;
			}

			else if (map->collisionMoveRight(posPlayer, glm::ivec2(32, 32)))
			{
				posPlayer.x -= 3;
			}
			else band = false;
		}

		else
		{
			caminant = false;
			engine->stopAllSounds();
			if (sprite->animation() == MOVE_LEFT || (!bJumping && ((sprite->animation() == JUMP_UP_LEFT) || (sprite->animation() == JUMP_DOWN_LEFT))))
				sprite->changeAnimation(STAND_LEFT);
			else if (sprite->animation() == MOVE_RIGHT || (!bJumping && ((sprite->animation() == JUMP_UP_RIGHT) || (sprite->animation() == JUMP_DOWN_RIGHT))))
				sprite->changeAnimation(STAND_RIGHT);
		}


		if (bJumping)
		{
			caminant = false;
			engine->stopAllSounds();

			if (sprite->animation() == MOVE_RIGHT || sprite->animation() == STAND_RIGHT) {
				sprite->changeAnimation(JUMP_UP_RIGHT);
			}
			else if (sprite->animation() == MOVE_LEFT || sprite->animation() == STAND_LEFT) {
				sprite->changeAnimation(JUMP_UP_LEFT);
			}
			jumpAngle += JUMP_ANGLE_STEP;

			if ((jumpAngle >= 90) && (sprite->animation() == JUMP_UP_RIGHT))
				sprite->changeAnimation(JUMP_DOWN_RIGHT);
			else if ((jumpAngle >= 90) && (sprite->animation() == JUMP_UP_LEFT))
				sprite->changeAnimation(JUMP_DOWN_LEFT);

			if (jumpAngle == 180)
			{
				bJumping = false;
				posPlayer.y = startY;
			}
			else
			{
				posPlayer.y = int(startY - JUMP_HEIGHT * sin(3.14159f * jumpAngle / 180.f));
				if (jumpAngle > 90)
				{
					bJumping = (!map->collisionMoveDown(posPlayer, glm::ivec2(32, 32), &posPlayer.y)) && !((posCaixa.x != -1) && (collisionMoveDown(1))) && !((posCaixa.x != -1) && (collisionMoveDown(2)));

					if ((map->changeStateDown(posPlayer, glm::ivec2(32, 32), &posPlayer.y)) == 1)
					{
						if (!godMode)
						{
							dead = true;
						}
						else {
							bJumping = false;
						}
					}
					else if ((map->changeStateDown(posPlayer, glm::ivec2(32, 32), &posPlayer.y)) == 2)
					{
						band = true;
					}
					else if ((map->changeStateDown(posPlayer, glm::ivec2(32, 32), &posPlayer.y)) == 3)
					{
						inte = true;
					}


				}
				else
				{
					bJumping = !map->collisionMoveUp(posPlayer, glm::ivec2(32, 32), &posPlayer.y);

					if ((map->changeStateUp(posPlayer, glm::ivec2(32, 32), &posPlayer.y)) == 1)
					{
						if (!godMode)
						{
							dead = true;
						}
						else {
							bJumping = false;
						}
					}
					else if ((map->changeStateUp(posPlayer, glm::ivec2(32, 32), &posPlayer.y)) == 2)
					{
						band = true;
					}

					else if ((map->changeStateUp(posPlayer, glm::ivec2(32, 32), &posPlayer.y)) == 3)
					{
						inte = true;
					}



				}
			}
		}

		else
		{
			posPlayer.y += FALL_STEP;


			if (map->collisionMoveDown(posPlayer, glm::ivec2(32, 32), &posPlayer.y))
			{
				if (Game::instance().getSpecialKey(GLUT_KEY_UP) && pressed == false)
				{
					engine->play2D("sounds/Jump.wav", false);
					pressed = true;
					bJumping = true;
					jumpAngle = 0;
					startY = posPlayer.y;
				}
				else if (!Game::instance().getSpecialKey(GLUT_KEY_UP)) pressed = false;
			}

			else if ((posCaixa.x != -1) && (collisionMoveDown(1)))
			{
				posPlayer.y = posCaixa.y - 31;
				if (Game::instance().getSpecialKey(GLUT_KEY_UP) && pressed == false)
				{
					engine->play2D("sounds/Jump.wav", false);
					pressed = true;
					bJumping = true;
					jumpAngle = 0;
					startY = posPlayer.y;
				}
				else if (!Game::instance().getSpecialKey(GLUT_KEY_UP)) pressed = false;
			}
			else if ((posCaixa2.x != -1) && (collisionMoveDown(2)))
			{
				posPlayer.y = posCaixa2.y - 31;
				if (Game::instance().getSpecialKey(GLUT_KEY_UP) && pressed == false)
				{
					engine->play2D("sounds/Jump.wav", false);
					pressed = true;
					bJumping = true;
					jumpAngle = 0;
					startY = posPlayer.y;
				}
				else if (!Game::instance().getSpecialKey(GLUT_KEY_UP)) pressed = false;
			}
			else if ((map->changeStateDown(posPlayer, glm::ivec2(32, 32), &posPlayer.y)) == 1)
			{
				if (!godMode)
				{
					dead = true;
				}
				else {
					posPlayer.y -= FALL_STEP;
					if (Game::instance().getSpecialKey(GLUT_KEY_UP) && pressed == false)
					{
						engine->play2D("sounds/Jump.wav", false);
						pressed = true;
						bJumping = true;
						jumpAngle = 0;
						startY = posPlayer.y;
					}
					else if (!Game::instance().getSpecialKey(GLUT_KEY_UP)) pressed = false;
				}
			}
			else if ((map->changeStateDown(posPlayer, glm::ivec2(32, 32), &posPlayer.y)) == 2)
			{
				band = true;
			}
			else if ((map->changeStateDown(posPlayer, glm::ivec2(32, 32), &posPlayer.y)) == 3)
			{
				inte = true;
			}
			else
			{
				if ((sprite->animation() == MOVE_RIGHT) || (sprite->animation() == STAND_RIGHT) || (sprite->animation() == JUMP_UP_RIGHT))
					sprite->changeAnimation(JUMP_DOWN_RIGHT);
				else if ((sprite->animation() == MOVE_LEFT) || (sprite->animation() == STAND_LEFT) || (sprite->animation() == JUMP_UP_LEFT))
					sprite->changeAnimation(JUMP_DOWN_LEFT);
			}
		}

		sprite->setPosition(glm::vec2(float(tileMapDispl.x + posPlayer.x), float(tileMapDispl.y + posPlayer.y)));
	}
}

bool Player::collisionleft(const glm::ivec2 &pos, const glm::ivec2 &size) const
{
	int x0, x1, y0, y1;

	x0 = pos.x;
	x1 = pos.x+ size.x - 1;
	y0 = pos.y;
	y1 = (pos.y + size.y - 1);

	for (int x = x0; x <= x1; x++)
	{
		for (int y = y0; y <= y1; y++)
		{
			if (y == posPlayer.y && x == posPlayer.x + size.x)
				return true;
		}
	}
	return false;
}

bool Player::collisionright(const glm::ivec2 &pos, const glm::ivec2 &size) const
{
	int x0, x1, y0, y1;

	x0 = pos.x+size.x-1;
	x1 = pos.x;
	y0 = pos.y;
	y1 = (pos.y + size.y - 1);

	for (int x = x0; x >= x1; x--)
	{
		for (int y = y0; y <= y1; y++)
		{
			if (y == posPlayer.y && x == posPlayer.x)
				return true;
		}
	}
	return false;
}

void Player::render()
{
	sprite->render();
}

void Player::setTileMap(TileMap *tileMap)
{
	map = tileMap;
}

void Player::setPosition(const glm::vec2 &pos)
{
	posPlayer = pos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + posPlayer.x), float(tileMapDispl.y + posPlayer.y)));
}

float Player::getX()
{
	return posPlayer.x;
}

bool Player::imDead() {
	return dead;
}

void Player::setDead() {
	if (!godMode) dead = true;
}

bool Player::bandera() {
	return band;
}

bool Player::inter() {
	return inte;
}

glm::ivec2 Player::getPos()
{
	return posPlayer;
}




bool Player::collisionMoveDown(int caixa) 
{
	int x0, x1, y, y0c, y1c, xc;

	x0 = posPlayer.x;
	x1 = (posPlayer.x + 50);
	y = (posPlayer.y + 31);
	if (caixa == 1)
	{
		y0c = posCaixa.y;
		y1c = posCaixa.y + 31;
		xc = posCaixa.x + 25;
	}

	if (caixa == 2)
	{
		y0c = posCaixa2.y;
		y1c = posCaixa2.y + 31;
		xc = posCaixa2.x + 25;
	}
	for (int yc = y0c; yc <= y1c; yc++)
	{
		for (int x = x0; x <= x1; x++)
		{
			if (x == xc && y == yc)
			{
				return true;
			}
		}
	}
	return false;
}

void Player::setPosCaixa(glm::ivec2 pos)
{
	posCaixa = pos;
}

void Player::setPosCaixa2(glm::ivec2 pos)
{
	posCaixa2 = pos;
}

void Player::treureSons() {
	engine->stopAllSounds();
}

void Player::setGodMode(bool g)
{
	godMode = g;
}

bool Player::collisiondownEnemic(const glm::ivec2 &pos, const glm::ivec2 &size)
{
	int x0, x1, y0c, y1c;

	x0 = pos.x ;
	x1 = pos.x + size.x - 1;

	y0c = pos.y;
	y1c = pos.y + 31;

	for (int x = x0; x <= x1; x++)
	{
		for (int y = y0c; y <= y1c; y++)
		{
			if (y == posPlayer.y + 31 && x == posPlayer.x) {
				posPlayer.y -= (y-y0c); 
				return true;
			}
		}
	}
	return false;
}

void Player::setbJumping() {
	bJumping = true;
	jumpAngle = 0;
	startY = posPlayer.y;
}

void Player::sethasWon(bool b)
{
	hasWon = b;
}

bool Player::gethasWon()
{
	return hasWon;
}