#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>
#include <irrKlang.h>
#include "Game.h"

#if defined(WIN32)
#include <conio.h>
#else
#include "../common/conio.h"
#endif

using namespace irrklang;

#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll


void Game::init()
{
	godMode = false;
	activeScene = -1;
	bPlay = true;
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
	menu.init();
}

bool Game::update(int deltaTime)
{



		if (activeScene == 0 && tuto.changeScene()) {

			scene.init();
			activeScene = 1;
		}

		if (activeScene == 1 && scene.changeScene()) {

			scene2.init();
			activeScene = 2;
		}


		if (activeScene == 2 && scene2.changeScene()) {
			scene3.init();
			activeScene = 3;
		}


		if (activeScene == 3 && scene3.changeScene()) {
			scene4.init();
			activeScene = 4;
		}
		if (activeScene == 4 && scene4.changeScene()) {
			scene5.init();
			activeScene = 5;
		}
		if (activeScene == 5 && scene5.changeScene()) {
			credits.init();
			activeScene = 6;
		}

		if (activeScene == 6 && credits.changeScene()) {
			menu.init();
			activeScene = -1;
		}

		switch (activeScene)
		{
		case 6:
			credits.update(deltaTime);
			break;
		case 5:
			scene5.setGodMode(godMode);
			scene5.update(deltaTime);
			break;
		case 4:
			scene4.setGodMode(godMode);
			scene4.update(deltaTime);
			break;
		case 3:
			scene3.setGodMode(godMode);
			scene3.update(deltaTime);
			break;
		case 2:
			scene2.setGodMode(godMode);
			scene2.update(deltaTime);
			break;
		case 1:
			scene.setGodMode(godMode);
			scene.update(deltaTime);
			break;
		case 0:
			tuto.setGodMode(godMode);
			tuto.update(deltaTime);
			break;
		default:
			int s = menu.update(deltaTime);
			if (s == 0)
			{
				tuto.init();
				activeScene = 0;
			}
			if (s == 1)
			{
				scene.init();
				activeScene = 1;
			}
			else if (s == 2)
			{
				scene2.init();
				activeScene = 2;
			}
			else if (s == 3)
			{
				scene3.init();
				activeScene = 3;
			}
			else if (s == 4)
			{
				scene4.init();
				activeScene = 4;
			}
			else if (s == 5)
			{
				scene5.init();
				activeScene = 5;
			}
			break;
		}



	return bPlay;
}

void Game::render()
{

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		switch (activeScene)
		{
		case 6:
			credits.render();
			break;
		case 5:
			scene5.render();
			break;
		case 4:
			scene4.render();
			break;
		case 3:
			scene3.render();
			break;
		case 2:
			scene2.render();
			break;
		case 1:
			scene.render();
			break;
		case 0:
			tuto.render();
			break;
		default:
			menu.render();
			break;
		}

}

