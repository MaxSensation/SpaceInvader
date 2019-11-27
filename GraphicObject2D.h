#ifndef GRAPHICOBJECT2D_H
#define GRAPHICOBJECT2D_H
#include "Component.h"
#include <iostream>

namespace ge {
	class GraphicObject2D : public Component
	{
	public:
		virtual ~GraphicObject2D();
		int* GetWidth();
		int* GetHeight();
		int* GetposX();
		int* GetposY();
	protected:
		GraphicObject2D(const std::string name, int posX, int posY, int width, int height) : Component(name), posX(posX), posY(posY), width(width), height(height) {

		};		
		int posX;
		int posY;
		int width;
		int height;
	private:
		GraphicObject2D(const GraphicObject2D&) = delete;
		const GraphicObject2D& operator=(const GraphicObject2D&) = delete;
	};
}

#endif