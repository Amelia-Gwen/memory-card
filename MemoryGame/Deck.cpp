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
	for (std::vector<Card>::iterator it = deck.begin(); it != deck.end(); ++it)
	{
		it->input(mousePos);
	}
}

void Deck::draw(sf::RenderWindow& window)
{
	for (std::vector<Card>::iterator it = deck.begin(); it != deck.end(); ++it)
	{
		it->draw(window);
	}
}

void Deck::positionCards()
{
	unsigned rows = 0;
	for (unsigned i = 2; i * i < deck.size(); ++i)
	{
		if (deck.size() % i == 0)
		{
			rows = i;
		}
	}
	unsigned x = 0;
	unsigned y = 0;
	for (std::vector<Card>::iterator it = deck.begin(); it != deck.end(); ++it)
	{
		it->setPosition(base_card_x + x * card_x_spacer, base_card_y + y * card_y_spacer);
		if (y < rows - 1)
		{
			++y;
		}
		else
		{
			y = 0;
			++x;
		}
	}
}
