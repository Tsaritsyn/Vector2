#pragma once
#include "SFML\Graphics.hpp"
#include "Point.h"

struct Particle : public Point
{
	float R;
	sf::Color color;
	Particle(sf::Vector2f& p, sf::Vector2f& v, float m = 1, float r = 10, sf::Color& c = sf::Color(sf::Color::Red));
	void draw(sf::RenderWindow& window);
	bool ifCollision(const Particle& a);
	int ifCloseToWall(const int width, const int heigth);
	void collisionToWall(const int type);
};

void collision(Particle& a, Particle& b);

