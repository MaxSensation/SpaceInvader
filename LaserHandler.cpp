#include "LaserHandler.h"
#include "GameEngine.h"

namespace ge {
	LaserHandler* LaserHandler::instance = 0;

	LaserHandler* LaserHandler::getInstance()
	{
		if (instance == 0)
		{
			instance = new LaserHandler();
		}
		return instance;
	}

	void LaserHandler::deleteInstance()
	{
		delete instance;
		instance = NULL;
	}

	LaserHandler::~LaserHandler()
	{					
		removeAllLaserBeams();	
	}

	LaserHandler::LaserHandler() {
		laserSound = GameEngine::getInstance()->getSoundManager()->createSound("laser.wav");
	}

	void LaserHandler::removeAllLaserBeams() {
		auto laser = laserBeams.begin();
		while (laser != laserBeams.end())
		{
			delete(*laser);
			laser = laserBeams.erase(laser);
		}
	}

	void LaserHandler::addLaser(int posX, int posY, bool bUp)
	{		
		LaserBeam* l = LaserBeam::getInstance(posX, posY, bUp);
		laserBeams.push_back(l);	
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
			if ((*it)== laser) {
				delete(*it);
				it = laserBeams.erase(it);
			}
			else {
				++it;
			}
		}			
		std::cout << "LaserBeam Removed" << std::endl;
	}

	bool LaserHandler::checkCollision(SDL_Rect* object) {
		for (LaserBeam* laser : laserBeams)
		{
			if (checkRectCollision(object, laser->getSpriteRect()))
			{
				removeLaserBeam(laser);
				return true;
			}		
		}
		return false;
	}

	void LaserHandler::update(float delta)
	{				
		checkLaserBeams();	
	}
}