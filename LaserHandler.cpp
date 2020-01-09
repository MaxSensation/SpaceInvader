#include "LaserHandler.h"

namespace ge {
	void LaserHandler::init(Scene* scene)
	{		
		handlerScene = scene;		
	}
	LaserHandler::~LaserHandler()
	{			
		auto laser = laserBeams.begin();
		while (laser != laserBeams.end())
		{
			(*laser)->removeSprite();
			*laser = nullptr;
			delete(*laser);
			laser = laserBeams.erase(laser);								
		}
		handlerScene = nullptr;
		delete(handlerScene);
	}

	void LaserHandler::addLaser(int posX, int posY, bool bUp)
	{		
		laserBeams.push_back(new LaserBeam(posX, posY, bUp));
		handlerScene->addSprite(laserBeams.back());
	}

	void LaserHandler::checkLaserBeams() {
		for (LaserBeam* laser : laserBeams) {
			if (laser->outsideBounce())
			{
				removeLaserBeam(laser);
			}
		}
	}

	void LaserHandler::removeLaserBeam(LaserBeam* laser) {					
		auto it = laserBeams.begin();		
		while (it != laserBeams.end())
		{
			if ((*it)->isDestroyd()) {					
				it = laserBeams.erase(it);			
			}
			else {
				++it;
			}
		}		
		laser->removeSprite();
		std::cout << "LaserBeam Removed" << std::endl;
	}

	bool LaserHandler::checkCollision(SDL_Rect* object) {
		for (LaserBeam* laser : laserBeams)
		{
			if (!(laser->isDestroyd()))
			{
				if (checkRectCollision(object, laser->getSpriteRect()))
				{
					removeLaserBeam(laser);
					return true;
				}
			}			
		}
		return false;
	}

	void LaserHandler::update(float delta)
	{				
		checkLaserBeams();
	}
	LaserHandler laserHandler;
}