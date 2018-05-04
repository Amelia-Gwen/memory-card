#ifndef BRUGLESCO_MEMORY_PLAYER_H
#define BRUGLESCO_MEMORY_PLAYER_H

#include "Expressions.h"

#include <SFML\Graphics.hpp>

class Player
{
public:
	Player(unsigned player);

	void shiftPile();

	sf::Vector2f getPile() const;
private:
	sf::Vector2f matchPile;
};

#endif // !BRUGLESCO_MEMORY_PLAYER_H
