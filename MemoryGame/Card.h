#ifndef BRUGLESCO_MEMORY_CARD_H
#define BRUGLESCO_MEMORY_CARD_H

#include <SFML\Graphics.hpp>
class Card
{
public:
	Card(unsigned matchNum);
private:
	sf::RectangleShape face;
	unsigned matchNum;
};

#endif // !BRUGLESCO_MEMORY_CARD_H
