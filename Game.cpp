#include "Game.h"

using namespace ge;

Game::Game():	
	scene(new Scene),
	SCREENWITDH(600),
	SCREENHEIGHT(600),
	fpsCap(60)
{	
	gameengine.Init("SpaceInvader", SCREENWITDH, SCREENHEIGHT, fpsCap);	
	laserHandler.Init(scene);	
	player = new Player(&SCREENWITDH, &SCREENHEIGHT, scene);
	enemy = new Enemy(SCREENWITDH/2, 100);
	std::cout << "Player Created" << std::endl;
	scene->AddUpdatableObject(&laserHandler);
	scene->AddSprite(player);
	scene->AddSprite(enemy);	
	gameengine.SetScene(scene);	
	std::cout << "Game Initiliezed" << "\n" << "FPS cap: " << fpsCap << "\n" << "ScreenWitdh: " << SCREENWITDH << "\n" << "ScreenHeight: " << SCREENHEIGHT << "\n" << std::endl;
	gameengine.Launch();
}

Game::~Game()
{	
	player = nullptr;
	delete(player);	
	scene = nullptr;
	delete(scene);
}

int main(int argc, char** argv)
{
	Game game;
	return 0;
}