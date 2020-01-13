#include "LevelHandler.h"

namespace ge {
	LevelHandler* LevelHandler::instance = 0;

	LevelHandler* LevelHandler::getInstance()
	{
		if (instance == 0)
		{
			instance = new LevelHandler();
		}
		return instance;
	}

	void LevelHandler::deleteInstance()
	{
		delete instance;
		instance = NULL;
	}

	LevelHandler::~LevelHandler()
	{		
		auto level = levels.begin();
		while (level != levels.end())
		{			
			delete(*level);
			level = levels.erase(level);
		}
		nextLevel = nullptr;
		delete(nextLevel);	
	}

	void LevelHandler::addLevel(std::vector<int> enemySet)
	{
		levels.push_back(new Level(enemySet));
	}

	void LevelHandler::NextLevel()
	{
		if (currentLevel < levels.size())
		{
			loadLevel(levels[currentLevel - 1]);
			currentLevel += 1;
			nextLevel->play();
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
		EnemyHandler::getInstance()-> addEnemySet(level->getEnemySet());
	}

	void LevelHandler::loadLevel(int level) {		
		
		if (level <= levels.size() && level > 0)
		{			
			EnemyHandler::getInstance()-> addEnemySet(levels[level - 1]->getEnemySet());
		}		
	}
}