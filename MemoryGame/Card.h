#ifndef BRUGLESCO_MEMORY_CARD_H
#define BRUGLESCO_MEMORY_CARD_H

#include "Expressions.h"

#include <SFML\Graphics.hpp>

class Card
{
public:
	Card(unsigned matchNum);

	void setPosition(float x, float y);

	void passTexture(const sf::Texture& texture);

	CardState checkState() const;

	unsigned getMatch() const;

	void match(float x, float y);

	void reset();

	void input(const sf::Vector2f& mousePos);

	void draw(sf::RenderWindow& window);
private:
	sf::RectangleShape face{ sf::Vector2f(card_width, card_height) };
	CardState cardState{ CardState::unmatched };
	unsigned matchNum;
	bool faceUp{ false };
};

#endif // !BRUGLESCO_MEMORY_CARD_H
