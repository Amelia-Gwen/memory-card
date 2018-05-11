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
	GameScreen(ModelData& data);

	void setGame();

	void input(const sf::Vector2f& mousePos);

	void update();

	void draw(sf::RenderWindow& window);
private:
	ModelData& data;
	sf::Texture cardMap;
	sf::Texture gameButtonMap;
	sf::RectangleShape pause{ sf::Vector2f(game_button_width, game_button_height) };
	sf::RectangleShape returnToMain{ sf::Vector2f(game_button_width, game_button_height) };
	HUDisplay hud{ data };
	std::vector<sf::RectangleShape> deck;
	bool paused{ false };

	void makeCards();

	void positionCards();
};

#endif // !BRUGLESCO_MEMORY_GAMESCREEN_H
