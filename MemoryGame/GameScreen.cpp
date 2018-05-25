#include "GameScreen.h"

GameScreen::GameScreen(ModelData& data, sf::Font& font) :
	data{ data },
	font{ font }
{
	if (!cardMap.loadFromFile("spritesheet.png"))
	{
		bruglesco::debuggStream << "you aren't loading your textures"; // remove for release
	}
	pauseButton.setPosition(bruglesco::pause_x, 0);
	pauseButton.setFillColor(sf::Color(120, 120, 120, 255));
	pauseString.setPosition(bruglesco::pause_x + bruglesco::pause_offset, 0);
	pauseString.setCharacterSize(50);
	pauseString.setFillColor(sf::Color::Black);
	returnToMain.setPosition(bruglesco::reset_x, 0);
	returnToMain.setFillColor(sf::Color(120, 120, 120, 255));
	resetString.setPosition(bruglesco::reset_x + bruglesco::reset_offset, 0);
	resetString.setCharacterSize(50);
	resetString.setFillColor(sf::Color::Black);
	pauseForeground.setFillColor(sf::Color(120, 120, 120, 120));
	endGameForeground.setPosition(bruglesco::win_x, bruglesco::win_y);
	endGameForeground.setFillColor(sf::Color(90, 90, 90, 180));
	winString.setPosition(bruglesco::winstring_x, bruglesco::winstring_y);
	winString.setCharacterSize(250);
	winString.setFillColor(sf::Color::Green);
	playerWinString.setPosition(bruglesco::player_winstring_x, bruglesco::player_winstring_y);
	playerWinString.setCharacterSize(250);
	playerWinString.setFillColor(sf::Color::Green);
	for (unsigned i = 0; i < bruglesco::max_pairs; ++i)
	{
		imageIdentifiers.push_back(i);
	}
}

void GameScreen::setGame()
{
	std::shuffle(std::begin(imageIdentifiers), std::end(imageIdentifiers), bruglesco::generator);
	makeCards();
	positionCards();
}

void GameScreen::trackMouse(const sf::Vector2f& mousePos)
{
	if (pauseButton.getGlobalBounds().contains(mousePos))
	{
		mouseIn = bruglesco::gameMouseIn::pause;
	}
	else if (returnToMain.getGlobalBounds().contains(mousePos))
	{
		mouseIn = bruglesco::gameMouseIn::reset;
	}
	else 
	{
		mouseIn = bruglesco::gameMouseIn::none;
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
	highlightCards(); // to be removed
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
		playerWinString.setString("Player " + std::to_string(data.getPlayer().getIdentity()));
	}
}

void GameScreen::draw(sf::RenderWindow& window)
{
	window.draw(pauseButton);
	window.draw(pauseString);
	window.draw(returnToMain);
	window.draw(resetString);
	hud.draw(window);
	for (std::vector<sf::RectangleShape>::iterator card = deck.begin(); card != deck.end(); ++card)
	{
		window.draw(*card);
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
	for (std::vector<Card>::iterator card = data.getDeck().begin(); card != data.getDeck().end(); ++card)
	{
		deck.push_back(sf::RectangleShape(sf::Vector2f(bruglesco::card_width, bruglesco::card_height)));
		deck[k].setTexture(&cardMap);
		deck[k].setTextureRect(sf::IntRect(2048, 0, static_cast<int>(bruglesco::card_width), static_cast<int>(bruglesco::card_height)));
		deck[k].setFillColor(sf::Color::White);
		++k;
	}
}

void GameScreen::positionCards()
{
	unsigned rows = 0;
	for (unsigned i = 2; i * i <= deck.size(); ++i)
	{
		if (deck.size() % i == 0)
		{
			rows = i;
		}
	}
	unsigned columns = deck.size() / rows;

	double padding_x = (bruglesco::canvas_width - columns * 128.f) / (columns + 1);
	double padding_y = (bruglesco::canvas_height - rows * 128.f) / (rows + 1);
	double x = padding_x;
	double y = padding_y;
	unsigned counter = 1;
	for (std::vector<sf::RectangleShape>::iterator card = deck.begin(); card != deck.end(); ++card)
	{
		card->setPosition(x, y);
		if (counter < columns)
		{
			++counter;
			x += padding_x + bruglesco::card_width;
		}
		else
		{
			counter = 1;
			x = padding_x;
			y += padding_y + bruglesco::card_height;
		}
	}
}

void GameScreen::highlightButtons()
{
	if (paused || mouseIn == bruglesco::gameMouseIn::pause)
	{
		pauseButton.setFillColor(sf::Color(60, 60, 60, 255));
		pauseString.setFillColor(sf::Color::Red);
	}
	else
	{
		pauseButton.setFillColor(sf::Color(120, 120, 120, 255));
		pauseString.setFillColor(sf::Color::Black);
	}

	if (mouseIn == bruglesco::gameMouseIn::reset)
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
		delay = 300;
	}
}

void GameScreen::endFailDelay()
{
	data.resetTurnCards();
}

void GameScreen::moveMatched()
{
	if (data.getMatchedCards().size() == 2)
	{
		float x = bruglesco::player_card_x + bruglesco::player_card_x_offset * data.getPlayer().getScore();
		float y;
		if (data.playerOneTurn())
		{
			y = bruglesco::player_one_card_y;
		}
		else
		{
			y = bruglesco::player_two_card_y;
		}

		for (unsigned i = 0; i < data.getMatchedCards().size(); ++i)
		{
			deck[data.getMatchedCards()[i]].setPosition(x, y);
		}
		data.resetTurnCards();
	}
}

void GameScreen::highlightCards()
{
	for (unsigned i = 0; i < data.getDeck().size(); ++i)
	{
		if (data.getDeck()[i].checkState() == bruglesco::CardState::unmatched)
		{
			deck[i].setTextureRect(sf::IntRect(2048, 0, static_cast<int>(bruglesco::card_width), static_cast<int>(bruglesco::card_height)));
		}
		else
		{
			deck[i].setTextureRect(sf::IntRect(imageIdentifiers[data.getDeck()[i].getMatch()] * 128, 0, static_cast<int>(bruglesco::card_width), static_cast<int>(bruglesco::card_height)));
		}
	}
	for (unsigned i = 0; i < data.getFailedCards().size(); ++i)
	{
		deck[data.getFailedCards()[i]].setTextureRect(sf::IntRect(imageIdentifiers[data.getDeck()[data.getFailedCards()[i]].getMatch()] * 128, 0, static_cast<int>(bruglesco::card_width), static_cast<int>(bruglesco::card_height)));
	}
}
