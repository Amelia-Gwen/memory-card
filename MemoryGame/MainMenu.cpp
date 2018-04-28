#include "MainMenu.h"

MainMenu::MainMenu()
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
		// send message to gamescreen - include deckSize
	}
	else if (sixPairs.getGlobalBounds().contains(mousePos))
	{
		deckSize = DeckSize::six;
		highlightPair();
	}
	else if (eightPairs.getGlobalBounds().contains(mousePos))
	{
		deckSize = DeckSize::eight;
		highlightPair();
	}
	else if (twelvePairs.getGlobalBounds().contains(mousePos))
	{
		deckSize = DeckSize::twelve;
		highlightPair();
	}
	else if (sixteenPairs.getGlobalBounds().contains(mousePos))
	{
		deckSize = DeckSize::sixteen;
		highlightPair();
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

void MainMenu::highlightPair()
{
	// move textureRects around
}
