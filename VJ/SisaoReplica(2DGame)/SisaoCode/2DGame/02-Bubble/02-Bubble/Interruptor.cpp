#include <iostream>
#include <cmath>
#include "Interruptor.h"


void Interruptor::init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram, string& file)
{
	apretat = false;
	aux_apretat = false;
	engine = createIrrKlangDevice();
	spritesheet.loadFromFile(file, TEXTURE_PIXEL_FORMAT_RGBA);
	sprite = Sprite::createSprite(glm::ivec2(24, 24), glm::vec2(1.0, 0.5), &spritesheet, &shaderProgram);
	sprite->setNumberAnimations(2);

	sprite->setAnimationSpeed(0, 8);
	sprite->addKeyframe(0, glm::vec2(0.f, 0.f));

	sprite->setAnimationSpeed(1, 8);
	sprite->addKeyframe(1, glm::vec2(0.f, 0.5f));



	sprite->changeAnimation(0);
	tileMapDispl = tileMapPos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x), float(tileMapDispl.y)));

}

void Interruptor::update(int deltaTime) {
	sprite->update(deltaTime);
	if (apretat && aux_apretat == false) {
		aux_apretat = true;
		engine->play2D("sounds/Interruptor.wav", false);
		sprite->changeAnimation(1);
	}
}

void Interruptor::render()
{
	sprite->render();
}

void Interruptor::apretar()
{
	apretat = true;
}