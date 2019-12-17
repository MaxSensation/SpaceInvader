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
			{};
			~LevelHandler();
			void addLevel(Level* level);
			void NextLevel();
			bool hasNextLevel();
			int getCurrentLevelnr();
			void loadLevel(Level* level);
			void loadLevel(int level);
		private:
			std::vector<Level*> levels;
			EnemyHandler* enemyHandler;
			int currentLevel = 1;
	};
}

#endif