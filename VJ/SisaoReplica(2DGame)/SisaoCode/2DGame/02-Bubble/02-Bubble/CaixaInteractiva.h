#ifndef _CAIXAINTERACTIVA_INCLUDE
#define _CAIXAINTERACTIVA_INCLUDE

#include "Sprite.h"


class CaixaInteractiva
{
public:
	void init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram, string& file);
	void update(int deltaTime);
	void render();
	void seleccionar();
	void deseleccionar();
	bool isSeleccionat();

private:
	Texture spritesheet;
	Sprite* sprite;
	bool seleccionat;
	glm::ivec2 tileMapDispl;
};

#endif // _CAIXAINTERACTIVA_INCLUDE