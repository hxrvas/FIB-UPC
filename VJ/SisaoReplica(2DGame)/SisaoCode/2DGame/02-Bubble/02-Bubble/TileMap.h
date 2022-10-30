#ifndef _TILE_MAP_INCLUDE
#define _TILE_MAP_INCLUDE


#include <glm/glm.hpp>
#include "Texture.h"
#include "ShaderProgram.h"


// Class Tilemap is capable of loading a tile map from a text file in a very
// simple format (see level01.txt for an example). With this information
// it builds a single VBO that contains all tiles. As a result the render
// method draws the whole map independently of what is visible.


class TileMap
{

public:
	// Tile maps can only be created inside an OpenGL context
	static TileMap *createTileMap(const string &levelFile, const glm::vec2 &minCoords, ShaderProgram &program);

	TileMap(const string &levelFile, const glm::vec2 &minCoords, ShaderProgram &program);
	~TileMap();

	void render() const;
	void free();
	
	int getTileSize() const { return tileSize; }

	bool collisionMoveLeft(const glm::ivec2 &pos, const glm::ivec2 &size) const;
	bool collisionMoveRight(const glm::ivec2 &pos, const glm::ivec2 &size) const;
	bool collisionMoveUp(const glm::ivec2& pos, const glm::ivec2& size, int* posY) const;
	bool collisionMoveDown(const glm::ivec2 &pos, const glm::ivec2 &size, int *posY) const;

	int changeStateLeft(const glm::ivec2 &pos, const glm::ivec2 &size) const;
	int changeStateRight(const glm::ivec2 &pos, const glm::ivec2 &size) const;
	int changeStateUp(const glm::ivec2 &pos, const glm::ivec2 &size, int *posY) const;
	int changeStateDown(const glm::ivec2 &pos, const glm::ivec2 &size, int *posY) const;

	int changeStateLeft2(const glm::ivec2 &pos, const glm::ivec2 &size) const;
	int changeStateRight2(const glm::ivec2 &pos, const glm::ivec2 &size) const;
	int changeStateUp2(const glm::ivec2 &pos, const glm::ivec2 &size, int *posY) const;
	int changeStateDown2(const glm::ivec2 &pos, const glm::ivec2 &size, int *posY) const;
	
	void setNoBloc();
private:
	bool loadLevel(const string &levelFile);
	void prepareArrays(const glm::vec2 &minCoords, ShaderProgram &program);

private:
	ShaderProgram *shaderProgram;
	GLuint vao;
	GLuint vbo;
	GLint posLocation, texCoordLocation;
	glm::ivec2 position, mapSize, tilesheetSize;
	int tileSize, blockSize;
	Texture tilesheet;
	glm::vec2 tileTexSize;
	int *map;
	int nTiles;
	bool noBloc;

};


#endif // _TILE_MAP_INCLUDE


