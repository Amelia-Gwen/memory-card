#include "GameScreen.h"

GameScreen::GameScreen()
{
	//gameBackground.loadFromFile("");
	pause.setPosition(pause_x, 0);
	reset.setPosition(reset_x, 0);
}

void GameScreen::draw(sf::RenderWindow& window)
{
	window.draw(backgroundSprite);
	window.draw(pause);
	window.draw(reset);
	hud.draw(window);
}
