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
	
	textScore = new Text(10, 10, 100, 100, "arial.ttf", 30, "Score: ");
	score = new Text(110, 10, 100, 100, "arial.ttf", 30, "0");
	scene->addText(textScore);
	scene->addText(score);
	
	winningText = new Text(SCREENWITDH/2 - 100, SCREENHEIGHT/2 - 100, 100, 100, "arial.ttf", 50, "You Won!");
	gameOverText = new Text(SCREENWITDH / 2 - 125, SCREENHEIGHT / 2 - 100, 100, 100, "arial.ttf", 50, "GameOver!");

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
	scene->addText(winningText);
}


void Game::gameOver() {
	std::cout << "--------------- GameOver!!! ---------------" << std::endl;
	scene->addText(gameOverText);
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

void Game::calcScore() {
	int scorePerEnemy = 10;
	int newScore = (enemyHandler->getTotalCreatedEnemies() - enemyHandler->getTotalAliveEnemies()) * scorePerEnemy;
	score->setText(std::to_string(newScore));
}

void Game::update(float delta)
{
	calcScore();
	checkGameStatus();
}

int main(int argc, char** argv)
{
	Game game;
	return 0;
}