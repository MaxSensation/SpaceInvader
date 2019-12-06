#include "LaserBeam.h"

namespace ge{
	LaserBeam::LaserBeam(int posX, int posY, bool bUp) :
		MovingSprite("LaserBeam", posX, posY, 20, 20, "LaserBeam.bmp"),
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

	bool LaserBeam::OutsideBounce() {
		if (position.y < 0)
		{
			std::cout << "LaserBeam Outside Bounce and will be removed" << std::endl;
			return true;			
		}
		else {
			return false;
		}
	}

	void LaserBeam::Update(float delta) {		
		position += velocity * delta;
	}
}
