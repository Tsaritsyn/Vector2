#include "SFML\Graphics.hpp"
#include <vector>
#include <cmath>
#include "Particle.h"
#include <cstdlib>
#include <iostream>

const int width = 800;
const int heigth = 600;

int main()
{
	sf::RenderWindow window(sf::VideoMode(width, heigth), "My window");
	sf::Event event;
	sf::Clock clock;
	float prevtime = 0.0;
	float particle_time = 0.0;
	float time = 0.0;
	std::vector < Particle > queue;

	while (window.isOpen())
	{
		//��������� ������������ ������������� �����
		time = clock.getElapsedTime().asSeconds();
		float dt = time - prevtime;
		prevtime = time;

		while (window.pollEvent(event))
		{
			//�������� ���� ��� ������� �� ������� ��� Escape
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
		}

		//������� ���� � ������� ������
		window.clear(sf::Color::Green);

		//�������� ����� ������� ��� ������� ���, ���� � ������� �������� ���������� ������ ������ 0.2 �������
		if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && ((particle_time - time) < -0.2))
		{
			//������ ��������� �������
			sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
			//������� ��������� ��������
			int k = rand() % 500 + 1;
			int a = rand() % 360 + 1;
			sf::Vector2f v(k * cos(3.14159 * a / 180), k * sin(3.14159 * a / 180));
			sf::Vector2f pos(mouse_pos.x, mouse_pos.y);
			Particle newp(pos, v);
			queue.push_back(newp);
			
			//����������� ������� �������� �������
			particle_time = clock.getElapsedTime().asSeconds();
		}

		//������� ������������
		for (unsigned int i = 0; i < queue.size(); i++)
		{
			//� ������� ���������
			for (unsigned int j = i + 1; j < queue.size(); j++)
			{
				if (queue[i].ifCollision(queue[j]))
				{
					collision(queue[i], queue[j]);
				}
			}
			//�� ��������
			queue[i].collisionToWall(queue[i].ifCloseToWall(width, heigth));
			

			//��������� � ������������ ������
			queue[i].draw(window);
			queue[i].move(dt);
		}
		

		//����� ����������� ���� �� �����
		window.display();
	}

	return 0;
}