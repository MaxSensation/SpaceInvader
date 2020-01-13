#ifndef LEVELHANDLER_H
#define LEVELHANDLER_H

#include "Level.h"
#include <vector>
#include "EnemyHandler.h"

namespace ge {
	class LevelHandler
	{
		public:
			static LevelHandler* getInstance();
			static void deleteInstance();
			~LevelHandler();
			void addLevel(std::vector<int> enemySet);
			void NextLevel();
			bool hasNextLevel();
			int getCurrentLevelnr();
			void loadLevel(Level* level);
			void loadLevel(int level);
		private:
			static LevelHandler* instance;
			LevelHandler()
			{
				nextLevel = GameEngine::getInstance()->getSoundManager()->createSound("nextLevel.wav");
			};
			std::vector<Level*> levels;
			int currentLevel = 1;
			Sound* nextLevel = nullptr;
	};
}

#endif