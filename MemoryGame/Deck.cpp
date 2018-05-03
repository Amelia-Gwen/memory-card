#include "Deck.h"

#include <algorithm>

void Deck::set(DeckSize deckSize)
{
	deck.clear();
	unsigned k = 0;
	for (unsigned i = 0; i < static_cast<unsigned>(deckSize); ++i)
	{
		deck.push_back(Card(i));
		deck[k].passTexture(cardMap);
		++k;
		deck.push_back(Card(i));
		deck[k].passTexture(cardMap);
		++k;
	}
	std::shuffle(std::begin(deck), std::end(deck), generator);
	positionCards();
}

void Deck::input(sf::Vector2f mousePos)
{
	for (std::vector<Card>::iterator iterator = deck.begin(); iterator != deck.end(); ++iterator)
	{
		iterator->input(mousePos);
	}
}

void Deck::draw(sf::RenderWindow& window)
{
	for (std::vector<Card>::iterator iterator = deck.begin(); iterator != deck.end(); ++iterator)
	{
		iterator->draw(window);
	}
}

void Deck::positionCards()
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
	for (std::vector<Card>::iterator iterator = deck.begin(); iterator != deck.end(); ++iterator)
	{
		iterator->setPosition(x, y);
		if (counter < columns)
		{
			++counter;
			x += padding_x + 128.f;
		}
		else
		{
			counter = 1;
			x = padding_x;
			y += padding_y + 128.f;
		}
	}
}
