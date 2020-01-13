#include "LaserBeam.h"
#include "GameEngine.h"

namespace ge{
	LaserBeam::~LaserBeam()
	{
	}
	LaserBeam::LaserBeam(int posX, int posY, bool bUp) :
		MovingSprite(posX, posY, 20, 20, "LaserBeam.png"),
		laserSpeed(0.3f)
	{
		if (bUp)
		{
			velocity.setY(-laserSpeed);
		}
		else
		{
			velocity.setY(laserSpeed);
		}
		std::cout << "LaserBeam Spawned" << std::endl;
	}

	bool LaserBeam::outsideBounce() {
		if (position.getY() < 0 || position.getY() > *gameengine.getScreenHeight())
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
	LaserBeam* LaserBeam::getInstance(int posX, int posY, bool bUp)
	{
		return new LaserBeam(posX, posY, bUp);
	}
}
