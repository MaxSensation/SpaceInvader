#ifndef LASERBEAM_H
#define LASERBEAM_H

#include "MovingSprite.h"


namespace ge{
	class LaserBeam : public MovingSprite
	{
		public:
			LaserBeam(int posX, int posY, bool bUp);
			bool OutsideBounce();			
			void Update(float delta);
		private:		
			float laserSpeed = 0.0f;
	};
}

#endif