#ifndef ENEMYHANDLER_H
#define ENEMYHANDLER_H

#include "Enemy.h"
#include "Scene.h"
#include "UpdateEachFrame.h"
#include <vector>

namespace ge {
	class EnemyHandler : public UpdateEachFrame
	{
	public:
		EnemyHandler(Scene* scene);
		void Add(Enemy* enemy);
	private:		
		void RemoveEnemy(Enemy* enemy);
		void RemoveDeadEnemies();
		void Update(float delta);
		Scene* scene = nullptr;
		std::vector<Enemy*> enemies;
	};
}

#endif ENEMYHANDLER_H