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
		static EnemyHandler* getInstance();
		static void deleteInstance();		
		void addEnemySet(std::vector<int> enemySet);
		bool allDead();	
		bool enemyWon();	
		int getTotalAliveEnemies();
		int getTotalCreatedEnemies();		
	private:		
		static EnemyHandler* instance;
		~EnemyHandler();
		EnemyHandler();
		void generateFirePoints();
		void fire();
		void add(float posX, float posY, float enemySpeed);
		void move();
		void moveDown();
		void removeEnemy(Enemy* enemy);
		void updateSpeed();
		void removeDeadEnemies();
		void checkEnemyWalls();
		void resetEnemiesFireState();
		float getEnemyMaxPosX();
		float getEnemyMinPosX();
		float getEnemyMaxPosY();
		void update(float delta);
		bool bMovingRight = true;
		int enemyWidth;
		int totalCreatedEnemies;
		float enemySpeed;
		std::vector<int> firePoints;
		std::vector<Enemy*> enemies;
		Sound* enemyDestroydSound = nullptr;
	};
}

#endif ENEMYHANDLER_H