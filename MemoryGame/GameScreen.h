#ifndef BRUGLESCO_MEMORY_GAMESCREEN_H
#define BRUGLESCO_MEMORY_GAMESCREEN_H

#include "Deck.h"
#include "Expressions.h"
#include "HUDisplay.h"
#include "Player.h"

#include <SFML\Graphics.hpp>

#include <memory>
#include <vector>

class GameScreen
{
public:
	GameScreen();

	bool getDeactivation() const;

	void reset();

	void play(const DeckSize& size);

	void input(sf::Vector2f mousePos);

	void draw(sf::RenderWindow& window);
private:
	sf::Texture gameBackground;
	sf::Sprite backgroundSprite{ gameBackground, sf::IntRect(0, 0, window_width, window_height) };
	sf::RectangleShape pause{ sf::Vector2f(game_button_width, game_button_height) };
	sf::RectangleShape returnToMain{ sf::Vector2f(game_button_width, game_button_height) };
	HUDisplay hud;
	unsigned numPlayers{ 2 };
	std::vector<Player> players;
	Player* activePlayer{ nullptr };
	Deck deck;
	bool quit{ false };
	bool paused{ false };

	void dealDeck(const DeckSize& size);

	void trackTurn();
};

#endif // !BRUGLESCO_MEMORY_GAMESCREEN_H
