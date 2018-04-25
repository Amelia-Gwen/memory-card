#include "GameScreen.h"

void GameScreen::draw(sf::RenderWindow& window)
{
	window.draw(pause);
	window.draw(reset);
	hud.draw(window);
}
