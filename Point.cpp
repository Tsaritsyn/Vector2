#include "SFML\Graphics.hpp"
#include "Point.h"

sf::Vector2f pos;
sf::Vector2f vel;
float M;

Point::Point(sf::Vector2f& p, sf::Vector2f& v, float m)
{
	pos = p;
	vel = v;
	M = m;
}

void Point::move(float dt)
{
	pos += vel * dt;
}