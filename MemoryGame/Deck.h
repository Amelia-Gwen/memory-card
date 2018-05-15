#ifndef BRUGLESCO_MEMORY_DECK_H
#define BRUGLESCO_MEMORY_DECK_H

#include "Card.h"
#include "Expressions.h"
#include "Player.h"

#include <vector>

class Deck
{
public:
	void set(const DeckSize& deckSize);

	void resetFail();

	CardState checkCards();

	bool checkWin();

	std::vector<Card>& getCards();

	std::vector<unsigned>& getFailedCards();

	void clear();
private:
	std::vector<Card> deck;
	std::vector<unsigned> upCards;
};

#endif // !BRUGLESCO_MEMORY_DECK_H
