#ifndef BRUGLESCO_MEMORY_HUDISPLAY_H
#define BRUGLESCO_MEMORY_HUDISPLAY_H

#include "Expressions.h"

#include <SFML\Graphics.hpp>

class HUDisplay
{
public:
	HUDisplay();

	void draw(sf::RenderWindow& window);
private:
	sf::RectangleShape playerOneDisplay{ sf::Vector2f(display_width, display_height) };
	sf::RectangleShape playerTwoDisplay{ sf::Vector2f(display_width, display_height) };
	sf::Font font;
	sf::Text playerOne{ "Player One:", font };
	sf::Text playerTwo{ "Player Two:", font };
};

#endif // !BRUGLESCO_MEMORY_HUDISPLAY_H
