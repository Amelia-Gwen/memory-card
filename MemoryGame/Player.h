#ifndef BRUGLESCO_MEMORY_PLAYER_H
#define BRUGLESCO_MEMORY_PLAYER_H

#include "Expressions.h"

#include <SFML\Graphics.hpp>

class Player
{
public:
	void scorePoint();

	void reset();

	unsigned getScore() const;
private:
	unsigned score{ 0 };
};

#endif // !BRUGLESCO_MEMORY_PLAYER_H
