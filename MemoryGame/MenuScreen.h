#ifndef BRUGLESCO_MEMORY_MENUSCREEN_H
#define BRUGLESCO_MEMORY_MENUSCREEN_H

#include "Expressions.h"
#include "GameScreen.h"
#include "ModelData.h"

#include <SFML\Graphics.hpp>

namespace memory {

	class MenuScreen
	{
	public:
		MenuScreen(ModelData& data, GameScreen& game, sf::Font& font);

		void trackMouse(const sf::Vector2f& mousePos);

		void input(const sf::Vector2f& mousePos);

		void update();

		void draw(sf::RenderWindow& window);
	private:
		ModelData & data;
		GameScreen& game;
		sf::Font& font;
		sf::RectangleShape playButton{ sf::Vector2f(menu_button_width, menu_button_height) };
		sf::Text playString{ "Play", font };
		sf::RectangleShape sixPairs{ sf::Vector2f(menu_button_width, menu_button_height) };
		sf::Text sixString{ "Six", font };
		sf::RectangleShape eightPairs{ sf::Vector2f(menu_button_width, menu_button_height) };
		sf::Text eightString{ "Eight", font };
		sf::RectangleShape twelvePairs{ sf::Vector2f(menu_button_width, menu_button_height) };
		sf::Text twelveString{ "Twelve", font };
		sf::RectangleShape sixteenPairs{ sf::Vector2f(menu_button_width, menu_button_height) };
		sf::Text sixteenString{ "Sixteen", font };
		std::vector<sf::Text> pairString{ 4, { "Pairs", font } };
		menuMouseIn mouseIn{ menuMouseIn::none };
		DeckSize deckSize{ DeckSize::six };

		void highlightButton();
	};

}

#endif // !BRUGLESCO_MEMORY_MENUSCREEN_H
