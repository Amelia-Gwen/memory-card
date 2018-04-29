#include "Deck.h"

#include <algorithm>

void Deck::set(DeckSize deckSize)
{
	deck.clear();
	unsigned size = static_cast<unsigned>(deckSize);
	for (unsigned i = 0; i < size; ++i)
	{
		deck.push_back(Card(i));
		deck.push_back(Card(i));
	}
	std::shuffle(std::begin(deck), std::end(deck), generator);
}

void Deck::input(sf::Vector2f mousePos)
{
	for (unsigned i = 0; i < deck.size(); ++i)
	{
		deck[i].input(mousePos);
	}
}

void Deck::draw(sf::RenderWindow& window)
{
	for (unsigned i = 0; i < deck.size(); ++i)
	{
		deck[i].draw(window);
	}
}
