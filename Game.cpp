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
	std::vector<int> enemySet = { 8,8,8,8 };
	enemyHandler->addEnemySet(enemySet);
	scene->addUpdatableObject(enemyHandler);
	scene->addUpdatableObject(this);
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

void Game::playerWon() {
	std::cout << "--------------- Player Won!!! ---------------" << std::endl;
}


void Game::gameOver() {
	std::cout << "--------------- GameOver!!! ---------------" << std::endl;
}

void Game::checkGameStatus() {	
	if (enemyHandler->enemyWon())
	{
		player->die();
	}
	if (enemyHandler->allDead() && !bWon)
	{
		playerWon();
		bWon = true;
	}
	if (player->isDead() && !bGameOver)
	{
		scene->removeSprite(player);
		gameOver();
		bGameOver = true;
	}
}

void Game::update(float delta)
{
	checkGameStatus();
}

int main(int argc, char** argv)
{
	Game game;
	return 0;
}