#include "MenuScreen.h"

MenuScreen::MenuScreen(ModelData& data, GameScreen& game, sf::Font& font) :
	data{ data },
	game{ game },
	font{ font }
{
	playButton.setPosition(bruglesco::play_button_x, bruglesco::play_button_y);
	playButton.setFillColor(sf::Color(120, 120, 120, 255));
	playString.setPosition(bruglesco::play_button_x + bruglesco::play_string_x_offset, bruglesco::play_button_y + bruglesco::play_string_y_offset);
	playString.setCharacterSize(150);
	playString.setFillColor(sf::Color::Black);

	sixPairs.setPosition(bruglesco::six_button_x, bruglesco::pair_button_y);
	sixPairs.setFillColor(sf::Color(120, 120, 120, 255));
	sixString.setPosition(bruglesco::six_button_x + bruglesco::six_string_x_offset, bruglesco::pair_button_y);
	sixString.setCharacterSize(100);
	sixString.setFillColor(sf::Color::Red);
	pairString[0].setPosition(bruglesco::six_button_x + bruglesco::pair_string_x_offset, bruglesco::pair_button_y + bruglesco::pair_string_y_offset);
	pairString[0].setCharacterSize(100);
	pairString[0].setFillColor(sf::Color::Red);

	eightPairs.setPosition(bruglesco::eight_button_x, bruglesco::pair_button_y);
	eightPairs.setFillColor(sf::Color(120, 120, 120, 255));
	eightString.setPosition(bruglesco::eight_button_x + bruglesco::eight_string_x_offset, bruglesco::pair_button_y);
	eightString.setCharacterSize(100);
	eightString.setFillColor(sf::Color::Black);
	pairString[1].setPosition(bruglesco::eight_button_x + bruglesco::pair_string_x_offset, bruglesco::pair_button_y + bruglesco::pair_string_y_offset);
	pairString[1].setCharacterSize(100);
	pairString[1].setFillColor(sf::Color::Black);

	twelvePairs.setPosition(bruglesco::twelve_button_x, bruglesco::pair_button_y);
	twelvePairs.setFillColor(sf::Color(120, 120, 120, 255));
	twelveString.setPosition(bruglesco::twelve_button_x + bruglesco::twelve_string_x_offset, bruglesco::pair_button_y);
	twelveString.setCharacterSize(100);
	twelveString.setFillColor(sf::Color::Black);
	pairString[2].setPosition(bruglesco::twelve_button_x + bruglesco::pair_string_x_offset, bruglesco::pair_button_y + bruglesco::pair_string_y_offset);
	pairString[2].setCharacterSize(100);
	pairString[2].setFillColor(sf::Color::Black);

	sixteenPairs.setPosition(bruglesco::sixteen_button_x, bruglesco::pair_button_y);
	sixteenPairs.setFillColor(sf::Color(120, 120, 120, 255));
	sixteenString.setPosition(bruglesco::sixteen_button_x + bruglesco::sixteen_string_x_offset, bruglesco::pair_button_y);
	sixteenString.setCharacterSize(100);
	sixteenString.setFillColor(sf::Color::Black);
	pairString[3].setPosition(bruglesco::sixteen_button_x + bruglesco::pair_string_x_offset, bruglesco::pair_button_y + bruglesco::pair_string_y_offset);
	pairString[3].setCharacterSize(100);
	pairString[3].setFillColor(sf::Color::Black);
}

void MenuScreen::trackMouse(const sf::Vector2f& mousePos)
{
	if (playButton.getGlobalBounds().contains(mousePos))
	{
		mouseIn = bruglesco::menuMouseIn::play;
	}
	else if (sixPairs.getGlobalBounds().contains(mousePos))
	{
		mouseIn = bruglesco::menuMouseIn::six;
	}
	else if (eightPairs.getGlobalBounds().contains(mousePos))
	{
		mouseIn = bruglesco::menuMouseIn::eight;
	}
	else if (twelvePairs.getGlobalBounds().contains(mousePos))
	{
		mouseIn = bruglesco::menuMouseIn::twelve;
	}
	else if (sixteenPairs.getGlobalBounds().contains(mousePos))
	{
		mouseIn = bruglesco::menuMouseIn::sixteen;
	}
	else 
	{
		mouseIn = bruglesco::menuMouseIn::none;
	}
}

