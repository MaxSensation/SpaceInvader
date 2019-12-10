#include "EnemyHandler.h"

namespace ge {
	EnemyHandler::EnemyHandler(Scene* scene) :
	scene(scene)
	{

	}

	void EnemyHandler::Add(Enemy* enemy)
	{
		enemies.push_back(enemy);
	}

	void EnemyHandler::RemoveEnemy(Enemy* enemy) {
		scene->RemoveSprite(enemy);
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

	void EnemyHandler::RemoveDeadEnemies()
	{
		for (Enemy* enemy : enemies) {
			if (enemy->IsDead())
			{
				RemoveEnemy(enemy);
			}
		}
	}
	void EnemyHandler::Update(float delta)
	{
		RemoveDeadEnemies();
	}
}