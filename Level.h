#ifndef LEVEL_H
#define LEVEL_H

#include <vector>

namespace ge {
	class Level
	{
		public:
			Level(std::vector<int> enemySet) : 
				enemySet(enemySet)				
			{};
			std::vector<int> getEnemySet();
		private:
			std::vector<int> enemySet;			
	};
}

#endif // !LEVEL_H
