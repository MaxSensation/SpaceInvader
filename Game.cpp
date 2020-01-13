#include "Game.h"
namespace ge{

	void Game::createHandlers()
	{		
		Scene::getInstance()->addUpdatableObject(LaserHandler::getInstance());
		Scene::getInstance()->addUpdatableObject(EnemyHandler::getInstance());
		Scene::getInstance()->addUpdatableObject(this);
	}

	void Game::createGrahpics()
	{
		player = Player::getInstance(GameEngine::getInstance()->getScreenWidth(), GameEngine::getInstance()->getScreenHeight(), &bGameOver);
		textScore = Text::getInstance(10, 10, 100, 100, "arial.ttf", 30, "Score: ");
		score = Text::getInstance(110, 10, 100, 100, "arial.ttf", 30, "0");
		Scene::getInstance()->addText(textScore);
		Scene::getInstance()->addText(score);


		textLevel = Text::getInstance(SCREENWITDH - 150, 10, 100, 100, "arial.ttf", 30, "Level: ");
		level = Text::getInstance(SCREENWITDH - 50, 10, 100, 100, "arial.ttf", 30, "0");
		Scene::getInstance()->addText(textLevel);
		Scene::getInstance()->addText(level);

		winningText = Text::getInstance(SCREENWITDH / 2 - 100, SCREENHEIGHT / 2 - 100, 100, 100, "arial.ttf", 50, "You Won!");
		gameOverText = Text::getInstance(SCREENWITDH / 2 - 125, SCREENHEIGHT / 2 - 100, 100, 100, "arial.ttf", 50, "GameOver!");
	}

	void Game::createSound()
	{
		winSound = GameEngine::getInstance()->getSoundManager()->createSound("win.wav");
		gameoverSound = GameEngine::getInstance()->getSoundManager()->createSound("gameover.wav");
		GameEngine::getInstance()->getSoundManager()->setMusic("music.wav");
		GameEngine::getInstance()->getSoundManager()->playMusic();
	}

	void Game::createLevels()
	{
		LevelHandler::getInstance()->addLevel({ 1,3,5 });
		LevelHandler::getInstance()->addLevel({ 5,3,1 });
		LevelHandler::getInstance()->addLevel({ 5,3,3,5 });
		LevelHandler::getInstance()->addLevel({ 6,6,6,6,6 });
		LevelHandler::getInstance()->addLevel({ 7,7,7,7,7,7 });
		LevelHandler::getInstance()->addLevel({ 8,8,8,8,8,8 });
		LevelHandler::getInstance()->addLevel({ 9,9,9,9,9,9 });
		LevelHandler::getInstance()->addLevel({ 9,9,9,9,9,9 });
		LevelHandler::getInstance()->addLevel({ 10,10,10,10,10,10 });
		LevelHandler::getInstance()->loadLevel(1);
	}

	Game::Game():
		SCREENWITDH(600),
		SCREENHEIGHT(600),
		fpsCap(60)
	{	
		GameEngine::getInstance()->init("SpaceInvader", SCREENWITDH, SCREENHEIGHT, fpsCap);
		createHandlers();
		createGrahpics();
		createSound();
		createLevels();
		std::cout << "Game Initiliezed" << "\n" << "FPS cap: " << fpsCap << "\n" << "ScreenWitdh: " << SCREENWITDH << "\n" << "ScreenHeight: " << SCREENHEIGHT << "\n" << std::endl;
		GameEngine::getInstance()->launch();
	}

	void Game::playerWon() {		
		std::cout << "--------------- Player Won!!! ---------------" << std::endl;
		Scene::getInstance()->addText(winningText);
		winSound->play();
	}

	void Game::nextLevel() {
		LaserHandler::getInstance()->removeAllLaserBeams();
		LevelHandler::getInstance()->NextLevel();
		std::cout << "--------------- Next Level!!! ---------------" << std::endl;	
	}

	void Game::gameOver() {
		std::cout << "--------------- GameOver!!! ---------------" << std::endl;
		Scene::getInstance()->addText(gameOverText);
		gameoverSound->play();
	}

	void Game::checkGameStatus() {		
		if (EnemyHandler::getInstance()->allDead() && LevelHandler::getInstance()->hasNextLevel())
		{
			nextLevel();
		}

		if (EnemyHandler::getInstance()->allDead() && !bWon)
		{				
			playerWon();
			bWon = true;		
		}
		if (EnemyHandler::getInstance()->enemyWon())
		{
			player->die();
		}
		if (player->isDead() && !bGameOver)
		{
			delete(player);
			gameOver();
			bGameOver = true;
		}
	}

	void Game::calcScore() {
		int scorePerEnemy = 10;
		int newScore = (EnemyHandler::getInstance()->getTotalCreatedEnemies() - EnemyHandler::getInstance()->getTotalAliveEnemies()) * scorePerEnemy;
		score->setText(std::to_string(newScore));
	}

	void Game::updateLevelText() {
		level->setText(std::to_string(LevelHandler::getInstance()->getCurrentLevelnr()));
	}

	void Game::update(float delta)
	{	
		checkGameStatus();
		updateLevelText();
		calcScore();
	}

	Game::~Game()
	{	
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
		LevelHandler::deleteInstance();
		LaserHandler::deleteInstance();
		EnemyHandler::deleteInstance();
		GameEngine::deleteInstance();
	}

	Game* Game::getInstance()
	{
		return new Game();
	}
}
int main(int argc, char** argv)
{	
	ge::Game* game = ge::Game::getInstance();
	delete(game);
	return 0;
}
