#ifndef BRUGLESCO_MEMORY_DECK_H
#define BRUGLESCO_MEMORY_DECK_H

#include "Card.h"
#include "Expressions.h"

#include <vector>

class Deck
{
public:
	void set(const DeckSize& deckSize);

	CardState checkCards();

	std::vector<Card>& getCards();

	void clear();
private:
	std::vector<Card> deck;
};

#endif // !BRUGLESCO_MEMORY_DECK_H
