#include "GraphicObject2D.h"

namespace ge{	
	int* GraphicObject2D::getWidth()
	{
		return &width;
	}
	int* GraphicObject2D::getHeight()
	{
		return &height;
	}
	Vector2* GraphicObject2D::getPosition()
	{
		return &position;
	}
}
