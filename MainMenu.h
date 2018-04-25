#ifndef BRUGLESCO_MEMORY_MAINMENU_H
#define BRUGLESCO_MEMORY_MAINMENU_H

#include "Expressions.h"

#include <SFML\Graphics.hpp>

class MainMenu
{
public:
	MainMenu();

	void draw(sf::RenderWindow& window);
private:
	sf::RectangleShape playButton{ sf::Vector2f(menu_button_width, menu_button_height) };
	sf::RectangleShape sixPairs{ sf::Vector2f(menu_button_width, menu_button_height) };
	sf::RectangleShape eightPairs{ sf::Vector2f(menu_button_width, menu_button_height) };
	sf::RectangleShape twelvePairs{ sf::Vector2f(menu_button_width, menu_button_height) };
	sf::RectangleShape sixteenPairs{ sf::Vector2f(menu_button_width, menu_button_height) };
};

#endif // !BRUGLESCO_MEMORY_MAINMENU_H
