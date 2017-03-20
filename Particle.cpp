#include "SFML\Graphics.hpp"
#include "Particle.h"
#include "Vector2.h"
#include <iostream>

float R;
sf::Color color;

Particle::Particle(sf::Vector2f& p, sf::Vector2f& v, float m, float r, sf::Color& c) : Point::Point(p, v, m)
{
	R = r;
	color = c;
}

void Particle::draw(sf::RenderWindow& window)
{
	sf::CircleShape circle(R);
	circle.setFillColor(color);
	circle.setPosition(pos);
	window.draw(circle);
}

bool Particle::ifCollision(const Particle& a)
{
	sf::Vector2f d = a.pos - pos;
	float dist = d.x * d.x + d.y * d.y;
	Vector2 vd = convert(d);
	Vector2 rasn_v = convert(vel - a.vel);
	return (dist < (R + a.R) * (R + a.R) && rasn_v * vd >= 0);
}

void Particle::collisionToWall(const int type)
{
	//столкновение с вертикальной стеной
	if (type == 1)
	{
		vel.x = -vel.x;
	}
	//столкновение с горизонтальной стеной
	else if (type == 2)
	{
		vel.y = -vel.y;
	}
}

int Particle::ifCloseToWall(const int width, const int heigth)
{
	//близость к вертикальной стене
	if ((pos.x < 0 && vel.x < 0) || (width - pos.x < 2 * R && vel.x > 0))
	{
		return 1;
	}
	//близость к горизонтальной стене
	else if ((pos.y < 0 && vel.y < 0) || (heigth - pos.y < 2 * R && vel.y > 0))
	{
		return 2;
	}
	else return 0;
}

void collision(Particle& a, Particle& b)
{
	Vector2 vi = convert(a.vel);
	Vector2 vj = convert(b.vel);
	Vector2 n = convert(b.pos - a.pos);
	n = n.unit();
	Vector2 dp = (2 * (vj - vi) / (1 / a.M + 1 / b.M) * n) * n;
	vj -= dp / b.M;
	vi += dp / a.M;
	a.vel = convert(vi);
	b.vel = convert(vj);
}