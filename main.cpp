#include <SFML\Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#include "Bullet.h"
#include "Vector2.h"
#include "Lazer.h"

int main()
{
	//�������� ���� � ��������� ���������
	int width = 800;
	int heigth = 600;
	sf::RenderWindow window(sf::VideoMode(width, heigth), "My window");
	
	//����������, � ������� ����� ������������ ������������ �������
	sf::Event event;

	//���������� �������� �� �����
	sf::Texture texture;
	/*if (!texture.loadFromFile("tiger.png"))
	{
		std::cout << "Foo!!!\n";
		return 0;
	}*/
	texture.loadFromFile("hero.png");
	//�������� �������, ������������ ���������
	sf::Sprite circle;
	circle.setTexture(texture);
	
	//circle.setTextureRect(sf::IntRect(0, 192, 96, 96));

	//������� �������� � ��������� ������
	float k = 0.5;
	circle.setScale(sf::Vector2f(k, k));
	sf::Vector2u buf = circle.getTexture()->getSize();
	sf::Vector2f size = sf::Vector2f(buf.x, buf.y) * 0.5f;
	circle.setOrigin(size.x, size.y);

	//������� ���������
	circle.setPosition(sf::Vector2f(width / 2, heigth / 2));
	
	//�������� �������� �����, ��������/�������
	int v = 50;

	std::vector < Bullet > queue;

	//����������� ����
	sf::Clock clock;
	float prevtime = 0;

	
	//Bullet bullet();
	//std::cout << bullet.posx << bullet.posy << std::endl;

	//�����, ��������� � ��������� ��������� ����
	sf::Time bullet_time = clock.getElapsedTime();

	while (window.isOpen())
	{
		//��������� ������������ ������������� �����
		sf::Time time = clock.getElapsedTime();
		float dt = time.asSeconds() - prevtime;
		prevtime = time.asSeconds();

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

		//������ ��������� �������
		sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
		//������ ��������� �����
		sf::Vector2f bullet_pos = circle.getPosition();
		sf::Vector2f d = sf::Vector2f(mouse_pos.x, mouse_pos.y) - bullet_pos;
		//������� ����� �� ������
		circle.setRotation(atan2f(d.y, d.x) * 180 / 3.14 + 90);
		
		//�������� ����� ��������� � ��������� �� ����� �� ������� ������
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && circle.getPosition().x > 0)
		{
			circle.move(-v * dt, 0);
		};
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && circle.getPosition().x < width - 2 * size.x)
		{
			circle.move(v * dt, 0);
		};
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && circle.getPosition().y > 0)
		{
			circle.move(0, -v * dt);
		};
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && circle.getPosition().y < heigth - 2 * size.y)
		{
			circle.move(0, v * dt);
		};

		//�������� ����� ���� ��� ������� ���, ���� � ������� �������� ���������� ������ ������ 0.1 �������
		if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && ((bullet_time.asSeconds() - time.asSeconds()) < - 0.1))
		{
			//������ ��������� �������
			mouse_pos = sf::Mouse::getPosition(window);
			//������ ��������� �����
			bullet_pos = circle.getPosition();
			d = sf::Vector2f(mouse_pos.x, mouse_pos.y) - bullet_pos;
			//����������� ���� �� ������
			Vector2 vel(100, 0);
			vel.rotateDegrees(atan2f(d.y, d.x) * 180 / 3.14);

			float r = 5.0;
			//���������� ���� �� ������ �����
			Bullet bullet(vel, bullet_pos.x - r, bullet_pos.y - r, r);
			queue.push_back(bullet);
			//����������� ������� �������� ����
			bullet_time = clock.getElapsedTime();
		}

		//��������� ������ ��� ������� ���
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			//������ ��������� �������
			sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
			//������ ��������� �����
			sf::Vector2f circle_pos = circle.getPosition();

			d = sf::Vector2f(mouse_pos.x, mouse_pos.y) - circle_pos;
			Lazer lazer(d, circle_pos);
			lazer.draw(window);
		}

		//��������� ����� � ����
		window.draw(circle);

		//��������� ���������� ����, ����������� ������ ������, �� ������������
		for (unsigned int i = 0; i < queue.size(); i++)
		{
			if (queue[i].posx > width || queue[i].posx < 0 || queue[i].posy > heigth || queue[i].posy < 0)
			{}
			else
			{
				queue[i].draw(window);
				queue[i].move(dt);
			}
		}
		

		//����� ����������� ���� �� �����
		window.display();
	}
	
	return 0;
} 