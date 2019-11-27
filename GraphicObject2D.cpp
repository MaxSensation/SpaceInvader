#include "GraphicObject2D.h"

namespace ge{
	GraphicObject2D::~GraphicObject2D()
	{
	}
	int* GraphicObject2D::GetWidth()
	{
		return &width;
	}
	int* GraphicObject2D::GetHeight()
	{
		return &height;
	}
	int* GraphicObject2D::GetposX()
	{
		return &posX;
	}
	int* GraphicObject2D::GetposY()
	{
		return &posY;
	}
}
