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

	void highlightButton(const sf::Vector2f& mousePos);

	void input(const sf::Vector2f& mousePos);

	void update();

	void draw(sf::RenderWindow& window);
private:
	ModelData& data;
	sf::Font& font;
	sf::Texture cardMap;
	sf::RectangleShape pause{ sf::Vector2f(game_button_width, game_button_height) };
	sf::Text pauseString{ "Pause", font };
	sf::RectangleShape returnToMain{ sf::Vector2f(game_button_width, game_button_height) };
	sf::Text resetString{ "Return", font };
	HUDisplay hud{ data, font };
	std::vector<sf::RectangleShape> deck;
	bool paused{ false };
	gameMouseIn mouseIn{ gameMouseIn::none };

	void makeCards();

	void positionCards();
};

#endif // !BRUGLESCO_MEMORY_GAMESCREEN_H
