#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Vector2.h"

struct Bullet
{
	float posx, posy, r;
	Vector2 v;
	Bullet(Vector2& vel, float a = 0, float b = 0, float rad = 5.0);
	void move(float dt);
	void draw(sf::RenderWindow& window);
};