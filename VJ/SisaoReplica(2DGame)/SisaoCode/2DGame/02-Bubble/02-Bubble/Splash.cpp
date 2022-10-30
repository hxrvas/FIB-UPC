#include <iostream>
#include <cmath>
#include "Splash.h"

void Splash::init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram, string file)
{
	r = false;
	spritesheet.loadFromFile(file, TEXTURE_PIXEL_FORMAT_RGBA);
	sprite = Sprite::createSprite(glm::ivec2(64, 64), glm::vec2(1.0, 0.167), &spritesheet, &shaderProgram);
	sprite->setNumberAnimations(2);

	sprite->setAnimationSpeed(0, 8);
	sprite->addKeyframe(0, glm::vec2(0.f, 0.834f));

	sprite->setAnimationSpeed(1, 8);
	sprite->addKeyframe(1, glm::vec2(0.f, 0.f));
	sprite->addKeyframe(1, glm::vec2(0.f, 0.167f));
	sprite->addKeyframe(1, glm::vec2(0.f, 0.334f));
	sprite->addKeyframe(1, glm::vec2(0.f, 0.5f));
	sprite->addKeyframe(1, glm::vec2(0.f, 0.667f));


	sprite->changeAnimation(1);
	tileMapDispl = tileMapPos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + posPlayer.x-16), float(tileMapDispl.y + posPlayer.y-16)));

}

void Splash::update(int deltaTime) {
		sprite->update(deltaTime);
		if (sprite->getFrame() == 5)
		{
			sprite->changeAnimation(0);
		}
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + posPlayer.x-16), float(tileMapDispl.y + posPlayer.y-16)));
}

void Splash::setPosition(const glm::vec2 &pos)
{
	posPlayer = pos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + posPlayer.x-16), float(tileMapDispl.y + posPlayer.y-16)));
}



void Splash::render()
{
	if (r) {
		sprite->render();
	}
}


void Splash::setTileMap(TileMap *tileMap)
{
	map = tileMap;
}
void Splash::play()
{
	r = true;
}

void Splash::setR(bool b)
{
	r = b;
}