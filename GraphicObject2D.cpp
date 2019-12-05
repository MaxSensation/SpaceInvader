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
	Vector2* GraphicObject2D::GetPosition()
	{
		return &position;
	}
}
