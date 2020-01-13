#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include "Game.h"
using namespace ge;

Game::Game():		
	SCREENWITDH(600),
	SCREENHEIGHT(600),
	fpsCap(60)
{	
	gameengine.init("SpaceInvader", SCREENWITDH, SCREENHEIGHT, fpsCap);	
	scene = gameengine.getScene();
	laserHandler.init(scene);
	scene->addUpdatableObject(&laserHandler);

	winSound = gameengine.getSoundManager()->createSound("win.wav");
	gameoverSound = gameengine.getSoundManager()->createSound("gameover.wav");
	
	player = new Player(&SCREENWITDH, &SCREENHEIGHT, scene, &bGameOver);
	scene->addSprite(player);
	
	textScore = new Text(10, 10, 100, 100, "arial.ttf", 30, "Score: ");
	score = new Text(110, 10, 100, 100, "arial.ttf", 30, "0");
	scene->addText(textScore);
	scene->addText(score);


	textLevel = new Text(SCREENWITDH - 150, 10, 100, 100, "arial.ttf", 30, "Level: ");
	level = new Text(SCREENWITDH - 50, 10, 100, 100, "arial.ttf", 30, "0");
	scene->addText(textLevel);
	scene->addText(level);
	
	winningText = new Text(SCREENWITDH/2 - 100, SCREENHEIGHT/2 - 100, 100, 100, "arial.ttf", 50, "You Won!");
	gameOverText = new Text(SCREENWITDH / 2 - 125, SCREENHEIGHT / 2 - 100, 100, 100, "arial.ttf", 50, "GameOver!");

	enemyHandler = new EnemyHandler(scene);		
	
	levelHandler = new LevelHandler(enemyHandler);

	levelHandler->addLevel({ 1,3,5 });
	levelHandler->addLevel({ 5,3,1 });
	levelHandler->addLevel({ 5,3,3,5 });
	levelHandler->addLevel({ 6,6,6,6,6 });
	levelHandler->addLevel({ 7,7,7,7,7,7 });
	levelHandler->addLevel({ 8,8,8,8,8,8 });
	levelHandler->addLevel({ 9,9,9,9,9,9 });
	levelHandler->addLevel({ 9,9,9,9,9,9 });
	levelHandler->addLevel({ 10,10,10,10,10,10 });
	levelHandler->loadLevel(1);

	gameengine.getSoundManager()->setMusic("music.wav");
	gameengine.getSoundManager()->playMusic();
	
	scene->addUpdatableObject(enemyHandler);
	scene->addUpdatableObject(this);	
	std::cout << "Game Initiliezed" << "\n" << "FPS cap: " << fpsCap << "\n" << "ScreenWitdh: " << SCREENWITDH << "\n" << "ScreenHeight: " << SCREENHEIGHT << "\n" << std::endl;
	gameengine.launch();
}

void Game::playerWon() {		
	std::cout << "--------------- Player Won!!! ---------------" << std::endl;
	scene->addText(winningText);
	winSound->play();
}

void Game::nextLevel() {
	laserHandler.removeAllLaserBeams();
	levelHandler->NextLevel();
	std::cout << "--------------- Next Level!!! ---------------" << std::endl;	
}

void Game::gameOver() {
	std::cout << "--------------- GameOver!!! ---------------" << std::endl;
	scene->addText(gameOverText);
	gameoverSound->play();
}

void Game::checkGameStatus() {		
	if (enemyHandler->allDead() && levelHandler->hasNextLevel())
	{
		nextLevel();
	}

	if (enemyHandler->allDead() && !bWon)
	{				
		playerWon();
		bWon = true;		
	}
	if (enemyHandler->enemyWon())
	{
		player->die();
	}
	if (player->isDead() && !bGameOver)
	{
		player->removeSprite();
		gameOver();
		bGameOver = true;
	}
}

void Game::calcScore() {
	int scorePerEnemy = 10;
	int newScore = (enemyHandler->getTotalCreatedEnemies() - enemyHandler->getTotalAliveEnemies()) * scorePerEnemy;
	score->setText(std::to_string(newScore));
}

void Game::updateLevelText() {
	level->setText(std::to_string(levelHandler->getCurrentLevelnr()));
}

void Game::update(float delta)
{	
	checkGameStatus();
	updateLevelText();
	calcScore();
}

Game::~Game()
{	
	if (!bGameOver)
	{		
		player->removeSprite();		
	}	
	delete(winSound);
	delete(gameoverSound);
	if (!player)
	{
		delete(player);
	}	
	delete(textScore);	
	delete(score);
	delete(winningText);	
	delete(gameOverText);	
	delete(textLevel);		
	delete(level);
	delete(enemyHandler);
	delete(levelHandler);	
	scene = nullptr;
	delete(scene);
}

int main(int argc, char** argv)
{	
	//_CrtSetDbgFlag(_CRTDBG_CHECK_ALWAYS_DF | _CRTDBG_LEAK_CHECK_DF);
	Game game;
	_CrtDumpMemoryLeaks();
	return 0;
}