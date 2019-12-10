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
	}

	void EnemyHandler::RemoveDeadEnemies()
	{
		auto it = enemies.begin();
		while (it != enemies.end())
		{
			if ((*it)->IsDead()) {
				RemoveEnemy(*it);				
			}
			++it;
		}
	}
	void EnemyHandler::Update(float delta)
	{
		RemoveDeadEnemies();
	}
}