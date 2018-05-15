#include "Deck.h"

#include <algorithm>

void Deck::set(const DeckSize& deckSize)
{
	deck.clear();
	unsigned k = 0;
	for (unsigned i = 0; i < static_cast<unsigned>(deckSize); ++i)
	{
		deck.push_back(Card(i));
		++k;
		deck.push_back(Card(i));
		++k;
	}
	std::shuffle(std::begin(deck), std::end(deck), generator);
}

void Deck::resetFail()
{
	upCards.clear();
}

CardState Deck::checkCards()
{
	unsigned count = 0;
	std::vector<Card*> cards;
	std::vector<unsigned> indeces;
	for (unsigned i = 0; i < deck.size(); ++i)
	{
		if (deck[i].checkState() == CardState::checking)
		{
			++count;
			cards.push_back(&deck[i]);
			indeces.push_back(i);
		}
	}

	if (count == 2)
	{
		if (cards[0]->getMatch() == cards[1]->getMatch())
		{
			cards[0]->match();
			cards[1]->match();
			return CardState::matched;
		}
		else
		{
			upCards = indeces;
			cards[0]->reset();
			cards[1]->reset();
			return CardState::unmatched;
		}
	}
	else
	{
		return CardState::checking;
	}
}

bool Deck::checkWin()
{
	for (std::vector<Card>::iterator card = deck.begin(); card != deck.end(); ++card)
	{
		if (card->checkState() != CardState::matched)
		{
			return false;
		}
	}
	return true;
}

std::vector<Card>& Deck::getCards()
{
	return deck;
}

std::vector<unsigned>& Deck::getFailedCards()
{
	return upCards;
}

void Deck::clear()
{
	deck.clear();
}
