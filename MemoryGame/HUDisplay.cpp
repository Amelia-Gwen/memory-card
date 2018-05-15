#include "HUDisplay.h"

HUDisplay::HUDisplay(ModelData& data, sf::Font& font) :
	data{ data },
	font{ font }
{
	playerOneDisplay.setPosition(display_x, player_one_display_y);
	playerOneDisplay.setFillColor(sf::Color(120, 120, 120, 255));
	playerTwoDisplay.setPosition(display_x, player_two_display_y);
	playerTwoDisplay.setFillColor(sf::Color(120, 120, 120, 255));
	playerOne.setPosition(display_x + display_offset, player_one_display_y);
	playerOne.setCharacterSize(50);
	playerOne.setFillColor(sf::Color::Red);
	playerTwo.setPosition(display_x + display_offset, player_two_display_y);
	playerTwo.setCharacterSize(50);
	playerTwo.setFillColor(sf::Color::Black);
}

void HUDisplay::update()
{
	if (data.playerOneTurn())
	{
		playerOneScore = data.getPlayer()->getScore();
		playerOne.setString("Player One: " + std::to_string(playerOneScore));
		playerOne.setFillColor(sf::Color::Red);
		playerTwo.setFillColor(sf::Color::Black);
	}
	else
	{
		playerTwoScore = data.getPlayer()->getScore();
		playerTwo.setString("Player Two: " + std::to_string(playerTwoScore));
		playerOne.setFillColor(sf::Color::Black);
		playerTwo.setFillColor(sf::Color::Red);
	}
}

void HUDisplay::draw(sf::RenderWindow& window)
{
	window.draw(playerOneDisplay);
	window.draw(playerOne);
	window.draw(playerTwoDisplay);
	window.draw(playerTwo);
}