void Game::keyPressed(int key)
{

		if (key == 49)
		{
			switch (activeScene)
			{
			case 5:
				scene5.deleteEngine();
				break;
			case 4:
				scene4.deleteEngine();
				break;
			case 3:
				scene3.deleteEngine();
				break;
			case 2:
				scene2.deleteEngine();
				break;
			case 1:
				scene.deleteEngine();
				break;
			case 0:
				tuto.deleteEngine();
				break;
			default:
				menu.deleteEngine();
				break;
			}

			scene.init();
			activeScene = 1;
		}
		if (key == 50)
		{
			switch (activeScene)
			{
			case 5:
				scene5.deleteEngine();
				break;
			case 4:
				scene4.deleteEngine();
				break;
			case 3:
				scene3.deleteEngine();
				break;
			case 2:
				scene2.deleteEngine();
				break;
			case 1:
				scene.deleteEngine();
				break;
			case 0:
				tuto.deleteEngine();
				break;
			default:
				menu.deleteEngine();
				break;
			}
			scene2.init();
			activeScene = 2;
		}
		if (key == 51)
		{
			switch (activeScene)
			{
			case 5:
				scene5.deleteEngine();
				break;
			case 4:
				scene4.deleteEngine();
				break;
			case 3:
				scene3.deleteEngine();
				break;
			case 2:
				scene2.deleteEngine();
				break;
			case 1:
				scene.deleteEngine();
				break;
			case 0:
				tuto.deleteEngine();
				break;
			default:
				menu.deleteEngine();
				break;
			}
			scene3.init();
			activeScene = 3;
		}
		if (key == 52)
		{
			switch (activeScene)
			{
			case 5:
				scene5.deleteEngine();
				break;
			case 4:
				scene4.deleteEngine();
				break;
			case 3:
				scene3.deleteEngine();
				break;
			case 2:
				scene2.deleteEngine();
				break;
			case 1:
				scene.deleteEngine();
				break;
			case 0:
				tuto.deleteEngine();
				break;
			default:
				menu.deleteEngine();
				break;
			}
			scene4.init();
			activeScene = 4;
		}
		if (key == 53)
		{
			switch (activeScene)
			{
			case 5:
				scene5.deleteEngine();
				break;
			case 4:
				scene4.deleteEngine();
				break;
			case 3:
				scene3.deleteEngine();
				break;
			case 2:
				scene2.deleteEngine();
				break;
			case 1:
				scene.deleteEngine();
				break;
			case 0:
				tuto.deleteEngine();
				break;
			default:
				menu.deleteEngine();
				break;
			}
			scene5.init();
			activeScene = 5;
		}

		if (key == 48)
		{
			switch (activeScene)
			{
			case 5:
				scene5.deleteEngine();
				break;
			case 4:
				scene4.deleteEngine();
				break;
			case 3:
				scene3.deleteEngine();
				break;
			case 2:
				scene2.deleteEngine();
				break;
			case 1:
				scene.deleteEngine();
				break;
			case 0:
				tuto.deleteEngine();
				break;
			default:
				menu.deleteEngine();
				break;
			}
			tuto.init();
			activeScene = 0;
		}

		if (key == int('c'))
		{
			switch (activeScene)
			{
			case 5:
				scene5.deleteEngine();
				break;
			case 4:
				scene4.deleteEngine();
				break;
			case 3:
				scene3.deleteEngine();
				break;
			case 2:
				scene2.deleteEngine();
				break;
			case 1:
				scene.deleteEngine();
				break;
			case 0:
				tuto.deleteEngine();
				break;
			default:
				menu.deleteEngine();
				break;
			}
			credits.init();
			activeScene = 6;
		}


		if (key == int('m'))
		{
			switch (activeScene)
			{
			case 6: 
				credits.deleteEngine();
				break;
			case 5:
				scene5.deleteEngine();
				break;
			case 4:
				scene4.deleteEngine();
				break;
			case 3:
				scene3.deleteEngine();
				break;
			case 2:
				scene2.deleteEngine();
				break;
			case 1:
				scene.deleteEngine();
				break;
			case 0:
				tuto.deleteEngine();
				break;
			default:
				menu.deleteEngine();
				break;
			}
			menu.init();
			activeScene = -1;
		}

		if (key == 27)
		{
			bPlay = false;
		}

		if (key == int('7'))
		{
			godMode = !godMode;
			cout << godMode << endl;
		}

		keys[key] = true;

}

void Game::keyReleased(int key)
{
	keys[key] = false;
}

void Game::specialKeyPressed(int key)
{
	specialKeys[key] = true;
}

void Game::specialKeyReleased(int key)
{
	specialKeys[key] = false;
}

void Game::mouseMove(int x, int y)
{
}

void Game::mousePress(int button)
{
}

void Game::mouseRelease(int button)
{
}

bool Game::getKey(int key) const
{
	return keys[key];
}

bool Game::getSpecialKey(int key) const
{
	return specialKeys[key];
}





