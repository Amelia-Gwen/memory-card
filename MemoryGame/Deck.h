#ifndef BRUGLESCO_MEMORY_DECK_H
#define BRUGLESCO_MEMORY_DECK_H

#include "Card.h"
#include "Expressions.h"

#include <SFML\Graphics.hpp>

#include <vector>

class Deck
{
public:
	void set(const DeckSize& deckSize);

	CardState checkCards(float x, float y);

	void input(const sf::Vector2f& mousePos);

	void draw(sf::RenderWindow& window);
private:
	sf::Texture cardMap;
	std::vector<Card> deck;

	void positionCards();
};

#endif // !BRUGLESCO_MEMORY_DECK_H
