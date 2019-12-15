#include "GraphicObject2D.h"

namespace ge{
	GraphicObject2D::~GraphicObject2D()
	{
	}
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
