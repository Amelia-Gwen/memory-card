#include "Deck.h"

#include <algorithm>

namespace memory {

	void Deck::set(const DeckSize& deckSize)
	{
		deck.clear();
		for (auto i = 0; i < static_cast<unsigned>(deckSize); ++i)
		{
			deck.push_back(Card(i));
			deck.push_back(Card(i));
		}
		std::shuffle(std::begin(deck), std::end(deck), generator);
	}

	void Deck::reset()
	{
		upCards.clear();
		matchedCards.clear();
	}

	CardState Deck::checkCards()
	{
		unsigned count = 0;
		std::vector<unsigned> indices;
		for (auto i = 0; i < deck.size(); ++i)
		{
			if (deck[i].checkState() == CardState::checking)
			{
				++count;
				indices.push_back(i);
			}
		}

		if (count == 2)
		{
			if (deck[indices[0]].getMatch() == deck[indices[1]].getMatch())
			{
				matchedCards = indices;
				deck[indices[0]].match();
				deck[indices[1]].match();
				return CardState::matched;
			}
			else
			{
				upCards = indices;
				deck[indices[0]].reset();
				deck[indices[1]].reset();
				return CardState::unmatched;
			}
		}
		else
		{
			return CardState::checking;
		}
	}

	bool Deck::checkWin() const
	{
		for (auto& card : deck)
		{
			if (card.checkState() != CardState::matched)
			{
				return false;
			}
		}
		return deck.size() > 0;
	}

	std::vector<Card>& Deck::getCards()
	{
		return deck;
	}

	std::vector<unsigned>& Deck::getFailedCards()
	{
		return upCards;
	}

	std::vector<unsigned>& Deck::getMatchedCards()
	{
		return matchedCards;
	}

	void Deck::clear()
	{
		deck.clear();
	}

}
