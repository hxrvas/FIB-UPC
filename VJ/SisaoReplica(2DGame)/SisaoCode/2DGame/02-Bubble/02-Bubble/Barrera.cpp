#include <iostream>
#include <cmath>
#include "Barrera.h"

void Barrera::init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram, string& file)
{
	explotar = false;
	spritesheet.loadFromFile(file, TEXTURE_PIXEL_FORMAT_RGBA);
	sprite = Sprite::createSprite(glm::ivec2(24, 24), glm::vec2(0.5, 0.33), &spritesheet, &shaderProgram);
	sprite->setNumberAnimations(3);

	sprite->setAnimationSpeed(0, 8);
	sprite->addKeyframe(0, glm::vec2(0.f, 0.f));

	sprite->setAnimationSpeed(1, 8);
	sprite->addKeyframe(1, glm::vec2(0.5f, 0.f));
	sprite->addKeyframe(1, glm::vec2(0.f, 0.33f));
	sprite->addKeyframe(1, glm::vec2(0.5f, 0.33f));
	sprite->addKeyframe(1, glm::vec2(0.f, 0.66f));
	sprite->addKeyframe(1, glm::vec2(0.5f, 0.66f));

	sprite->setAnimationSpeed(2, 8);
	sprite->addKeyframe(2, glm::vec2(0.5f, 0.67f));



	sprite->changeAnimation(0);
	tileMapDispl = tileMapPos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x), float(tileMapDispl.y)));

}

void Barrera::update(int deltaTime) {
	sprite->update(deltaTime);
	if (explotar) {
		sprite->changeAnimation(1);
		explotar = false;
	}
	if (sprite->animation() == 1 && sprite->getFrame() == 5) {
		sprite->changeAnimation(2);
	}
}

void Barrera::render()
{
	sprite->render();
}

void Barrera::setExplotar() {
	explotar = true;
}