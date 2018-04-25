#ifndef BRUGLESCO_MEMORY_HUDISPLAY_H
#define BRUGLESCO_MEMORY_HUDISPLAY_H

#include "Expressions.h"

#include <SFML\Graphics.hpp>

#include <string>

class HUDisplay
{
public:
	HUDisplay();

	void draw(sf::RenderWindow& window);
private:
	sf::RectangleShape playerOneDisplay{ sf::Vector2f(display_width, display_height) };
	sf::RectangleShape playerTwoDisplay{ sf::Vector2f(display_width, display_height) };
};

#endif // !BRUGLESCO_MEMORY_HUDISPLAY_H
