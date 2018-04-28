#ifndef BRUGLESCO_MEMORY_GAMESCREEN_H
#define BRUGLESCO_MEMORY_GAMESCREEN_H

#include "Deck.h"
#include "Expressions.h"
#include "HUDisplay.h"

#include <SFML\Graphics.hpp>

class GameScreen
{
public:
	GameScreen();

	void dealDeck();

	void input(sf::Vector2f mousePos);

	void draw(sf::RenderWindow& window);
private:
	sf::Texture gameBackground;
	sf::Sprite backgroundSprite{ gameBackground, sf::IntRect(0, 0, window_width, window_height) };
	sf::RectangleShape pause{ sf::Vector2f(game_button_width, game_button_height) };
	sf::RectangleShape reset{ sf::Vector2f(game_button_width, game_button_height) };
	HUDisplay hud;
	Deck deck;
	DeckSize deckSize{ DeckSize::six };
};

#endif // !BRUGLESCO_MEMORY_GAMESCREEN_H
