#include "LevelHandler.h"

namespace ge {
	void LevelHandler::addLevel(Level* level)
	{
		levels.push_back(level);
	}

	void LevelHandler::NextLevel()
	{
		if (currentLevel < levels.size())
		{
			loadLevel(levels[currentLevel - 1]);
			currentLevel += 1;
		}
	}

	bool LevelHandler::hasNextLevel() {
		if (currentLevel < levels.size())
			return true;
		else
			return false;
	}

	int LevelHandler::getCurrentLevelnr() {
		return currentLevel;
	}

	void LevelHandler::loadLevel(Level* level) {
		enemyHandler -> addEnemySet(level->getEnemySet());
	}

	void LevelHandler::loadLevel(int level) {		
		
		if (level <= levels.size() && level > 0)
		{			
			enemyHandler -> addEnemySet(levels[level - 1]->getEnemySet());
		}		
	}
}