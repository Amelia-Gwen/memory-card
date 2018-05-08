#include "GameScreen.h"

GameScreen::GameScreen(ModelData& data) :
	data{ data }
{
	//gameBackground.loadFromFile("");
	pause.setPosition(pause_x, 0);
	pause.setTexture(&gameButtonMap);
	//pause.setTextureRect(sf::IntRect());
	pause.setFillColor(sf::Color::Black); // to be removed
	returnToMain.setPosition(reset_x, 0);
	returnToMain.setTexture(&gameButtonMap);
	//returnToMain.setTextureRect(sf::IntRect());
	returnToMain.setFillColor(sf::Color::Black); // to be removed
}

void GameScreen::setGame()
{
	makeCards();
	positionCards();
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
	else if (!paused)
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
	// remove if not needed
}

void GameScreen::draw(sf::RenderWindow& window)
{
	window.draw(backgroundSprite);
	window.draw(pause);
	window.draw(returnToMain);
	for (std::vector<sf::RectangleShape>::iterator card = deck.begin(); card != deck.end(); ++card)
	{
		window.draw(*card);
	}
}

void GameScreen::makeCards()
{
	unsigned k = 0;
	for (std::vector<Card>::iterator card = data.getDeck().begin(); card != data.getDeck.end(); ++card)
	{
		deck.push_back(sf::RectangleShape(sf::Vector2f(card_width, card_height)));
		deck[k].setTexture(&cardMap);
		//deck[k].setTextureRect(sf::IntRect());
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
