#ifndef COMPONENT_H
#define COMPONENT_H
#include <SDL.h>

namespace ge {
	class Component {
	public:		
		virtual ~Component();
		virtual void draw() const = 0;
	protected:
		Component();
	private:
		Component(const Component&) = delete;
		const Component& operator=(const Component&) = delete;
	};
}

#endif