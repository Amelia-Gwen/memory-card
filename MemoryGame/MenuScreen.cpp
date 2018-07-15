#include "MenuScreen.h"

namespace memory {

	MenuScreen::MenuScreen(ModelData& data, GameScreen& game, sf::Font& font) :
		data{ data },
		game{ game },
		font{ font }
	{
		playButton.setPosition(play_button_x, play_button_y);
		playButton.setFillColor(sf::Color(120, 120, 120, 255));
		playString.setPosition(play_button_x + play_string_x_offset, play_button_y + play_string_y_offset);
		playString.setCharacterSize(150);
		playString.setFillColor(sf::Color::Black);

		sixPairs.setPosition(six_button_x, pair_button_y);
		sixPairs.setFillColor(sf::Color(120, 120, 120, 255));
		sixString.setPosition(six_button_x + six_string_x_offset, pair_button_y);
		sixString.setCharacterSize(100);
		sixString.setFillColor(sf::Color::Red);
		pairString[0].setPosition(six_button_x + pair_string_x_offset, pair_button_y + pair_string_y_offset);
		pairString[0].setCharacterSize(100);
		pairString[0].setFillColor(sf::Color::Red);

		eightPairs.setPosition(eight_button_x, pair_button_y);
		eightPairs.setFillColor(sf::Color(120, 120, 120, 255));
		eightString.setPosition(eight_button_x + eight_string_x_offset, pair_button_y);
		eightString.setCharacterSize(100);
		eightString.setFillColor(sf::Color::Black);
		pairString[1].setPosition(eight_button_x + pair_string_x_offset, pair_button_y + pair_string_y_offset);
		pairString[1].setCharacterSize(100);
		pairString[1].setFillColor(sf::Color::Black);

		twelvePairs.setPosition(twelve_button_x, pair_button_y);
		twelvePairs.setFillColor(sf::Color(120, 120, 120, 255));
		twelveString.setPosition(twelve_button_x + twelve_string_x_offset, pair_button_y);
		twelveString.setCharacterSize(100);
		twelveString.setFillColor(sf::Color::Black);
		pairString[2].setPosition(twelve_button_x + pair_string_x_offset, pair_button_y + pair_string_y_offset);
		pairString[2].setCharacterSize(100);
		pairString[2].setFillColor(sf::Color::Black);

		sixteenPairs.setPosition(sixteen_button_x, pair_button_y);
		sixteenPairs.setFillColor(sf::Color(120, 120, 120, 255));
		sixteenString.setPosition(sixteen_button_x + sixteen_string_x_offset, pair_button_y);
		sixteenString.setCharacterSize(100);
		sixteenString.setFillColor(sf::Color::Black);
		pairString[3].setPosition(sixteen_button_x + pair_string_x_offset, pair_button_y + pair_string_y_offset);
		pairString[3].setCharacterSize(100);
		pairString[3].setFillColor(sf::Color::Black);
	}

	void MenuScreen::trackMouse(const sf::Vector2f& mousePos)
	{
		if (playButton.getGlobalBounds().contains(mousePos))
		{
			mouseIn = menuMouseIn::play;
		}
		else if (sixPairs.getGlobalBounds().contains(mousePos))
		{
			mouseIn = menuMouseIn::six;
		}
		else if (eightPairs.getGlobalBounds().contains(mousePos))
		{
			mouseIn = menuMouseIn::eight;
		}
		else if (twelvePairs.getGlobalBounds().contains(mousePos))
		{
			mouseIn = menuMouseIn::twelve;
		}
		else if (sixteenPairs.getGlobalBounds().contains(mousePos))
		{
			mouseIn = menuMouseIn::sixteen;
		}
		else
		{
			mouseIn = menuMouseIn::none;
		}
	}

	void MenuScreen::input(const sf::Vector2f& mousePos)
	{
		if (playButton.getGlobalBounds().contains(mousePos))
		{
			data.setSize(deckSize);
			data.play();
			game.setGame();
			mouseIn = menuMouseIn::none;
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
		// switch to auto range loop?
		for (std::vector<sf::Text>::iterator string = pairString.begin(); string != pairString.end(); ++string)
		{
			window.draw(*string);
		}
	}

	void MenuScreen::highlightButton()
	{
		if (mouseIn == menuMouseIn::play)
		{
			playButton.setFillColor(sf::Color(60, 60, 60, 255));
			playString.setFillColor(sf::Color::Red);
		}
		else
		{
			playButton.setFillColor(sf::Color(120, 120, 120, 255));
			playString.setFillColor(sf::Color::Black);
		}

		if (mouseIn == menuMouseIn::six)
		{
			sixPairs.setFillColor(sf::Color(60, 60, 60, 255));
			sixString.setFillColor(sf::Color::Red);
			pairString[0].setFillColor(sf::Color::Red);
		}
		else if (deckSize == DeckSize::six)
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

		if (mouseIn == menuMouseIn::eight)
		{
			eightPairs.setFillColor(sf::Color(60, 60, 60, 255));
			eightString.setFillColor(sf::Color::Red);
			pairString[1].setFillColor(sf::Color::Red);
		}
		else if (deckSize == DeckSize::eight)
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

		if (mouseIn == menuMouseIn::twelve)
		{
			twelvePairs.setFillColor(sf::Color(60, 60, 60, 255));
			twelveString.setFillColor(sf::Color::Red);
			pairString[2].setFillColor(sf::Color::Red);
		}
		else if (deckSize == DeckSize::twelve)
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

		if (mouseIn == menuMouseIn::sixteen)
		{
			sixteenPairs.setFillColor(sf::Color(60, 60, 60, 255));
			sixteenString.setFillColor(sf::Color::Red);
			pairString[3].setFillColor(sf::Color::Red);
		}
		else if (deckSize == DeckSize::sixteen)
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

}
