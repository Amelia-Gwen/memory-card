#ifndef BRUGLESCO_MEMORY_DECK_H
#define BRUGLESCO_MEMORY_DECK_H

#include "Card.h"
#include "Expressions.h"
#include "Player.h"

#include <vector>

class Deck
{
public:
	void set(const bruglesco::DeckSize& deckSize);

	void reset();

	bruglesco::CardState checkCards();

	bool checkWin();

	std::vector<Card>& getCards();

	std::vector<unsigned>& getFailedCards();

	std::vector<unsigned>& getMatchedCards();

	void clear();
private:
	std::vector<Card> deck;
	std::vector<unsigned> upCards;
	std::vector<unsigned> matchedCards;
};

#endif // !BRUGLESCO_MEMORY_DECK_H
