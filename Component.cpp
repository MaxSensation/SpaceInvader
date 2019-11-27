#include "Component.h"
#include <iostream>

using namespace std;

namespace ge {

	Component::Component(const string name) : name(name)
	{

	}

	Component::~Component()
	{

	}

	string Component::GetName()
	{
		return name;
	}
}