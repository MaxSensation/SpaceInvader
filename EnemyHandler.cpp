#include "EnemyHandler.h"

namespace ge {
	EnemyHandler* EnemyHandler::instance = 0;

	EnemyHandler::EnemyHandler()
	{
		generateFirePoints();	
		totalCreatedEnemies = 0;
		enemyDestroydSound = GameEngine::getInstance()->getSoundManager()->createSound("explosion.wav");		
	}

	EnemyHandler* EnemyHandler::getInstance()
	{
		if (instance == 0)
		{
			instance = new EnemyHandler();
		}
		return instance;
	}

	void EnemyHandler::deleteInstance()
	{
		delete instance;
		instance = NULL;
	}

	EnemyHandler::~EnemyHandler()
	{		
		auto enemy = enemies.begin();
		while (enemy != enemies.end())
		{						
			delete(*enemy);
			enemy = enemies.erase(enemy);
		}		
	}

	void EnemyHandler::add(float posX, float posY, float enemySpeed)
	{		
		Enemy* e = Enemy::getInstance(posX, posY, enemySpeed);
		enemies.push_back(e);
	}

	void EnemyHandler::addEnemySet(std::vector<int> enemySet)
	{
		enemyWidth = 24;
		enemySpeed = 0.05f;
		int row = 1;
		float offset = 0.0f;
		float enemySpacing = -1.0f;
		float x = 0.0f;
		float y = 0.0f;
		float maxEnemiesPerRow = 0.0f;
		float middleOfRow = 0.0f;

		for (int enemyPerRow : enemySet) {
			enemyPerRow > maxEnemiesPerRow ? maxEnemiesPerRow = (float)enemyPerRow : NULL;
		}
		
		enemySpacing = (float) (*GameEngine::getInstance()->getScreenWidth() / maxEnemiesPerRow) - (enemyWidth / 2.0f);
		offset = (enemySpacing * -1.0f);

		float maxMiddleOfRow = (maxEnemiesPerRow + 0.5f) / 2.0f;

		for (int enemyPerRow : enemySet) {
			for (int  i = 1;  i <= enemyPerRow;  i++)
			{								
				middleOfRow = (enemyPerRow + 0.5f) / 2.0f;
				x = (float) enemySpacing * i + offset;
				x += (float)(maxMiddleOfRow - middleOfRow) * enemySpacing;
				y = 200.0f / enemySet.size() * row;
				add(x, y, enemySpeed);
				totalCreatedEnemies++;
			}
			row++;
		}		
	}

	void EnemyHandler::move()
	{
		if (bMovingRight)
		{
			for (Enemy* enemy : enemies) {
				enemy -> moveRight();
			}
		}
		else
		{
			for (Enemy* enemy : enemies) {
				enemy -> moveLeft();
			}
		}
	}


	void EnemyHandler::moveDown() {
		for (Enemy* enemy : enemies) {
			enemy->moveDown();
		}
	}


	void EnemyHandler::removeEnemy(Enemy* enemy) {							
		delete(enemy);
		enemyDestroydSound->play();
		std::cout << "Enemy Removed" << std::endl;
		updateSpeed();
	}

	void EnemyHandler::updateSpeed() {
		enemySpeed *= 1.075f;
		for (Enemy* enemy : enemies) {
			enemy->updateSpeed(enemySpeed);
		}
	}

	bool EnemyHandler::allDead() {
		if (enemies.size() == 0)
			return true;
		else
			return false;
	}

	void EnemyHandler::removeDeadEnemies()
	{
		auto enemy = enemies.begin();
		while (enemy != enemies.end())
		{
			if ((*enemy)->isDead())
			{				
				removeEnemy(*enemy);
				enemy = enemies.erase(enemy);				
			}
			else
			{
				enemy++;
			}			
		}
	}

	void EnemyHandler::checkEnemyWalls(){
		if (getEnemyMaxPosX() >= *GameEngine::getInstance()->getScreenWidth() - enemyWidth && bMovingRight)
		{
			moveDown();
			bMovingRight = false;
			generateFirePoints();
			resetEnemiesFireState();
		}
		if (getEnemyMinPosX() <= 0 && !bMovingRight)
		{
			moveDown();
			bMovingRight = true;
			generateFirePoints();
			resetEnemiesFireState();
		}		
	};

	void EnemyHandler::resetEnemiesFireState() {
		for (Enemy* enemy : enemies) {
			enemy->setFire(true);
		}
	}

	float EnemyHandler::getEnemyMaxPosX(){
		if (enemies.size() > 0)
		{
			float maxPosX = -1.0f;
			for (Enemy* enemy : enemies) {
				enemy->getPosition()->getX() > maxPosX ? maxPosX = enemy->getPosition()->getX() : NULL;
			}
			return maxPosX;
		}
		return -1.0f;
	};

	float EnemyHandler::getEnemyMinPosX() {
		if (enemies.size() > 0)
		{
			float minPosX = (float)*GameEngine::getInstance()->getScreenHeight();
			for (Enemy* enemy : enemies) {
				enemy->getPosition()->getX() < minPosX ? minPosX = enemy->getPosition()->getX() : NULL;
			}
			return minPosX;
		}
		return -1;
	};

	float EnemyHandler::getEnemyMaxPosY() {
		if (enemies.size() > 0)
		{
			float maxPosY = 0;
			for (Enemy* enemy : enemies) {
				enemy->getPosition()->getY() > maxPosY ? maxPosY = enemy->getPosition()->getY() : NULL;
			}
			return maxPosY;
		}
		return -1;
	};

	bool EnemyHandler::enemyWon() {
		for (Enemy *enemy : enemies)
		{
			if (getEnemyMaxPosY() >= *GameEngine::getInstance()->getScreenHeight() - enemyWidth)
			{
				return true;
			}
		}
		return false;
	}

	void EnemyHandler::fire() {
		float maxPosY = getEnemyMaxPosY();		
		for (Enemy *enemy : enemies)
		{			
			if (enemy->canFire())
			{		
				if (enemy->getPosition()->getY() == maxPosY)
				{				
					auto firePoint = firePoints.begin();
					while (firePoint != firePoints.end())
					{
						if (*firePoint == (int)enemy->getPosition()->getX()) {												
							if (rand() % 2 + 1 == 1)
							{
								enemy->fire();
								firePoint = firePoints.erase(firePoint);
							}
							else
							{
								enemy->setFire(false);
								++firePoint;
							}
						}
						else {
							++firePoint;
						}
					}		
				}
			}
		}
	}

	void EnemyHandler::generateFirePoints() {
		firePoints.clear();
		for (int i = *GameEngine::getInstance()->getScreenWidth()/10; i < *GameEngine::getInstance()->getScreenWidth(); i += *GameEngine::getInstance()->getScreenWidth()/10)
		{			
			firePoints.push_back(i);
		}		
	}

	void EnemyHandler::update(float delta)
	{		
		removeDeadEnemies();
		checkEnemyWalls();		
		fire();
		move();				
	}

	int EnemyHandler::getTotalAliveEnemies() {
		return enemies.size();
	}

	int EnemyHandler::getTotalCreatedEnemies() {
		return totalCreatedEnemies;
	}
}