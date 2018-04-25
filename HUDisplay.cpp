#include "HUDisplay.h"

HUDisplay::HUDisplay()
{
	playerOneDisplay.setPosition(display_x, player_one_display_y);
	playerTwoDisplay.setPosition(display_x, player_two_display_y);
}

void HUDisplay::draw(sf::RenderWindow& window)
{
	window.draw(playerOneDisplay);
	window.draw(playerTwoDisplay);
}
