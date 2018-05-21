#ifndef BRUGLESCO_MEMORY_PLAYER_H
#define BRUGLESCO_MEMORY_PLAYER_H

#include "Expressions.h"

class Player
{
public:
	Player(unsigned identity);

	void scorePoint();

	void reset();

	unsigned getIdentity() const;

	unsigned getScore() const;
private:
	unsigned identity;
	unsigned score{ 0 };
};

#endif // !BRUGLESCO_MEMORY_PLAYER_H
