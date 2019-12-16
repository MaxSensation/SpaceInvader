#ifndef GAME_H
#define GAME_H

#include "GameEngine.h"
#include "GameInput.h"
#include "Player.h"
#include "Enemy.h"
#include "LaserHandler.h"
#include "EnemyHandler.h"
#include "LevelHandler.h"
#include "Level.h"
#include "UpdateEachFrame.h"
#include "Text.h"

namespace ge{
	class Game : public UpdateEachFrame
	{
		public:
			Game();
			~Game();		
		private:
			void playerWon();
			void nextLevel();
			void gameOver();
			void checkGameStatus();
			void calcScore();
			void updateLevelText();
			void update(float delta);

			Player* player = nullptr;
			Text* textScore = nullptr;
			Text* score = nullptr;			
			Text* winningText = nullptr;
			Text* gameOverText = nullptr;
			Text* textLevel = nullptr;
			Text* level = nullptr;			
			Enemy* enemy = nullptr;
			Scene* scene = nullptr;
			EnemyHandler* enemyHandler = nullptr;
			LevelHandler* levelHandler = nullptr;
			int SCREENWITDH = 0;
			int SCREENHEIGHT = 0;
			int fpsCap = 0;
			bool bWon = false;
			bool bGameOver = false;
	};
}

#endif