#include "Enemy.h"
namespace ge{
	Enemy::Enemy(int posX, int posY) :
		MovingSprite("Enemy", posX, posY, 40, 40, "Player.bmp")
	{
	}
}
