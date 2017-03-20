#include <SFML\Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Lazer.h"

sf::Vector2f dir, pos;

Lazer::Lazer(sf::Vector2f& d, sf::Vector2f& p)
{
	dir = d;
	pos = p;
}

void Lazer::draw(sf::RenderWindow& window)
{
	float k = window.getSize().x + window.getSize().y;
	sf::Vertex line[] =
	{
		sf::Vertex(pos), sf::Vertex(pos + k * dir)
	};
	window.draw(line, 2, sf::Lines);
}
