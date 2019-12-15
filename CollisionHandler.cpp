#include "CollisionHandler.h"

bool CollisionHandler::checkRectCollision(SDL_Rect object_a, SDL_Rect object_b)
{
	if (SDL_HasIntersection(&object_a, &object_b))
	{
		return true;
	}
	return false;
}
