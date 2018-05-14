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
}

void GameScreen::setGame()
{
	makeCards();
	positionCards();
}

void GameScreen::highlightButton(const sf::Vector2f& mousePos)
{
	if (mouseIn == gameMouseIn::none && pause.getGlobalBounds().contains(mousePos))
	{
		pause.setFillColor(sf::Color(60, 60, 60, 255));
		pauseString.setFillColor(sf::Color::Red);
		mouseIn = gameMouseIn::pause;
	}
	else if (mouseIn == gameMouseIn::pause && !pause.getGlobalBounds().contains(mousePos))
	{
		pause.setFillColor(sf::Color(120, 120, 120, 255));
		pauseString.setFillColor(sf::Color::Black);
		mouseIn = gameMouseIn::none;
	}
	else if (mouseIn == gameMouseIn::none && returnToMain.getGlobalBounds().contains(mousePos))
	{
		returnToMain.setFillColor(sf::Color(60, 60, 60, 255));
		resetString.setFillColor(sf::Color::Red);
		mouseIn = gameMouseIn::reset;
	}
	else if (mouseIn == gameMouseIn::reset && !returnToMain.getGlobalBounds().contains(mousePos))
	{
		returnToMain.setFillColor(sf::Color(120, 120, 120, 255));
		resetString.setFillColor(sf::Color::Black);
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
	hud.update();
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
