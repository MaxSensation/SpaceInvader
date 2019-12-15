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
		bool allDead();	
	private:		
		void move();
		void moveDown();
		void removeEnemy(Enemy* enemy);
		void updateSpeed();
		void removeDeadEnemies();
		void checkEnemyWalls();
		int getEnemyMaxPosX();
		int getEnemyMinPosX();
		void update(float delta);
		bool bMovingRight = true;
		int enemyWidth;
		float enemySpeed;
		Scene* scene = nullptr;
		std::vector<Enemy*> enemies;
	};
}

#endif ENEMYHANDLER_H