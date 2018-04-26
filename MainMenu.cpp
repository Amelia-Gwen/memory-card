#include "MainMenu.h"

MainMenu::MainMenu(InputHandler& inputHandler) :
	m_inputHandler(inputHandler)
{
	//background.loadFromFile("");
	playButton.setPosition(play_button_x, play_button_y);
	sixPairs.setPosition(six_button_x, pair_button_y);
	eightPairs.setPosition(eight_button_x, pair_button_y);
	twelvePairs.setPosition(twelve_button_x, pair_button_y);
	sixteenPairs.setPosition(sixteen_button_x, pair_button_y);
}

void MainMenu::input(sf::Vector2f mousePos)
{
	if (playButton.getGlobalBounds().contains(mousePos))
	{
		m_inputHandler.play();
	}
	else if (sixPairs.getGlobalBounds().contains(mousePos))
	{
		m_inputHandler.six();
	}
	else if (eightPairs.getGlobalBounds().contains(mousePos))
	{
		m_inputHandler.eight();
	}
	else if (twelvePairs.getGlobalBounds().contains(mousePos))
	{
		m_inputHandler.twelve();
	}
	else if (sixteenPairs.getGlobalBounds().contains(mousePos))
	{
		m_inputHandler.sixteen();
	}
}

void MainMenu::draw(sf::RenderWindow& window)
{
	window.draw(backgroundSprite);
	window.draw(playButton);
	window.draw(sixPairs);
	window.draw(eightPairs);
	window.draw(twelvePairs);
	window.draw(sixteenPairs);
}
