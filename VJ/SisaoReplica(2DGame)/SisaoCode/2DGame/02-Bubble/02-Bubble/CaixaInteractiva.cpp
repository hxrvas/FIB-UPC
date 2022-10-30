#include <iostream>
#include <cmath>
#include "CaixaInteractiva.h"


void CaixaInteractiva::init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram, string& file)
{
	spritesheet.loadFromFile(file, TEXTURE_PIXEL_FORMAT_RGBA);
	sprite = Sprite::createSprite(glm::ivec2(40, 40), glm::vec2(1.0, 0.5), &spritesheet, &shaderProgram);
	sprite->setNumberAnimations(2);

	sprite->setAnimationSpeed(0, 8);
	sprite->addKeyframe(0, glm::vec2(0.f, 0.f));

	sprite->setAnimationSpeed(1, 8);
	sprite->addKeyframe(1, glm::vec2(0.f, 0.5f));



	sprite->changeAnimation(0);
	tileMapDispl = tileMapPos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x), float(tileMapDispl.y)));
	seleccionat = false;

}

void CaixaInteractiva::update(int deltaTime) {
	sprite->update(deltaTime);
	if (seleccionat && sprite->animation() != 1) {
		sprite->changeAnimation(1);
	}

	else if(!seleccionat && sprite->animation() != 0) {
		sprite->changeAnimation(0);
	} 
}

void CaixaInteractiva::render()
{
	sprite->render();
}

void CaixaInteractiva::seleccionar()
{
	seleccionat = true;
}

void CaixaInteractiva::deseleccionar()
{
	seleccionat = false;
}

bool CaixaInteractiva::isSeleccionat() {
	return seleccionat;
}