#ifndef LASERBEAM_H
#define LASERBEAM_H

#include "MovingSprite.h"

namespace ge{
	class LaserBeam : public MovingSprite
	{
		public:
			~LaserBeam();			
			bool outsideBounce();			
			void update(float delta);
			static LaserBeam* getInstance(int posX, int posY, bool bUp);
		private:		
			LaserBeam(int posX, int posY, bool bUp);
			float laserSpeed = 0.0f;
	};
}

#endif