#include "MenuScreen.h"

MenuScreen::MenuScreen(ModelData& data, GameScreen& game, sf::Font& font) :
	data{ data },
	game{ game },
	font{ font }
{
	playButton.setPosition(play_button_x, play_button_y);
	playButton.setFillColor(sf::Color(120, 120, 120, 255));
	playString.setPosition(play_button_x, play_button_y);
	playString.setCharacterSize(100);
	playString.setFillColor(sf::Color::Black);
	sixPairs.setPosition(six_button_x, pair_button_y);
	sixPairs.setFillColor(sf::Color(120, 120, 120, 255));
	sixString.setPosition(six_button_x, pair_button_y);
	sixString.setCharacterSize(100);
	sixString.setFillColor(sf::Color::Red);
	eightPairs.setPosition(eight_button_x, pair_button_y);
	eightPairs.setFillColor(sf::Color(120, 120, 120, 255));
	eightString.setPosition(eight_button_x, pair_button_y);
	eightString.setCharacterSize(100);
	eightString.setFillColor(sf::Color::Black);
	twelvePairs.setPosition(twelve_button_x, pair_button_y);
	twelvePairs.setFillColor(sf::Color(120, 120, 120, 255));
	twelveString.setPosition(twelve_button_x, pair_button_y);
	twelveString.setCharacterSize(100);
	twelveString.setFillColor(sf::Color::Black);
	sixteenPairs.setPosition(sixteen_button_x, pair_button_y);
	sixteenPairs.setFillColor(sf::Color(120, 120, 120, 255));
	sixteenString.setPosition(sixteen_button_x, pair_button_y);
	sixteenString.setCharacterSize(100);
	sixteenString.setFillColor(sf::Color::Black);
}

void MenuScreen::highlightButton(const sf::Vector2f& mousePos)
{
	if (mouseIn == menuMouseIn::none && playButton.getGlobalBounds().contains(mousePos))
	{
		playButton.setFillColor(sf::Color(60, 60, 60, 255));
		playString.setFillColor(sf::Color::Red);
		mouseIn = menuMouseIn::play;
	}
	else if (mouseIn == menuMouseIn::play && !playButton.getGlobalBounds().contains(mousePos))
	{
		playButton.setFillColor(sf::Color(120, 120, 120, 255));
		playString.setFillColor(sf::Color::Black);
		mouseIn = menuMouseIn::none;
	}
	else if (mouseIn == menuMouseIn::none && sixPairs.getGlobalBounds().contains(mousePos))
	{
		sixPairs.setFillColor(sf::Color(60, 60, 60, 255));
		sixString.setFillColor(sf::Color::Red);
		mouseIn = menuMouseIn::six;
	}
	else if (mouseIn == menuMouseIn::six && !sixPairs.getGlobalBounds().contains(mousePos))
	{
		sixPairs.setFillColor(sf::Color(120, 120, 120, 255));
		mouseIn = menuMouseIn::none;
		if (deckSize != DeckSize::six)
		{
			sixString.setFillColor(sf::Color::Black);
		}
	}
	else if (mouseIn == menuMouseIn::none && eightPairs.getGlobalBounds().contains(mousePos))
	{
		eightPairs.setFillColor(sf::Color(60, 60, 60, 255));
		eightString.setFillColor(sf::Color::Red);
		mouseIn = menuMouseIn::eight;
	}
	else if (mouseIn == menuMouseIn::eight && !eightPairs.getGlobalBounds().contains(mousePos))
	{
		eightPairs.setFillColor(sf::Color(120, 120, 120, 255));
		mouseIn = menuMouseIn::none;
		if (deckSize != DeckSize::eight)
		{
			eightString.setFillColor(sf::Color::Black);
		}
	}
	else if (mouseIn == menuMouseIn::none && twelvePairs.getGlobalBounds().contains(mousePos))
	{
		twelvePairs.setFillColor(sf::Color(60, 60, 60, 255));
		twelveString.setFillColor(sf::Color::Red);
		mouseIn = menuMouseIn::twelve;
	}
	else if (mouseIn == menuMouseIn::twelve && !twelvePairs.getGlobalBounds().contains(mousePos))
	{
		twelvePairs.setFillColor(sf::Color(120, 120, 120, 255));
		mouseIn = menuMouseIn::none;
		if (deckSize != DeckSize::twelve)
		{
			twelveString.setFillColor(sf::Color::Black);
		}
	}
	else if (mouseIn == menuMouseIn::none && sixteenPairs.getGlobalBounds().contains(mousePos))
	{
		sixteenPairs.setFillColor(sf::Color(60, 60, 60, 255));
		sixteenString.setFillColor(sf::Color::Red);
		mouseIn = menuMouseIn::sixteen;
	}
	else if (mouseIn == menuMouseIn::sixteen && !sixteenPairs.getGlobalBounds().contains(mousePos))
	{
		sixteenPairs.setFillColor(sf::Color(120, 120, 120, 255));
		mouseIn = menuMouseIn::none;
		if (deckSize != DeckSize::sixteen)
		{
			sixteenString.setFillColor(sf::Color::Black);
		}
	}
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
		deckSize = DeckSize::six;
		data.setSize(deckSize);
	}
	else if (eightPairs.getGlobalBounds().contains(mousePos))
	{
		deckSize = DeckSize::eight;
		data.setSize(deckSize);
	}
	else if (twelvePairs.getGlobalBounds().contains(mousePos))
	{
		deckSize = DeckSize::twelve;
		data.setSize(deckSize);
	}
	else if (sixteenPairs.getGlobalBounds().contains(mousePos))
	{
		deckSize = DeckSize::sixteen;
		data.setSize(deckSize);
	}
}

void MenuScreen::draw(sf::RenderWindow& window)
{
	window.draw(playButton);
	window.draw(playString);
	window.draw(sixPairs);
	window.draw(sixString);
	window.draw(eightPairs);
	window.draw(eightString);
	window.draw(twelvePairs);
	window.draw(twelveString);
	window.draw(sixteenPairs);
	window.draw(sixteenString);
}
