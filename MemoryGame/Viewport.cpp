#include "Viewport.h"

Viewport::Viewport(ModelData& data) :
	data{ data }
{}

bool Viewport::isOpen() const
{
	return window.isOpen();
}

void Viewport::input()
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
			sf::Vector2f mousePos = sf::Vector2f(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
			if (data.isMenu())
			{
				menu.input(mousePos);
			}
			else
			{
				game.input(mousePos);
			}
		}
	}
}

void Viewport::update()
{
	// remove if not used
}

void Viewport::draw()
{
	if (isOpen())
	{
		window.clear();

		if (data.isMenu())
		{
			menu.draw(window);
		}
		else
		{
			game.draw(window);
		}

		window.display();
	}
}
