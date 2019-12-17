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
	Level 
		level1({ 1,3,5 }), 
		level2({ 5,3,1 }),
		level3({ 5,3,3,5 }),
		level4({ 6,6,6,6,6 }),
		level5({ 7,7,7,7,7,7 }),
		level6({ 8,8,8,8,8,8 }),
		level7({ 9,9,9,9,9,9 }),
		level8({ 10,10,10,10,10,10 })
	;
	
	levelHandler->addLevel(&level1);
	levelHandler->addLevel(&level2);
	levelHandler->addLevel(&level3);
	levelHandler->addLevel(&level4);
	levelHandler->addLevel(&level5);
	levelHandler->addLevel(&level5);
	levelHandler->addLevel(&level6);
	levelHandler->addLevel(&level7);
	levelHandler->addLevel(&level8);
	levelHandler->loadLevel(1);

	scene->addUpdatableObject(enemyHandler);
	scene->addUpdatableObject(this);
	gameengine.setScene(scene);	
	std::cout << "Game Initiliezed" << "\n" << "FPS cap: " << fpsCap << "\n" << "ScreenWitdh: " << SCREENWITDH << "\n" << "ScreenHeight: " << SCREENHEIGHT << "\n" << std::endl;
	gameengine.launch();
}

void Game::playerWon() {		
	std::cout << "--------------- Player Won!!! ---------------" << std::endl;
	scene->addText(winningText);
}

void Game::nextLevel() {
	levelHandler->NextLevel();
	std::cout << "--------------- Next Level!!! ---------------" << std::endl;	
}

void Game::gameOver() {
	std::cout << "--------------- GameOver!!! ---------------" << std::endl;
	scene->addText(gameOverText);
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
	player = nullptr;
	delete(player);
	textScore = nullptr;
	delete(textScore);
	score = nullptr;
	delete(score);
	winningText = nullptr;
	delete(winningText);
	gameOverText = nullptr;
	delete(gameOverText);
	textLevel = nullptr;
	delete(textLevel);
	level = nullptr;
	delete(level);
	enemy = nullptr;
	delete(enemy);
	scene = nullptr;
	delete(scene);
	enemyHandler = nullptr;
	delete(enemyHandler);
	levelHandler = nullptr;
	delete(levelHandler);
}

int main(int argc, char** argv)
{	
	Game game;
	return 0;
}