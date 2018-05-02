#ifndef BRUGLESCO_MEMORY_MAINMENU_H
#define BRUGLESCO_MEMORY_MAINMENU_H

#include "Expressions.h"

#include <SFML\Graphics.hpp>

class MainMenu
{
public:
	MainMenu();

	bool getActivation() const;

	DeckSize getSize() const;

	void reset();

	void input(sf::Vector2f mousePos);

	void draw(sf::RenderWindow& window);
private:
	sf::Texture menuBackground;
	sf::Sprite backgroundSprite{ menuBackground, sf::IntRect(0, 0, window_width, window_height) };
	sf::RectangleShape playButton{ sf::Vector2f(menu_button_width, menu_button_height) };
	sf::RectangleShape sixPairs{ sf::Vector2f(menu_button_width, menu_button_height) };
	sf::RectangleShape eightPairs{ sf::Vector2f(menu_button_width, menu_button_height) };
	sf::RectangleShape twelvePairs{ sf::Vector2f(menu_button_width, menu_button_height) };
	sf::RectangleShape sixteenPairs{ sf::Vector2f(menu_button_width, menu_button_height) };
	DeckSize deckSize{ DeckSize::six };
	bool activated{ false };

	void highlightPair();
};

#endif // !BRUGLESCO_MEMORY_MAINMENU_H
