#include "LaserHandler.h"
#include "GameEngine.h"

namespace ge {
	void LaserHandler::init(Scene* scene)
	{		
		handlerScene = scene;	
		laserSound = gameengine.getSoundManager()->createSound("laser.wav");
	}
	LaserHandler::~LaserHandler()
	{					 
		delete(laserSound);
		handlerScene = nullptr;
		delete(handlerScene);	
	}

	void LaserHandler::removeAllLaserBeams() {
		auto laser = laserBeams.begin();
		while (laser != laserBeams.end())
		{
			(*laser)->removeSprite();
			laser = laserBeams.erase(laser);
		}
	}

	void LaserHandler::addLaser(int posX, int posY, bool bUp)
	{		
		LaserBeam* l = LaserBeam::getInstance(posX, posY, bUp);
		laserBeams.push_back(l);
		handlerScene->addSprite(laserBeams.back());		
		laserSound->play();
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