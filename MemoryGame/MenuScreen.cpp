#include "MenuScreen.h"

MenuScreen::MenuScreen(ModelData& data, GameScreen& game) :
	data{ data },
	game{ game }
{
	//background.loadFromFile("");
	playButton.setPosition(play_button_x, play_button_y);
	playButton.setTexture(&menuMap);
	//playButton.setTextureRect(sf::IntRect());
	playButton.setFillColor(sf::Color::Black); // to be removed
	sixPairs.setPosition(six_button_x, pair_button_y);
	sixPairs.setTexture(&menuMap);
	//sixPairs.setTextureRect(sf::IntRect());
	sixPairs.setFillColor(sf::Color::Black); // to be removed
	eightPairs.setPosition(eight_button_x, pair_button_y);
	eightPairs.setTexture(&menuMap);
	//eightPairs.setTextureRect(sf::IntRect());
	eightPairs.setFillColor(sf::Color::Black); // to be removed
	twelvePairs.setPosition(twelve_button_x, pair_button_y);
	twelvePairs.setTexture(&menuMap);
	//twelvePairs.setTextureRect(sf::IntRect());
	twelvePairs.setFillColor(sf::Color::Black); // to be removed
	sixteenPairs.setPosition(sixteen_button_x, pair_button_y);
	sixteenPairs.setTexture(&menuMap);
	//sixteenPairs.setTextureRect(sf::IntRect());
	sixteenPairs.setFillColor(sf::Color::Black); // to be removed
}

void MenuScreen::input(const sf::Vector2f& mousePos)
{
	if (playButton.getGlobalBounds().contains(mousePos))
	{
		data.play();
		game.setGame();
	}
	else if (sixPairs.getGlobalBounds().contains(mousePos))
	{
		data.setSize(DeckSize::six);
		highlight();
	}
	else if (eightPairs.getGlobalBounds().contains(mousePos))
	{
		data.setSize(DeckSize::eight);
		highlight();
	}
	else if (twelvePairs.getGlobalBounds().contains(mousePos))
	{
		data.setSize(DeckSize::twelve);
		highlight();
	}
	else if (sixteenPairs.getGlobalBounds().contains(mousePos))
	{
		data.setSize(DeckSize::sixteen);
		highlight();
	}
}

void MenuScreen::draw(sf::RenderWindow& window)
{
	window.draw(backgroundSprite);
	window.draw(playButton);
	window.draw(sixPairs);
	window.draw(eightPairs);
	window.draw(twelvePairs);
	window.draw(sixteenPairs);
}

void MenuScreen::highlight()
{
	// move textures
}
