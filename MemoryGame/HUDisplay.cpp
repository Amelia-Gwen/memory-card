#include "HUDisplay.h"

HUDisplay::HUDisplay()
{
	//font.loadFromFile("");
	playerOneDisplay.setPosition(display_x, player_one_display_y);
	playerOneDisplay.setFillColor(sf::Color::Black); // to be removed
	playerTwoDisplay.setPosition(display_x, player_two_display_y);
	playerTwoDisplay.setFillColor(sf::Color::Black); // to be removed
	playerOne.setCharacterSize(30);
	//playerOne.setPosition();
	playerTwo.setCharacterSize(30);
	//playerTwo.setPosition();
}

void HUDisplay::draw(sf::RenderWindow& window)
{
	window.draw(playerOneDisplay);
	window.draw(playerTwoDisplay);
	window.draw(playerOne);
	window.draw(playerTwo);
}
