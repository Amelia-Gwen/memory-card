#ifndef BRUGLESCO_MEMORY_DECK_H
#define BRUGLESCO_MEMORY_DECK_H

#include "Card.h"
#include "Expressions.h"

#include <vector>

namespace memory {

	class Deck
	{
	public:
		void set(const DeckSize& deckSize);

		void reset();

		CardState checkCards();

		bool checkWin() const;

		std::vector<Card>& getCards();

		std::vector<unsigned>& getFailedCards();

		std::vector<unsigned>& getMatchedCards();

		void clear();
	private:
		std::vector<Card> deck;
		std::vector<unsigned> upCards;
		std::vector<unsigned> matchedCards;
	};

}

#endif // !BRUGLESCO_MEMORY_DECK_H
