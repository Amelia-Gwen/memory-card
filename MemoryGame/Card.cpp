#include "Card.h"

Card::Card(unsigned matchNum) :
	matchNum{ matchNum }
{}

unsigned Card::getMatch() const
{
	return matchNum;
}

bruglesco::CardState Card::checkState() const
{
	return cardState;
}

void Card::flip()
{
	if (cardState == bruglesco::CardState::unmatched)
	{
		cardState = bruglesco::CardState::checking;
		faceUp = true;
	}
}

void Card::match()
{
	cardState = bruglesco::CardState::matched;
}

void Card::reset()
{
	cardState = bruglesco::CardState::unmatched;
	faceUp = false;
}
