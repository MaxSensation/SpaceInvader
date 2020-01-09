#include "LaserBeam.h"
#include "GameEngine.h"

namespace ge{
	LaserBeam::LaserBeam(int posX, int posY, bool bUp) :
		MovingSprite(posX, posY, 20, 20, "LaserBeam.png"),
		laserSpeed(0.3f)
	{
		if (bUp)
		{
			velocity.y = -laserSpeed;
		}
		else
		{
			velocity.y = laserSpeed;
		}
		std::cout << "LaserBeam Spawned" << std::endl;
	}

	bool LaserBeam::outsideBounce() {
		if (position.y < 0 || position.y > *gameengine.getScreenHeight())
		{
			std::cout << "LaserBeam Outside Bounce and will be removed" << std::endl;
			return true;			
		}
		else {
			return false;
		}
	}

	void LaserBeam::update(float delta) {			
		position += velocity * delta;
	}
}
