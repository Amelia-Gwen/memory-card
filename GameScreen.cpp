#include "GameScreen.h"

GameScreen::GameScreen()
{
	//gameBackground.loadFromFile("");
	pause.setPosition(pause_x, 0);
	reset.setPosition(reset_x, 0);
}

void GameScreen::input(sf::Vector2f mousePos)
{
	if (pause.getGlobalBounds().contains(mousePos))
	{

	}
	else if (reset.getGlobalBounds().contains(mousePos))
	{

	}
}

void GameScreen::draw(sf::RenderWindow& window)
{
	window.draw(backgroundSprite);
	window.draw(pause);
	window.draw(reset);
	hud.draw(window);
}
