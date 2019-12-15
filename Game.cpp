#include "Game.h"

using namespace ge;

Game::Game():	
	scene(new Scene),
	SCREENWITDH(600),
	SCREENHEIGHT(600),
	fpsCap(60)
{	
	gameengine.init("SpaceInvader", SCREENWITDH, SCREENHEIGHT, fpsCap);	
	
	laserHandler.init(scene);
	scene->addUpdatableObject(&laserHandler);

	player = new Player(&SCREENWITDH, &SCREENHEIGHT, scene);
	scene->addSprite(player);
	
	enemyHandler = new EnemyHandler(scene);	
	std::vector<int> enemySet = { 7,5,3,1 };
	enemyHandler->addEnemySet(enemySet);
	scene->addUpdatableObject(enemyHandler);
			
	gameengine.setScene(scene);	
	std::cout << "Game Initiliezed" << "\n" << "FPS cap: " << fpsCap << "\n" << "ScreenWitdh: " << SCREENWITDH << "\n" << "ScreenHeight: " << SCREENHEIGHT << "\n" << std::endl;
	gameengine.launch();
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