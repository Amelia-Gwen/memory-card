#include "Viewport.h"

Viewport::Viewport(ModelData& data) :
	data{ data }
{
	font.loadFromFile("{PixelFlag}.ttf");
	background.setFillColor(sf::Color(100, 100, 100, 255));
}

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
	
	sf::Vector2f mousePos = sf::Vector2f(static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y));
	
	
	sf::Event event;
	while (window.pollEvent(event))
	{
		
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		
		if (event.type == sf::Event::MouseMoved)
		{
			if (data.isMenu())
			{
				menu.highlightButton(mousePos);
			}
			else
			{
				game.highlightButton(mousePos);
			}
		}

		if (event.type == sf::Event::MouseButtonPressed)
		{
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
	game.update();
}

void Viewport::draw()
{
	if (isOpen())
	{
		window.clear();

		window.draw(background);

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
