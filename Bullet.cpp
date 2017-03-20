#include <SFML\Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Vector2.h"
#include "Bullet.h"

float posx, posy, r;

Bullet::Bullet(Vector2& vel, float a, float b, float rad)
{
	posx = a;
	posy = b;
	r = rad;
	v = vel;
}

void Bullet::move(float dt)
{
	posx += v.x * dt;
	posy += v.y * dt;
}
void Bullet::draw(sf::RenderWindow& window)
{
	sf::CircleShape bullet(r);
	bullet.setPosition(sf::Vector2f(posx, posy));
	bullet.setFillColor(sf::Color::Black);
	window.draw(bullet);
}
