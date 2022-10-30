#include <iostream>
#include <cmath>
#include "Caixa.h"

#define FALL_STEP 4

void Caixa::init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram, string& file)
{
	force = 5;
	engine = createIrrKlangDevice();
	spritesheet.loadFromFile(file, TEXTURE_PIXEL_FORMAT_RGBA);
	sprite = Sprite::createSprite(glm::ivec2(32, 32), glm::vec2(1.0, 1.0), &spritesheet, &shaderProgram);
	sprite->setNumberAnimations(1);

	sprite->setAnimationSpeed(0, 8);
	sprite->addKeyframe(0, glm::vec2(0.f, 0.f));



	sprite->changeAnimation(0);
	tileMapDispl = tileMapPos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + pos.x), float(tileMapDispl.y + pos.y)));

}

void Caixa::setTileMap(TileMap *tileMap)
{
	map = tileMap;
}

void Caixa::setPlayer(Player *p)
{
	player = p;
}

void Caixa::update(int deltaTime) {
	sprite->update(deltaTime);


	if (!floating)
	{
		if (player->collisionright(pos, glm::ivec2(32, 32)))
		{
			movingleft = true;
			pos.x -= 3;


			if (map->collisionMoveLeft(pos, glm::ivec2(32, 32)))
			{
				pos.x += 3;
			}
		}

		if (player->collisionleft(pos, glm::ivec2(32, 32)))
		{
			movingright = true;
			pos.x += 3;

			if (map->collisionMoveRight(pos, glm::ivec2(32, 32)))
			{
				pos.x -= 3;
			}
		}


		pos.y += FALL_STEP;

		if (map->collisionMoveDown(pos, glm::ivec2(32, 32), &pos.y))
		{
			contador = 10;
			force = 3;
			movingleft = false;
			movingright = false;
		}
		else if ((map->changeStateDown(pos, glm::ivec2(32, 32), &pos.y)) == 1)
		{
			pos.y += 12;
			if (floating == false) {
				engine->play2D("sounds/Splash.wav", false);
			}
			floating = true;
		}
		else if (movingleft) {
			contador -= 1;

			pos.x -= force;
			if (contador == 0) {

				if (force > 0) force -= 1;
				contador = 10;
			}

		}
		else if (movingright) {
			contador -= 1;

			pos.x += force;
			if (contador == 0) {
				if (force > 0) force -= 1;
				contador = 10;
			}
		}


		sprite->setPosition(glm::vec2(float(tileMapDispl.x + pos.x), float(tileMapDispl.y + pos.y)));
	}
}

void Caixa::setPosition(const glm::vec2 &p)
{
	pos = p;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + pos.x), float(tileMapDispl.y + pos.y)));
}

void Caixa::render()
{
	sprite->render();
}

glm::ivec2 Caixa::getPos() {
	return pos;
}

bool Caixa::getFloating()
{
	return floating;
}