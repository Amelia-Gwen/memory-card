#ifndef BRUGLESCO_MEMORY_PLAYER_H
#define BRUGLESCO_MEMORY_PLAYER_H

#include "Expressions.h"

#include <SFML\Graphics.hpp>

class Player
{
public:
	Player(unsigned player);

	void scorePoint();

	unsigned getScore() const;

	unsigned getIndex() const;
private:
	unsigned score{ 0 };
	const unsigned index;
};

#endif // !BRUGLESCO_MEMORY_PLAYER_H
