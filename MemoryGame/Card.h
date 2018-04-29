#ifndef BRUGLESCO_MEMORY_CARD_H
#define BRUGLESCO_MEMORY_CARD_H

#include <SFML\Graphics.hpp>

class Card
{
public:
	Card(unsigned matchNum);

	bool input(sf::Vector2f mousePos);

	void draw(sf::RenderWindow& window);
private:
	sf::RectangleShape face;
	unsigned matchNum;
	bool faceUp{ false };
};

#endif // !BRUGLESCO_MEMORY_CARD_H
