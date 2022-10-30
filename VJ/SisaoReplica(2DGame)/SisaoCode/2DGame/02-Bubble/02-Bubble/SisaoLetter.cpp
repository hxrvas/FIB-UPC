#include "SisaoLetter.h"


#include <iostream>
#include <cmath>
#include "SisaoLetter.h"

void SisaoLetter::init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram, string& file)
{
	spritesheet.loadFromFile(file, TEXTURE_PIXEL_FORMAT_RGBA);
	sprite = Sprite::createSprite(glm::ivec2(320, 320), glm::vec2(1.f, 0.167f), &spritesheet, &shaderProgram);
	sprite->setNumberAnimations(6);

	sprite->setAnimationSpeed(0, 4);
	sprite->addKeyframe(0, glm::vec2(0.f, 0.f));
	sprite->addKeyframe(0, glm::vec2(0.f,0.167f));
	sprite->addKeyframe(0, glm::vec2(0.f, 0.334f));
	sprite->addKeyframe(0, glm::vec2(0.f, 0.5f));
	sprite->addKeyframe(0, glm::vec2(0.f, 0.667f));
	sprite->addKeyframe(0, glm::vec2(0.f, 0.834f));



	sprite->changeAnimation(0);
	tileMapDispl = tileMapPos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x), float(tileMapDispl.y)));

}

void SisaoLetter::update(int deltaTime) {
	sprite->update(deltaTime);
}

void SisaoLetter::render()
{
	sprite->render();
}