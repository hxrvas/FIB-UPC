#include <iostream>
#include <cmath>
#include "Palmera.h"

void Palmera::init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram,string file)
{
	spritesheet.loadFromFile(file, TEXTURE_PIXEL_FORMAT_RGBA);
	sprite = Sprite::createSprite(glm::ivec2(80,80), glm::vec2(1, 1), &spritesheet, &shaderProgram);
	sprite->setNumberAnimations(1);

	sprite->setAnimationSpeed(0, 8);
	sprite->addKeyframe(0, glm::vec2(0.f, 0.f));


	sprite->changeAnimation(0);
	tileMapDispl = tileMapPos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x), float(tileMapDispl.y)));

}

void Palmera::update(int deltaTime) {
	sprite->update(deltaTime);
}

void Palmera::render()
{
	sprite->render();
}