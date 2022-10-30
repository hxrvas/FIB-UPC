#include <iostream>
#include <cmath>
#include "Sol.h"

void Sol::init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram, string &file)
{
	spritesheet.loadFromFile(file, TEXTURE_PIXEL_FORMAT_RGBA);
	sprite = Sprite::createSprite(glm::ivec2(64, 64), glm::vec2(1., 1.), &spritesheet, &shaderProgram);
	sprite->setNumberAnimations(1);

	sprite->setAnimationSpeed(0, 8);
	sprite->addKeyframe(0, glm::vec2(0.f, 0.f));



	sprite->changeAnimation(0);
	tileMapDispl = tileMapPos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x), float(tileMapDispl.y)));

}

void Sol::update(int deltaTime) {
	sprite->update(deltaTime);
}

void Sol::render()
{
	sprite->render();
}