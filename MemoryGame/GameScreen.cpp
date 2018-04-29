#include "GameScreen.h"

GameScreen::GameScreen()
{
	//gameBackground.loadFromFile("");
	pause.setPosition(pause_x, 0);
	reset.setPosition(reset_x, 0);
}

void GameScreen::dealDeck()
{
	deck.set(deckSize);
}

void GameScreen::input(sf::Vector2f mousePos)
{
	if (pause.getGlobalBounds().contains(mousePos))
	{
		// pause
	}
	else if (reset.getGlobalBounds().contains(mousePos))
	{
		deck.set(deckSize);
	}
	deck.input(mousePos);
}

void GameScreen::draw(sf::RenderWindow& window)
{
	window.draw(backgroundSprite);
	window.draw(pause);
	window.draw(reset);
	hud.draw(window);
	deck.draw(window);
}
