#ifndef COMPONENT_H
#define COMPONENT_H
#include <iostream>

namespace ge {
	class Component {
	protected:
		Component();
	private:
		Component(const Component&) = delete;
		const Component& operator=(const Component&) = delete;		
	};
}

#endif