#include <iostream>
#include <cmath>
#include "Explosio.h"

void Explosio::init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram, string file)
{
	spritesheet.loadFromFile(file, TEXTURE_PIXEL_FORMAT_RGBA);
	sprite = Sprite::createSprite(glm::ivec2(256, 256), glm::vec2(0.25, 0.25), &spritesheet, &shaderProgram);
	sprite->setNumberAnimations(1);

	sprite->setAnimationSpeed(0, 32);
	sprite->addKeyframe(0, glm::vec2(0.f, 0.f));
	sprite->addKeyframe(0, glm::vec2(0.25f, 0.f));
	sprite->addKeyframe(0, glm::vec2(0.5f, 0.f));
	sprite->addKeyframe(0, glm::vec2(0.75f, 0.f));
	sprite->addKeyframe(0, glm::vec2(0.f, 0.25f));
	sprite->addKeyframe(0, glm::vec2(0.25f, 0.25f));
	sprite->addKeyframe(0, glm::vec2(0.5f, 0.25f));
	sprite->addKeyframe(0, glm::vec2(0.75f, 0.25f));
	sprite->addKeyframe(0, glm::vec2(0.f, 0.5f));
	sprite->addKeyframe(0, glm::vec2(0.25f, 0.5f));
	sprite->addKeyframe(0, glm::vec2(0.5f, 0.5f));
	sprite->addKeyframe(0, glm::vec2(0.75f, 0.5f));
	sprite->addKeyframe(0, glm::vec2(0.f, 0.75f));
	sprite->addKeyframe(0, glm::vec2(0.25f, 0.75f));
	sprite->addKeyframe(0, glm::vec2(0.5f, 0.75f));
	sprite->addKeyframe(0, glm::vec2(0.75f, 0.75f));

	
	sprite->changeAnimation(0);
	tileMapDispl = tileMapPos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + posPlayer.x), float(tileMapDispl.y + posPlayer.y) - 128.f));

}

void Explosio::update(int deltaTime) {
	sprite->update(deltaTime);
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + posPlayer.x) - 128.f, float(tileMapDispl.y + posPlayer.y) - 128.f));
}

void Explosio::setPosition(const glm::vec2 &pos)
{
	posPlayer = pos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + posPlayer.x)-128.f, float(tileMapDispl.y + posPlayer.y)-128.f));
}



void Explosio::render()
{
	sprite->render();
}

int Explosio::numSprite() {
	return sprite->getFrame();
}

void Explosio::setTileMap(TileMap *tileMap)
{
	map = tileMap;
}