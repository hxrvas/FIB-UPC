#include <iostream>
#include <cmath>
#include "Bandera.h"

void Bandera::init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram, string file)
{
	spritesheet.loadFromFile(file, TEXTURE_PIXEL_FORMAT_RGBA);
	sprite = Sprite::createSprite(glm::ivec2(64, 64), glm::vec2(0.25, 0.5), &spritesheet, &shaderProgram);
	sprite->setNumberAnimations(4);
	engine = createIrrKlangDevice();

	sprite->setAnimationSpeed(0, 8);
	sprite->addKeyframe(0, glm::vec2(0.f, 0.f));

	sprite->setAnimationSpeed(1, 16);
	sprite->addKeyframe(1, glm::vec2(0.f, 0.f));
	sprite->addKeyframe(1, glm::vec2(0.25f, 0.f));
	sprite->addKeyframe(1, glm::vec2(0.5f, 0.f));
	sprite->addKeyframe(1, glm::vec2(0.75f, 0.f));
	sprite->addKeyframe(1, glm::vec2(0.f, 0.5f));
	sprite->addKeyframe(1, glm::vec2(0.25f, 0.5f));
	sprite->addKeyframe(1, glm::vec2(0.5f, 0.5f));
	sprite->addKeyframe(1, glm::vec2(0.75f, 0.5f));

	sprite->setAnimationSpeed(2, 16);
	sprite->addKeyframe(2, glm::vec2(0.75f, 0.5f));
	sprite->addKeyframe(2, glm::vec2(0.5f, 0.5f));
	sprite->addKeyframe(2, glm::vec2(0.25f, 0.5f));
	sprite->addKeyframe(2, glm::vec2(0.f, 0.5f));
	sprite->addKeyframe(2, glm::vec2(0.75f, 0.f));
	sprite->addKeyframe(2, glm::vec2(0.5f, 0.f));
	sprite->addKeyframe(2, glm::vec2(0.25f, 0.f));
	sprite->addKeyframe(2, glm::vec2(0.f, 0.f));

	sprite->setAnimationSpeed(3, 8);
	sprite->addKeyframe(3, glm::vec2(0.75f, 0.5f));




	sprite->changeAnimation(0);
	tileMapDispl = tileMapPos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x), float(tileMapDispl.y)));

}

void Bandera::update(int deltaTime) {
	sprite->update(deltaTime);
	if (id == 1 && player->bandera() == true && (sprite->animation() != 1) && band_aux == false) {
		band_aux = true;
		sprite->changeAnimation(1);
	}
	if (id == 2 && player2->bandera2() == true && (sprite->animation() != 1) && band2_aux == false) {
		band2_aux = true;
		sprite->changeAnimation(1);
	}
	 
 	if (sprite->animation() == 1 && sprite->getFrame() == 8) {
		sprite->changeAnimation(3);
	}

	if (id == 1 && band_aux && !player->bandera()) {
		band_aux = false;
		sprite->changeAnimation(2);
	}
	if (id == 2 && band2_aux && !player2->bandera2()) {
		band2_aux = false;
		sprite->changeAnimation(2);
	}

	if (sprite->animation() == 2 && sprite->getFrame() == 8) {
		sprite->changeAnimation(0);
	}
	
}

void Bandera::setPlayer(Player *play) {
	player = play;
}

void Bandera::setPlayer2(Player2 *play2) {
	player2 = play2;
}

void Bandera::render()
{
	sprite->render();
}

void Bandera::setId(int idt) {
	id = idt;
}

bool Bandera::getBandaux() {
	return band_aux;
}

bool Bandera::getBandaux2() {
	return band2_aux;
}

bool Bandera::endFrame() {
	return (sprite->animation() == 3);
}