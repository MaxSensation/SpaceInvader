#ifndef LEVELHANDLER_H
#define LEVELHANDLER_H

#include "Level.h"
#include <vector>
#include "EnemyHandler.h"

namespace ge {
	class LevelHandler
	{
		public:
			LevelHandler(EnemyHandler* enemyHandler) :
				enemyHandler(enemyHandler)				
			{
				nextLevel = gameengine.getSoundManager()->createSound("nextLevel.wav");
			};
			~LevelHandler();
			void addLevel(std::vector<int> enemySet);
			void NextLevel();
			bool hasNextLevel();
			int getCurrentLevelnr();
			void loadLevel(Level* level);
			void loadLevel(int level);
		private:
			std::vector<Level*> levels;
			EnemyHandler* enemyHandler;
			int currentLevel = 1;
			Sound* nextLevel = nullptr;
	};
}

#endif