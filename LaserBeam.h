#ifndef LASERBEAM_H
#define LASERBEAM_H

#include "MovingSprite.h"

namespace ge{
	class LaserBeam : public MovingSprite
	{
		public:
			~LaserBeam();
			LaserBeam(int posX, int posY, bool bUp);
			bool outsideBounce();			
			void update(float delta);
		private:		
			float laserSpeed = 0.0f;
	};
}

#endif