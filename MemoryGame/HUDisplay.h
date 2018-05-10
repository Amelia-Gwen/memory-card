#ifndef BRUGLESCO_MEMORY_HUDISPLAY_H
#define BRUGLESCO_MEMORY_HUDISPLAY_H

#include "Expressions.h"
#include "ModelData.h"

#include <SFML\Graphics.hpp>

#include <string>

class HUDisplay
{
public:
	HUDisplay(ModelData& data);

	void draw(sf::RenderWindow& window);
private:
	ModelData& data;
	sf::RectangleShape playerOneDisplay{ sf::Vector2f(display_width, display_height) };
	sf::RectangleShape playerTwoDisplay{ sf::Vector2f(display_width, display_height) };
	sf::Font font;
	unsigned playerOneScore{ 0 };
	sf::Text playerOne{ "Player One: " + std::to_string(playerOneScore), font };
	unsigned playerTwoScore{ 0 };
	sf::Text playerTwo{ "Player Two: " + std::to_string(playerTwoScore), font };
};

#endif // !BRUGLESCO_MEMORY_HUDISPLAY_H