void MenuScreen::input(const sf::Vector2f& mousePos)
{
	if (playButton.getGlobalBounds().contains(mousePos))
	{
		data.setSize(deckSize);
		data.play();
		game.setGame();
		mouseIn = bruglesco::menuMouseIn::none;
	}
	else if (sixPairs.getGlobalBounds().contains(mousePos))
	{
		deckSize = bruglesco::DeckSize::six;
		data.setSize(deckSize);
	}
	else if (eightPairs.getGlobalBounds().contains(mousePos))
	{
		deckSize = bruglesco::DeckSize::eight;
		data.setSize(deckSize);
	}
	else if (twelvePairs.getGlobalBounds().contains(mousePos))
	{
		deckSize = bruglesco::DeckSize::twelve;
		data.setSize(deckSize);
	}
	else if (sixteenPairs.getGlobalBounds().contains(mousePos))
	{
		deckSize = bruglesco::DeckSize::sixteen;
		data.setSize(deckSize);
	}
}

void MenuScreen::update()
{
	highlightButton();
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
	for (std::vector<sf::Text>::iterator string = pairString.begin(); string != pairString.end(); ++string)
	{
		window.draw(*string);
	}
}

void MenuScreen::highlightButton()
{
	if (mouseIn == bruglesco::menuMouseIn::play)
	{
		playButton.setFillColor(sf::Color(60, 60, 60, 255));
		playString.setFillColor(sf::Color::Red);
	}
	else
	{
		playButton.setFillColor(sf::Color(120, 120, 120, 255));
		playString.setFillColor(sf::Color::Black);
	}

	if (mouseIn == bruglesco::menuMouseIn::six)
	{
		sixPairs.setFillColor(sf::Color(60, 60, 60, 255));
		sixString.setFillColor(sf::Color::Red);
		pairString[0].setFillColor(sf::Color::Red);
	}
	else if (deckSize == bruglesco::DeckSize::six)
	{
		sixPairs.setFillColor(sf::Color(120, 120, 120, 255));
		sixString.setFillColor(sf::Color::Red);
		pairString[0].setFillColor(sf::Color::Red);
	}
	else
	{
		sixPairs.setFillColor(sf::Color(120, 120, 120, 255));
		sixString.setFillColor(sf::Color::Black);
		pairString[0].setFillColor(sf::Color::Black);
	}

	if (mouseIn == bruglesco::menuMouseIn::eight)
	{
		eightPairs.setFillColor(sf::Color(60, 60, 60, 255));
		eightString.setFillColor(sf::Color::Red);
		pairString[1].setFillColor(sf::Color::Red);
	}
	else if (deckSize == bruglesco::DeckSize::eight)
	{
		eightPairs.setFillColor(sf::Color(120, 120, 120, 255));
		eightString.setFillColor(sf::Color::Red);
		pairString[1].setFillColor(sf::Color::Red);
	}
	else
	{
		eightPairs.setFillColor(sf::Color(120, 120, 120, 255));
		eightString.setFillColor(sf::Color::Black);
		pairString[1].setFillColor(sf::Color::Black);
	}

	if (mouseIn == bruglesco::menuMouseIn::twelve)
	{
		twelvePairs.setFillColor(sf::Color(60, 60, 60, 255));
		twelveString.setFillColor(sf::Color::Red);
		pairString[2].setFillColor(sf::Color::Red);
	}
	else if (deckSize == bruglesco::DeckSize::twelve)
	{
		twelvePairs.setFillColor(sf::Color(120, 120, 120, 255));
		twelveString.setFillColor(sf::Color::Red);
		pairString[2].setFillColor(sf::Color::Red);
	}
	else
	{
		twelvePairs.setFillColor(sf::Color(120, 120, 120, 255));
		twelveString.setFillColor(sf::Color::Black);
		pairString[2].setFillColor(sf::Color::Black);
	}

	if (mouseIn == bruglesco::menuMouseIn::sixteen)
	{
		sixteenPairs.setFillColor(sf::Color(60, 60, 60, 255));
		sixteenString.setFillColor(sf::Color::Red);
		pairString[3].setFillColor(sf::Color::Red);
	}
	else if (deckSize == bruglesco::DeckSize::sixteen)
	{
		sixteenPairs.setFillColor(sf::Color(120, 120, 120, 255));
		sixteenString.setFillColor(sf::Color::Red);
		pairString[3].setFillColor(sf::Color::Red);
	}
	else
	{
		sixteenPairs.setFillColor(sf::Color(120, 120, 120, 255));
		sixteenString.setFillColor(sf::Color::Black);
		pairString[3].setFillColor(sf::Color::Black);
	}
}
