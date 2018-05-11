#include "HUDisplay.h"

HUDisplay::HUDisplay(ModelData& data) :
	data{ data }
{
	font.loadFromFile("{PixelFlag}.ttf");
	playerOneDisplay.setPosition(display_x, player_one_display_y);
	playerOneDisplay.setFillColor(sf::Color(120, 120, 120, 255));
	playerTwoDisplay.setPosition(display_x, player_two_display_y);
	playerTwoDisplay.setFillColor(sf::Color(120, 120, 120, 255));
	playerOne.setPosition(display_x + display_offset, player_one_display_y);
	playerOne.setCharacterSize(50);
	playerOne.setFillColor(sf::Color::Black);
	playerTwo.setPosition(display_x + display_offset, player_two_display_y);
	playerTwo.setCharacterSize(50);
	playerTwo.setFillColor(sf::Color::Black);
}

void HUDisplay::update()
{
	if (data.getPlayers().size() > 1)
	{
		playerOneScore = data.getPlayers()[0].getScore();
		playerTwoScore = data.getPlayers()[1].getScore();
	}
	playerOne.setString("Player One: " + std::to_string(playerOneScore));
	playerTwo.setString("Player Two: " + std::to_string(playerTwoScore));
}

void HUDisplay::draw(sf::RenderWindow& window)
{
	window.draw(playerOneDisplay);
	window.draw(playerTwoDisplay);
	window.draw(playerOne);
	window.draw(playerTwo);
}
