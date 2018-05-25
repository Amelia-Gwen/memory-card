#ifndef BRUGLESCO_MEMORY_CARD_H
#define BRUGLESCO_MEMORY_CARD_H

#include "Expressions.h"

class Card
{
public:
	Card(unsigned matchNum);

	unsigned getMatch() const;

	bruglesco::CardState checkState() const;

	void flip();

	void match();

	void reset();
private:
	unsigned matchNum;
	bruglesco::CardState cardState{ bruglesco::CardState::unmatched };
	bool faceUp{ false };
};

#endif // !BRUGLESCO_MEMORY_CARD_H
