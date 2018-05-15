#include "Card.h"

Card::Card(unsigned matchNum) :
	matchNum{ matchNum }
{}

unsigned Card::getMatch() const
{
	return matchNum;
}

CardState Card::checkState() const
{
	return cardState;
}

void Card::flip()
{
	if (cardState == CardState::unmatched)
	{
		cardState = CardState::checking;
		faceUp = true;
	}
}

void Card::match()
{
	cardState = CardState::matched;
}

void Card::reset()
{
	cardState = CardState::unmatched;
	faceUp = false;
}
