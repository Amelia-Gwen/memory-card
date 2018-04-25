#include "MainMenu.h"

MainMenu::MainMenu()
{
	playButton.setPosition(play_button_x, play_button_y);
	sixPairs.setPosition(six_button_x, pair_button_y);
	eightPairs.setPosition(eight_button_x, pair_button_y);
	twelvePairs.setPosition(twelve_button_x, pair_button_y);
	sixteenPairs.setPosition(sixteen_button_x, pair_button_y);
}

void MainMenu::draw(sf::RenderWindow& window)
{
	window.draw(playButton);
	window.draw(sixPairs);
	window.draw(eightPairs);
	window.draw(twelvePairs);
	window.draw(sixteenPairs);
}
