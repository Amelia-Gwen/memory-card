#include "HUDisplay.h"

void HUDisplay::draw(sf::RenderWindow& window)
{
	window.draw(playerOneDisplay);
	window.draw(playerTwoDisplay);
}
