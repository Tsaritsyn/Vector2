#include <iostream>
#include <cmath>
#include "Vector2.h"

const float pi = 3.14;

float x, y;

Vector2::Vector2(float a, float b)
{
	x = a;
	y = b;
};

	Vector2 Vector2::operator + (const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	};

	Vector2& Vector2::operator += (const Vector2& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	};

	Vector2 Vector2::operator - (const Vector2& other) const
	{
		return Vector2(x - other.x, y - other.y);
	};

	Vector2 Vector2::operator - () const
	{
		return Vector2(-x, -y);
	};

	Vector2& Vector2::operator -= (const Vector2& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	};
	float Vector2::operator * (const Vector2& other) const	//scalar multiplication
	{
		return (x * other.x + y * other.y);
	};

	float Vector2::operator ^ (const Vector2& other) const	//length of vector multiplication
	{
		return (x * other.y - y * other.x);
	};

	Vector2 Vector2::operator * (const float k) const		//right multiplication with a number
	{
		return Vector2(x * k, y * k);
	};

	Vector2 Vector2::operator / (const float k) const
	{
		return Vector2(x / k, y / k);
	}

	Vector2 Vector2::normal()
	{
		return Vector2(-x, y);
	};

	float Vector2::length()
	{
		return sqrt(x * x + y * y);
	};

Vector2 Vector2::unit()					//vector of length 1
	{
		//return Vector2(x / sqrt(x * x + y * y), y / sqrt(x * x + y * y));
		return Vector2(x / length(), y / length());
	};

	void Vector2::rotateDegrees(const float f)
	{
		float x0 = x;
		float y0 = y;
		x = x0 * cos(f * pi / 180) - y0 * sin(f * pi / 180);
		y = y0 * cos(f * pi / 180) + x0 * sin(f * pi / 180);
	};

	Vector2 Vector2::getRotatedDegrees(const float f)
	{
		return Vector2(x * cos(f * pi / 180) - y * sin(f * pi / 180), y * cos(f * pi / 180) + x * sin(f * pi / 180));
	};

std::istream& operator >> (std::istream& stream, Vector2& v)	//input
{
	std::cin >> v.x >> v.y;
	return stream;
};
std::ostream& operator << (std::ostream& stream, const Vector2& v)	//output
{
	stream << v.x << ' ' << v.y << endl;
	return stream;
};
Vector2 operator * (float k, const Vector2& v)	//right multiplication with a number
{
	return Vector2(v.x * k, v.y * k);
};

Vector2 convert(sf::Vector2f& v)
{
	Vector2 res(v.x, v.y);
	return res;
}

sf::Vector2f convert(Vector2 v)
{
	return sf::Vector2f(v.x, v.y);
}