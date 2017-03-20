#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <cmath>

struct Lazer
{
	sf::Vector2f dir;
	sf::Vector2f pos;
	Lazer(sf::Vector2f& d, sf::Vector2f& p);
	void draw(sf::RenderWindow& window);
};