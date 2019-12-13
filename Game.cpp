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
	scene->AddUpdatableObject(&laserHandler);

	player = new Player(&SCREENWITDH, &SCREENHEIGHT, scene);
	scene->AddSprite(player);
	
	enemyHandler = new EnemyHandler(scene);	
	std::vector<int> enemySet = { 7,5,3,1 };
	enemyHandler->AddEnemySet(enemySet);
	scene->AddUpdatableObject(enemyHandler);
			
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