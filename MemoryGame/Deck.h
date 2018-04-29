#ifndef BRUGLESCO_MEMORY_DECK_H
#define BRUGLESCO_MEMORY_DECK_H

#include "Card.h"
#include "Expressions.h"

#include <SFML\Graphics.hpp>

#include <vector>

class Deck
{
public:
	void set(DeckSize deckSize);

	void input(sf::Vector2f mousePos);

	void draw(sf::RenderWindow& window);
private:
	sf::Texture cardMap;
	std::vector<Card> deck;
};

#endif // !BRUGLESCO_MEMORY_DECK_H
