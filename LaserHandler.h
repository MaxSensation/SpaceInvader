#ifndef LASERHANDLER_H
#define LASERHANDLER_H
#include <vector>
#include "LaserBeam.h"
#include "Scene.h"
#include "CollisionHandler.h"

namespace ge {
	class LaserHandler : public UpdateEachFrame, public CollisionHandler
	{
		public:		
			LaserHandler();
			void init(Scene* scene);			
			void addLaser(LaserBeam* laser);
			void checkLaserBeams();
			void removeLaserBeam(LaserBeam* laser);
			bool checkCollision(SDL_Rect* object);
			void update(float delta);
			~LaserHandler();
		private:
			std::vector<LaserBeam*> laserBeams;
			Scene* handlerScene;
	};
	extern LaserHandler laserHandler;
}

#endif