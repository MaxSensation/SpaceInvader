#include "Vector2.h"

namespace ge{

	Vector2 Vector2::operator+(Vector2 const& other)
	{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2& Vector2::operator+=(Vector2 const& other)
	{
		x += other.x;
		y += other.y;

		return *this;
	}

	Vector2 Vector2::operator*(float other)
	{
		return Vector2(x * other, y * other);
	}

	float Vector2::getX()
	{
		return x;
	}

	float Vector2::getY()
	{
		return y;
	}

	float Vector2::setX(float newX)
	{
		return x = newX;
	}

	float Vector2::setY(float newY)
	{
		return y = newY;
	}

}