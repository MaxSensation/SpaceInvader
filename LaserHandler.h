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
			static LaserHandler* getInstance();
			static void deleteInstance();
			void addLaser(int posX, int posY, bool bUp);
			void checkLaserBeams();
			void removeLaserBeam(LaserBeam* laser);
			bool checkCollision(SDL_Rect* object);
			void update(float delta);						
			void removeAllLaserBeams();			
		private:			
			static LaserHandler* instance;
			~LaserHandler();
			LaserHandler();
			std::vector<LaserBeam*> laserBeams;
			Sound* laserSound = nullptr;
	};
}

#endif