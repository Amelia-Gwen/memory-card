#include "GameScreen.h"

namespace memory {

	GameScreen::GameScreen(ModelData& data, sf::Font& font) :
		data{ data },
		font{ font }
	{
		if (!cardMap.loadFromFile("spritesheet.png"))
		{

		}
		pauseButton.setPosition(pause_x, 0);
		pauseButton.setFillColor(sf::Color(120, 120, 120, 255));
		pauseString.setPosition(pause_x + pause_offset, 0);
		pauseString.setCharacterSize(50);
		pauseString.setFillColor(sf::Color::Black);
		returnToMain.setPosition(reset_x, 0);
		returnToMain.setFillColor(sf::Color(120, 120, 120, 255));
		resetString.setPosition(reset_x + reset_offset, 0);
		resetString.setCharacterSize(50);
		resetString.setFillColor(sf::Color::Black);
		pauseForeground.setFillColor(sf::Color(120, 120, 120, 120));
		endGameForeground.setPosition(win_x, win_y);
		endGameForeground.setFillColor(sf::Color(90, 90, 90, 180));
		winString.setPosition(winstring_x, winstring_y);
		winString.setCharacterSize(250);
		winString.setFillColor(sf::Color::Green);
		playerWinString.setPosition(player_winstring_x, player_winstring_y);
		playerWinString.setCharacterSize(250);
		playerWinString.setFillColor(sf::Color::Green);
		for (unsigned i = 0; i < max_pairs; ++i)
		{
			imageIdentifiers.push_back(i);
		}
	}

	void GameScreen::setGame()
	{
		std::shuffle(std::begin(imageIdentifiers), std::end(imageIdentifiers), generator);
		makeCards();
		positionCards();
	}

	void GameScreen::trackMouse(const sf::Vector2f& mousePos)
	{
		if (pauseButton.getGlobalBounds().contains(mousePos))
		{
			mouseIn = gameMouseIn::pause;
		}
		else if (returnToMain.getGlobalBounds().contains(mousePos))
		{
			mouseIn = gameMouseIn::reset;
		}
		else
		{
			mouseIn = gameMouseIn::none;
		}
	}

	void GameScreen::input(const sf::Vector2f& mousePos)
	{
		if (pauseButton.getGlobalBounds().contains(mousePos))
		{
			if (!data.isOver())
			{
				paused = !paused;
			}
		}
		else if (!paused && returnToMain.getGlobalBounds().contains(mousePos))
		{
			data.quit();
			z_index_indices.clear();
			delay = 0;
			data.resetDeck();
		}
		else if (!paused && delay == 0)
		{
			for (std::pair<std::vector<Card>::iterator, std::vector<sf::RectangleShape>::iterator> card(data.getDeck().begin(), deck.begin());
				card.first != data.getDeck().end() && card.second != deck.end(); ++card.first, ++card.second)
			{
				if (card.second->getGlobalBounds().contains(mousePos))
				{
					card.first->flip();
				}
			}
		}
	}

	void GameScreen::update()
	{
		highlightButtons();
		matchFailDelay();
		moveMatched();
		adjustTexture();
		hud.update();

		if (delay == 1)
		{
			endFailDelay();
		}
		if (delay > 0)
		{
			--delay;
		}

		if (data.isOver())
		{
			if (data.whoWon() == winState::draw)
			{
				winString.setString("Draw");
				playerWinString.setString("");
			}
			else if (data.whoWon() == winState::playerOne)
			{
				winString.setString("Winner");
				playerWinString.setString("Player 1");
			}
			else if (data.whoWon() == winState::playerTwo)
			{
				winString.setString("Winner");
				playerWinString.setString("Player 2");
			}
		}
	}

	void GameScreen::draw(sf::RenderWindow& window)
	{
		window.draw(pauseButton);
		window.draw(pauseString);
		window.draw(returnToMain);
		window.draw(resetString);
		hud.draw(window);
		for (auto i = 0; i < data.getDeck().size(); ++i)
		{
			if (data.getDeck()[i].checkState() != CardState::matched)
			{
				window.draw(deck[i]);
			}
		}
		for (auto i = 0; i < z_index_indices.size(); ++i)
		{
			window.draw(deck[z_index_indices[i]]);
		}

		if (paused)
		{
			window.draw(pauseForeground);
		}

		if (data.isOver())
		{
			window.draw(endGameForeground);
			window.draw(winString);
			window.draw(playerWinString);
		}
	}

