#ifndef LASERHANDLER_H
#define LASERHANDLER_H
#include <vector>
#include "LaserBeam.h"
#include "Scene.h"
#include "CollisionHandler.h"
#include "Sound.h"

namespace ge {
	class LaserHandler : public UpdateEachFrame, public CollisionHandler
	{
		public:					
			void init(Scene* scene);			
			void addLaser(int posX, int posY, bool bUp);
			void checkLaserBeams();
			void removeLaserBeam(LaserBeam* laser);
			bool checkCollision(SDL_Rect* object);
			void update(float delta);
			~LaserHandler();
			void removeAllLaserBeams();
		private:
			std::vector<LaserBeam*> laserBeams;
			Scene* handlerScene = nullptr;	
			Sound* laserSound = nullptr;
	};
	extern LaserHandler laserHandler;
}

#endif