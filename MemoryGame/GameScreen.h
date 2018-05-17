#ifndef BRUGLESCO_MEMORY_GAMESCREEN_H
#define BRUGLESCO_MEMORY_GAMESCREEN_H

#include "Card.h"
#include "Expressions.h"
#include "HUDisplay.h"
#include "ModelData.h"

#include <SFML\Graphics.hpp>

#include <vector>

class GameScreen
{
public:
	GameScreen(ModelData& data, sf::Font& font);

	void setGame();

	void trackMouse(const sf::Vector2f& mousePos);

	void input(const sf::Vector2f& mousePos);

	void update();

	void draw(sf::RenderWindow& window);
private:
	ModelData& data;
	sf::Font& font;
	sf::Texture cardMap;
	sf::RectangleShape pauseButton{ sf::Vector2f(game_button_width, game_button_height) };
	sf::Text pauseString{ "Pause", font };
	sf::RectangleShape returnToMain{ sf::Vector2f(game_button_width, game_button_height) };
	sf::Text resetString{ "Return", font };
	HUDisplay hud{ data, font };
	sf::RectangleShape pauseForeground{ sf::Vector2f(static_cast<float>(screen_width), static_cast<float>(screen_height)) };
	sf::RectangleShape endGameForeground{ sf::Vector2f(win_width, win_height) };
	sf::Text winString{ "Winner", font };
	sf::Text playerWinString{ "", font };
	std::vector<sf::RectangleShape> deck;
	gameMouseIn mouseIn{ gameMouseIn::none };
	bool paused{ false };
	std::vector<unsigned> imageIdentifiers;
	unsigned delay{ 0 };

	void makeCards();

	void positionCards();

	void highlightButtons();

	void matchFailDelay();

	void endFailDelay();

	void moveMatched();

	void highlightCards(); // to be removed
};

#endif // !BRUGLESCO_MEMORY_GAMESCREEN_H
