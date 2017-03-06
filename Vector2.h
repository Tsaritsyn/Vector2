#pragma once
#include <iostream>
using namespace std;

struct Vector2
{
	float x, y;
	Vector2(float a = 0, float b = 0)
	{
		x = a;
		y = b;
	};
	Vector2 operator + (const Vector2& other) const;
	Vector2& operator += (const Vector2& other);
	Vector2 operator - (const Vector2& other) const;
	Vector2 operator - () const;
	Vector2& operator -= (const Vector2& other);
	float operator * (const Vector2& other) const;	//scalar multiplication
	float operator ^ (const Vector2& other) const;	//length of vector multiplication
	Vector2 operator * (const float k) const;		//right multiplication with a number
	Vector2 operator / (const float k) const;
	Vector2 unit();					//vector of length 1
	Vector2 normal();
	float length();
	void rotateDegrees(const float f);
	Vector2 getRotatedDegrees(const float f);
};

istream& operator >> (istream& stream, Vector2& v);	//input
ostream& operator << (ostream& stream, const Vector2& v);	//output
Vector2 operator * (float k, const Vector2& v);	//right multiplication with a number