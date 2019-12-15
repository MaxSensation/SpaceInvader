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
		void add(Enemy* enemy);
		void addEnemySet(std::vector<int> enemySet);
	private:		
		void removeEnemy(Enemy* enemy);
		void removeDeadEnemies();
		void update(float delta);
		Scene* scene = nullptr;
		std::vector<Enemy*> enemies;
	};
}

#endif ENEMYHANDLER_H