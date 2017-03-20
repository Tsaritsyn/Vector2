#pragma once
#include "SFML\Graphics.hpp"

struct Point
{
	Point(sf::Vector2f& p = sf::Vector2f(0, 0), sf::Vector2f& v = sf::Vector2f(1, 1), float m = 1);
	sf::Vector2f pos;
	sf::Vector2f vel;
	float M;
	void move(float dt);
};
