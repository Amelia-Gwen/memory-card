#include "GameScreen.h"

GameScreen::GameScreen(ModelData& data, sf::Font& font) :
	data{ data },
	font{ font }
{
	pause.setPosition(pause_x, 0);
	pause.setFillColor(sf::Color(120, 120, 120, 255));
	pauseString.setPosition(pause_x + pause_offset, 0);
	pauseString.setCharacterSize(50);
	pauseString.setFillColor(sf::Color::Black);
	returnToMain.setPosition(reset_x, 0);
	returnToMain.setFillColor(sf::Color(120, 120, 120, 255));
	resetString.setPosition(reset_x + reset_offset, 0);
	resetString.setCharacterSize(50);
	resetString.setFillColor(sf::Color::Black);
	pauseForeground.setFillColor(sf::Color(120, 120, 120, 120));
}

void GameScreen::setGame()
{
	makeCards();
	positionCards();
}

void GameScreen::trackMouse(const sf::Vector2f& mousePos)
{
	if (pause.getGlobalBounds().contains(mousePos))
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
	if (pause.getGlobalBounds().contains(mousePos))
	{
		paused = !paused;
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
}

void GameScreen::draw(sf::RenderWindow& window)
{
	window.draw(pause);
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
}

void GameScreen::makeCards()
{
	deck.clear();
	unsigned k = 0;
	for (std::vector<Card>::iterator card = data.getDeck().begin(); card != data.getDeck().end(); ++card)
	{
		deck.push_back(sf::RectangleShape(sf::Vector2f(card_width, card_height)));
		deck[k].setTexture(&cardMap);
		//deck[k].setTextureRect(sf::IntRect());
		deck[k].setFillColor(sf::Color::Black); // to be removed
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

	float padding_x = (canvas_width - columns * 128.f) / (columns + 1);
	float padding_y = (canvas_height - rows * 128.f) / (rows + 1);
	float x = padding_x;
	float y = padding_y;
	unsigned counter = 1;
	for (std::vector<sf::RectangleShape>::iterator card = deck.begin(); card != deck.end(); ++card)
	{
		card->setPosition(x, y);
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
		pause.setFillColor(sf::Color(60, 60, 60, 255));
		pauseString.setFillColor(sf::Color::Red);
	}
	else
	{
		pause.setFillColor(sf::Color(120, 120, 120, 255));
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
		delay = 800;
	}
}

void GameScreen::endFailDelay()
{
	data.resetFail();
}

void GameScreen::highlightCards()
{
	for (unsigned i = 0; i < data.getDeck().size(); ++i)
	{
		if (data.getDeck()[i].checkState() == CardState::unmatched)
		{
			deck[i].setFillColor(sf::Color::Black);
		}
		else
		{
			deck[i].setFillColor(sf::Color::Green);
		}
	}
	for (unsigned i = 0; i < data.getFailedCards().size(); ++i)
	{
		deck[data.getFailedCards()[i]].setFillColor(sf::Color::Green);
	}
}
