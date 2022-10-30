#ifndef _GAME_INCLUDE
#define _GAME_INCLUDE

#include "SceneTutorial.h"
#include "Scene.h"
#include "Scene2.h"
#include "Scene3.h"
#include "Scene4.h"
#include "Scene5.h"
#include "SceneCredits.h"
#include "MenuInit.h"


#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 960


// Game is a singleton (a class with a single instance) that represents our whole application


class Game
{

public:
	Game() {}
	
	
	static Game &instance()
	{
		static Game G;
	
		return G;
	}
	
	void init();
	bool update(int deltaTime);
	void render();
	
	// Input callback methods
	void keyPressed(int key);
	void keyReleased(int key);
	void specialKeyPressed(int key);
	void specialKeyReleased(int key);
	void mouseMove(int x, int y);
	void mousePress(int button);
	void mouseRelease(int button);
	
	bool getKey(int key) const;
	bool getSpecialKey(int key) const;

private:
	bool godMode;
	int activeScene;
	bool bPlay;                       // Continue to play game?
	MenuInit menu;
	SceneTutorial tuto;
	Scene scene;                      // Scene to render
	Scene2 scene2;
	Scene3 scene3;
	Scene4 scene4;
	Scene5 scene5;
	SceneCredits credits;
	
	bool keys[256], specialKeys[256]; // Store key states so that 
	                                  // we can have access at any time

};


#endif // _GAME_INCLUDE


