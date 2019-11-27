#ifndef COMPONENT_H
#define COMPONENT_H
#include <iostream>

namespace ge {
	class Component {
	public:		
		virtual ~Component();
		std::string GetName();
	protected:
		Component(std::string name);
	private:
		Component(const Component&) = delete;
		const Component& operator=(const Component&) = delete;
		std::string name;
	};
}

#endif