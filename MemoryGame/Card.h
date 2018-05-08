#ifndef BRUGLESCO_MEMORY_CARD_H
#define BRUGLESCO_MEMORY_CARD_H

#include "Expressions.h"

#include <SFML\Graphics.hpp>

class Card
{
public:
	Card(unsigned matchNum);

	unsigned getMatch() const;

	CardState checkState();

	void flip();

	void match();

	void reset();
private:
	unsigned matchNum;
	CardState cardState{ CardState::unmatched };
	bool faceUp{ false };
};

#endif // !BRUGLESCO_MEMORY_CARD_H
