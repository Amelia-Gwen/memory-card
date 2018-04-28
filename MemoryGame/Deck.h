#ifndef BRUGLESCO_MEMORY_DECK_H
#define BRUGLESCO_MEMORY_DECK_H

#include "Card.h"
#include "Expressions.h"

#include <algorithm>
#include <random>
#include <vector>

class Deck
{
public:
	Deck();

	void set(DeckSize deckSize);
private:
	std::vector<Card> deck;

	unsigned translateSize(DeckSize deckSize);
};

#endif // !BRUGLESCO_MEMORY_DECK_H
