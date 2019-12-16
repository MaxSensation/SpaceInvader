#include "EnemyHandler.h"

namespace ge {
	EnemyHandler::EnemyHandler(Scene* scene) :
	scene(scene)
	{
		generateFirePoints();		
	}

	void EnemyHandler::add(Enemy* enemy)
	{
		enemies.push_back(enemy);
		scene->addSprite(enemy);
	}

	void EnemyHandler::addEnemySet(std::vector<int> enemySet)
	{
		enemyWidth = 24;
		enemySpeed = 0.05f;
		int row = 1;
		int prevEnemiesPerRow = enemySet[0];
		int offset = 0;
		int enemySpacing = -1;
		int x = 0;
		int y = 0;
		int xMax = -1;

		for (int enemyPerRow : enemySet) {
			for (int  i = 1;  i <= enemyPerRow;  i++)
			{								
				//std::cout << "Row: " << row << " EnemiesPerRow: " << enemyPerRow << " current enemy: " << i << std::endl;
				if (enemySpacing < 0)
				{
					enemySpacing = (400 / enemyPerRow) - (enemyWidth / 2);					
					offset = (enemySpacing * -1);
				}				

				if (prevEnemiesPerRow - enemyPerRow > 0)
				{
					x = enemySpacing * (i + ((prevEnemiesPerRow - enemyPerRow) / 2));
				}
				else
				{
					x = enemySpacing * i;
				}
				x += offset;

				y = 200 / enemySet.size() * row;				
				add(new Enemy(x, y, enemySpeed));
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
		scene->removeSprite(enemy);
		auto it = enemies.begin();
		while (it != enemies.end())
		{
			if (*it == enemy) {
				it = enemies.erase(it);
			}
			else {
				++it;
			}
		}
		enemy = nullptr;
		delete(enemy);
		updateSpeed();
	}

	void EnemyHandler::updateSpeed() {
		enemySpeed *= 1.075;
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
		for (Enemy* enemy : enemies) {
			if (enemy->isDead())
			{
				removeEnemy(enemy);
			}
		}
	}

	void EnemyHandler::checkEnemyWalls(){
		if (getEnemyMaxPosX() >= 600 - enemyWidth && bMovingRight)
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

	int EnemyHandler::getEnemyMaxPosX(){
		if (enemies.size() > 0)
		{
			int maxPosX = -1;
			for (Enemy* enemy : enemies) {
				enemy->getPosition()->x > maxPosX ? maxPosX = enemy->getPosition()->x : NULL;
			}
			return maxPosX;
		}
		return -1;
	};

	int EnemyHandler::getEnemyMinPosX() {
		if (enemies.size() > 0)
		{
			int minPosX = 600;
			for (Enemy* enemy : enemies) {
				enemy->getPosition()->x < minPosX ? minPosX = enemy->getPosition()->x : NULL;
			}
			return minPosX;
		}
		return -1;
	};

	int EnemyHandler::getEnemyMaxPosY() {
		if (enemies.size() > 0)
		{
			int maxPosY = 0;
			for (Enemy* enemy : enemies) {
				enemy->getPosition()->y > maxPosY ? maxPosY = enemy->getPosition()->y : NULL;
			}
			return maxPosY;
		}
		return -1;
	};

	bool EnemyHandler::enemyWon() {
		for (Enemy *enemy : enemies)
		{
			if (getEnemyMaxPosY() >= 600 - enemyWidth)
			{
				return true;
			}
		}
		return false;
	}

	void EnemyHandler::fire() {
		int maxPosY = getEnemyMaxPosY();		
		for (Enemy *enemy : enemies)
		{			
			if (enemy->canFire())
			{		
				if (enemy->getPosition()->y == maxPosY)
				{				
					auto firePoint = firePoints.begin();
					while (firePoint != firePoints.end())
					{
						if (*firePoint == (int)enemy->getPosition()->x) {												
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
		for (int i = 600/10; i < 600; i += 600/10)
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
}