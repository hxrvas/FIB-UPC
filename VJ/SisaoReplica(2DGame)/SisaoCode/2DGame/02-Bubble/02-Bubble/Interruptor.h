#ifndef _INTERRUPTOR_INCLUDE
#define _INTERRUPTOR_INCLUDE

#include "Sprite.h"
#include <irrKlang.h>

#if defined(WIN32)
#include <conio.h>
#else
#include "../common/conio.h"
#endif

using namespace irrklang;


class Interruptor
{
public:
	void init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram, string& file);
	void update(int deltaTime);
	void render();
	void apretar();

private:
	Texture spritesheet;
	Sprite* sprite;
	ISoundEngine* engine;
	glm::ivec2 tileMapDispl;
	bool apretat, aux_apretat;
};

#endif // _INTERRUPTOR_INCLUDE