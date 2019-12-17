#ifndef GRAPHICOBJECT2D_H
#define GRAPHICOBJECT2D_H
#include "Component.h"
#include <iostream>
#include "Vector2.h"

namespace ge {
	class GraphicObject2D : public Component
	{
	public:		
		int* getWidth();
		int* getHeight();
		Vector2* getPosition();
	protected:
		GraphicObject2D(int posX, int posY, int width, int height) : Component(), position(posX,posY), width(width), height(height) {};		
		int width;
		int height;
		Vector2 position;
	private:
		GraphicObject2D(const GraphicObject2D&) = delete;
		const GraphicObject2D& operator=(const GraphicObject2D&) = delete;
	};
}

#endif