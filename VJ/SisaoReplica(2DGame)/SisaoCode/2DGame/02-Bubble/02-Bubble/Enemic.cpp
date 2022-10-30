#include <iostream>
#include <cmath>
#include "Enemic.h"

void Enemic::init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram, string& file)
{
	spritesheet.loadFromFile(file, TEXTURE_PIXEL_FORMAT_RGBA);
	sprite = Sprite::createSprite(glm::ivec2(32, 32), glm::vec2(0.33,0.25), &spritesheet, &shaderProgram);
	sprite->setNumberAnimations(3);

	moveLeft = true;

	sprite->setAnimationSpeed(0, 8);
	sprite->addKeyframe(0, glm::vec2(0.67f, 0.f));
	sprite->addKeyframe(0, glm::vec2(0.67f, 0.25f));


	sprite->setAnimationSpeed(1, 16);
	sprite->addKeyframe(1, glm::vec2(0.f, 0.f));
	sprite->addKeyframe(1, glm::vec2(0.33f, 0.f));
	sprite->addKeyframe(1, glm::vec2(0.f, 0.25f));
	sprite->addKeyframe(1, glm::vec2(0.33f, 0.25f));
	sprite->addKeyframe(1, glm::vec2(0.f, 0.5f));
	sprite->addKeyframe(1, glm::vec2(0.33f, 0.5f));
	sprite->addKeyframe(1, glm::vec2(0.f, 0.75f));
	sprite->addKeyframe(1, glm::vec2(0.33f, 0.75f));

	sprite->setAnimationSpeed(2, 8);
	sprite->addKeyframe(2, glm::vec2(0.33f, 0.75f));


	sprite->changeAnimation(0);
	tileMapDispl = tileMapPos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + posEnemic.x), float(tileMapDispl.y + posEnemic.y)));

}

void Enemic::update(int deltaTime) {
	if (sprite->animation() != 2 && sprite->animation() != 1) {
		if (moveLeft) {
			posEnemic.x -= 1;
			if (posEnemic.x == 180) moveLeft = false;
		}
		else {
			posEnemic.x += 1;
			if (posEnemic.x == 640) moveLeft = true;
		}
		if (player->collisionright(posEnemic, glm::ivec2(32, 32))) {
			player->setDead();
		}
		else if (player->collisionleft(posEnemic, glm::ivec2(32, 32))) {
			player->setDead();
		}
		else if (player->collisiondownEnemic(posEnemic, glm::ivec2(32, 32))) {
			engine = createIrrKlangDevice();
			engine->play2D("sounds/MortEnemic.mp3", false);
			sprite->changeAnimation(1);
			player->setbJumping();
		}
	}
	if (sprite->animation() == 1 && sprite->getFrame() == 7) sprite->changeAnimation(2);
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + posEnemic.x), float(tileMapDispl.y + posEnemic.y)));
	sprite->update(deltaTime);

}

void Enemic::setPosition(const glm::vec2 &pos)
{
	posEnemic = pos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + posEnemic.x), float(tileMapDispl.y + posEnemic.y)));
}

void Enemic::render()
{
	sprite->render();
}

void Enemic::setPlayer(Player *p)
{
	player = p;
}

