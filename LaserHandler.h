#ifndef LASERHANDLER_H
#define LASERHANDLER_H
#include <vector>
#include "LaserBeam.h"
#include "Scene.h"

namespace ge {
	class LaserHandler : public UpdateEachFrame
	{
		public:		
			LaserHandler();
			void Init(Scene* scene);
			~LaserHandler();
			void AddLaser(LaserBeam* laser);
			void CheckLaserBeams();
			void RemoveLaserBeam(LaserBeam* laser);
			void Update(float delta);
		private:
			std::vector<LaserBeam*> laserBeams;
			Scene* handlerScene;
	};
	extern LaserHandler laserHandler;
}

#endif