	void GameScreen::makeCards()
	{
		deck.clear();
		unsigned k = 0;
		for (auto& card : data.getDeck())
		{
			deck.push_back(sf::RectangleShape(sf::Vector2f(card_width, card_height)));
			deck[k].setTexture(&cardMap);
			deck[k].setTextureRect(sf::IntRect(2048, 0, static_cast<int>(card_width), static_cast<int>(card_height)));
			++k;
		}
	}

	void GameScreen::positionCards()
	{
		unsigned rows = 0;
		for (auto i = 2; i * i <= deck.size(); ++i)
		{
			if (deck.size() % i == 0)
			{
				rows = i;
			}
		}
		unsigned columns = deck.size() / rows;

		float padding_x = (canvas_width - columns * 128.f) / (columns + 1);
		float padding_y = (canvas_height - rows * 128.f) / (rows + 1);
		float x = padding_x;
		float y = padding_y;
		unsigned counter = 1;
		for (auto& card : deck)
		{
			card.setPosition(x, y);
			if (counter < columns)
			{
				++counter;
				x += padding_x + card_width;
			}
			else
			{
				counter = 1;
				x = padding_x;
				y += padding_y + card_height;
			}
		}
	}

	void GameScreen::highlightButtons()
	{
		if (paused || mouseIn == gameMouseIn::pause)
		{
			pauseButton.setFillColor(sf::Color(60, 60, 60, 255));
			pauseString.setFillColor(sf::Color::Red);
		}
		else
		{
			pauseButton.setFillColor(sf::Color(120, 120, 120, 255));
			pauseString.setFillColor(sf::Color::Black);
		}

		if (mouseIn == gameMouseIn::reset)
		{
			returnToMain.setFillColor(sf::Color(60, 60, 60, 255));
			resetString.setFillColor(sf::Color::Red);
		}
		else
		{
			returnToMain.setFillColor(sf::Color(120, 120, 120, 255));
			resetString.setFillColor(sf::Color::Black);
		}
	}

	void GameScreen::matchFailDelay()
	{
		if (delay == 0 && data.getFailedCards().size() == 2)
		{
			delay = 120;
		}
	}

	void GameScreen::endFailDelay()
	{
		data.resetDeck();
	}

	void GameScreen::moveMatched()
	{
		if (data.getMatchedCards().size() == 2)
		{
			float x = player_card_x + player_card_x_offset * data.getPlayer().getScore();
			float y;
			if (data.playerOneTurn())
			{
				y = player_one_card_y;
			}
			else
			{
				y = player_two_card_y;
			}

			for (unsigned i = 0; i < data.getMatchedCards().size(); ++i)
			{
				deck[data.getMatchedCards()[i]].setPosition(x, y);
				z_index_indices.push_back(data.getMatchedCards()[i]);
			}
			data.resetDeck();
		}
	}

	void GameScreen::adjustTexture()
	{
		for (auto i = 0; i < data.getDeck().size(); ++i)
		{
			if (data.getDeck()[i].checkState() == CardState::unmatched)
			{
				deck[i].setTextureRect(sf::IntRect(2048, 0, static_cast<int>(card_width), static_cast<int>(card_height)));
			}
			else
			{
				deck[i].setTextureRect(sf::IntRect(imageIdentifiers[data.getDeck()[i].getMatch()] * 128, 0, static_cast<int>(card_width), static_cast<int>(card_height)));
			}
		}
		for (auto i = 0; i < data.getFailedCards().size(); ++i)
		{
			deck[data.getFailedCards()[i]].setTextureRect(sf::IntRect(imageIdentifiers[data.getDeck()[data.getFailedCards()[i]].getMatch()] * 128, 0, static_cast<int>(card_width), static_cast<int>(card_height)));
		}
	}

}
