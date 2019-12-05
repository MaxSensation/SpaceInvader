#include "Vector2.h"

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
