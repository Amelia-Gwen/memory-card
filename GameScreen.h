#ifndef BRUGLESCO_MEMORY_GAMESCREEN_H
#define BRUGLESCO_MEMORY_GAMESCREEN_H

#include "Expressions.h"
#include "HUDisplay.h"

#include <SFML\Graphics.hpp>

class GameScreen
{
public:
	void draw(sf::RenderWindow& window);
private:
	sf::RectangleShape pause{ sf::Vector2f(game_button_width, game_button_height) };
	sf::RectangleShape reset{ sf::Vector2f(game_button_width, game_button_height) };
	HUDisplay hud;
};

#endif // !BRUGLESCO_MEMORY_GAMESCREEN_H
