#ifndef BRUGLESCO_MEMORY_MENUSCREEN_H
#define BRUGLESCO_MEMORY_MENUSCREEN_H

#include "Expressions.h"
#include "GameScreen.h"
#include "ModelData.h"

#include <SFML\Graphics.hpp>
class MenuScreen
{
public:
	MenuScreen(ModelData& data, GameScreen& game);

	void input(const sf::Vector2f& mousePos);

	void draw(sf::RenderWindow& window);
private:
	ModelData& data;
	GameScreen& game;
	sf::Texture menuMap;
	sf::RectangleShape playButton{ sf::Vector2f(menu_button_width, menu_button_height) };
	sf::RectangleShape sixPairs{ sf::Vector2f(menu_button_width, menu_button_height) };
	sf::RectangleShape eightPairs{ sf::Vector2f(menu_button_width, menu_button_height) };
	sf::RectangleShape twelvePairs{ sf::Vector2f(menu_button_width, menu_button_height) };
	sf::RectangleShape sixteenPairs{ sf::Vector2f(menu_button_width, menu_button_height) };

	void highlight();
};
#endif // !BRUGLESCO_MEMORY_MENUSCREEN_H
