#ifndef VECTOR_H
#define VECTOR_H

class Vector2
{
	public:
		Vector2() : x(0.0f), y(0.0f) {};
		Vector2(float x, float y) : x(x), y(y) {};
		Vector2 operator+(Vector2 const& other);
		Vector2& operator+=(Vector2 const& other);
		Vector2 operator*(float other);
		float x, y;
};

#endif // !VECTOR_H