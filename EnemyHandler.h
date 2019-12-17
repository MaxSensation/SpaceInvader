#ifndef ENEMYHANDLER_H
#define ENEMYHANDLER_H

#include "Enemy.h"
#include "Scene.h"
#include "UpdateEachFrame.h"
#include <vector>
#include "GameEngine.h"

namespace ge {
	class EnemyHandler : public UpdateEachFrame
	{
	public:
		EnemyHandler(Scene* scene);		
		~EnemyHandler();
		void addEnemySet(std::vector<int> enemySet);
		bool allDead();	
		bool enemyWon();	
		int getTotalAliveEnemies();
		int getTotalCreatedEnemies();
	private:		
		void generateFirePoints();
		void fire();
		void add(int posX, int posY, double enemySpeed);
		void move();
		void moveDown();
		void removeEnemy(Enemy* enemy);
		void updateSpeed();
		void removeDeadEnemies();
		void checkEnemyWalls();
		void resetEnemiesFireState();
		int getEnemyMaxPosX();
		int getEnemyMinPosX();
		int getEnemyMaxPosY();		
		void update(float delta);
		bool bMovingRight = true;
		int enemyWidth;
		int totalCreatedEnemies;
		float enemySpeed;
		std::vector<int> firePoints;
		Scene* scene = nullptr;
		std::vector<Enemy*> enemies;
	};
}

#endif ENEMYHANDLER_H