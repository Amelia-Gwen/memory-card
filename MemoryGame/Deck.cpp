#include "Deck.h"

Deck::Deck()
{
}

void Deck::set(DeckSize deckSize)
{
	unsigned size = translateSize(deckSize);
	for (unsigned i = 0; i < size; ++i)
	{
		deck.push_back(Card(i));
		deck.push_back(Card(i));
	}
	std::random_shuffle(deck.begin(), deck.end(), generator);
}

unsigned Deck::translateSize(DeckSize deckSize)
{
	switch (deckSize)
	{
	case DeckSize::six:
		return 6;
	case DeckSize::eight:
		return 8;
	case DeckSize::twelve:
		return 12;
	case DeckSize::sixteen:
		return 16;
	default:
		// should not reach. throw error or exception?
		break;
	}
}
