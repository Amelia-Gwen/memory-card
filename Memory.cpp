#include "Memory.h"

Memory::Memory()
{
	window.setFramerateLimit(60);
}

void Memory::run()
{
	while (window.isOpen())
	{
		input();
		update();
		draw();
	}
}

void Memory::input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		window.close();
	}

	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}

		if (event.type == sf::Event::MouseButtonPressed)
		{
			sf::Vector2f mousePos = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
			if (!playing)
			{
				mainMenu.input(mousePos);
			}
			else
			{
				gameScreen.input(mousePos);
			}
		}
	}
}

void Memory::update()
{
	// call necessary update functions
}

void Memory::draw()
{
	window.clear();

	if (!playing)
	{
		mainMenu.draw(window);
	}
	else
	{
		gameScreen.draw(window);
	}

	window.display();
}
