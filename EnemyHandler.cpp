#include "EnemyHandler.h"

namespace ge {
	EnemyHandler::EnemyHandler(Scene* scene) :
	scene(scene)
	{

	}

	void EnemyHandler::add(Enemy* enemy)
	{
		enemies.push_back(enemy);
		scene->addSprite(enemy);
	}

	void EnemyHandler::addEnemySet(std::vector<int> enemySet)
	{
		int enemyWidth = 26;
		int row = 1;
		int prevEnemiesPerRow = enemySet[0];
		int offset = 0;
		int enemySpacing = -1;
		int x = 0;
		int y = 0;

		for (int enemyPerRow : enemySet) {
			for (int  i = 1;  i <= enemyPerRow;  i++)
			{								
				std::cout << "Row: " << row << " EnemiesPerRow: " << enemyPerRow << " current enemy: " << i << std::endl;
				if (enemySpacing < 0)
				{
					enemySpacing = (600 / enemyPerRow) - (enemyWidth / 2);
				}				

				if (prevEnemiesPerRow - enemyPerRow > 0)
				{
					x = enemySpacing * (i + ((prevEnemiesPerRow - enemyPerRow) / 2));
				}
				else
				{
					x = enemySpacing * i;
				}
				
				y = 200 / enemySet.size() * row;
				add(new Enemy(x, y));
			}
			row++;
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
	void EnemyHandler::update(float delta)
	{
		removeDeadEnemies();
	}
}