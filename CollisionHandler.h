#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H
#include "SDL.h"
#include "Component.h"

namespace ge{
	class CollisionHandler : Component
	{		
		protected:
			bool checkRectCollision(SDL_Rect* object_a, SDL_Rect* object_b);
			CollisionHandler() {};
		private:
			CollisionHandler(const CollisionHandler&) = delete;
			const CollisionHandler& operator=(const CollisionHandler&) = delete;
	};
}
#endif // !COLLISIONHANDLER_H
