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
		//выяснение длительности существование кадра
		time = clock.getElapsedTime().asSeconds();
		float dt = time - prevtime;
		prevtime = time;

		while (window.pollEvent(event))
		{
			//закрытие окна при нажатии на крестик или Escape
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
		}

		//очистка окна и заливка зелёным
		window.clear(sf::Color::Green);

		//создание новой частицы при нажатой ЛКМ, если с момента создания предыдущей прошло больше 0.2 секунды
		if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && ((particle_time - time) < -0.2))
		{
			//взятие координат курсора
			sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
			//задание случайной скорости
			int k = rand() % 500 + 1;
			int a = rand() % 360 + 1;
			sf::Vector2f v(k * cos(3.14159 * a / 180), k * sin(3.14159 * a / 180));
			sf::Vector2f pos(mouse_pos.x, mouse_pos.y);
			Particle newp(pos, v);
			queue.push_back(newp);
			
			//запоминание времени создания частицы
			particle_time = clock.getElapsedTime().asSeconds();
		}

		//просчёт столкновений
		for (unsigned int i = 0; i < queue.size(); i++)
		{
			//с другими частицами
			for (unsigned int j = i + 1; j < queue.size(); j++)
			{
				if (queue[i].ifCollision(queue[j]))
				{
					collision(queue[i], queue[j]);
				}
			}
			//со стенками
			queue[i].collisionToWall(queue[i].ifCloseToWall(width, heigth));
			

			//отрисовка и передвижение частиц
			queue[i].draw(window);
			queue[i].move(dt);
		}
		

		//вывод содержимого окна на экран
		window.display();
	}

	return 0;
}