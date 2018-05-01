#include "Card.h"

Card::Card(unsigned matchNum) :
	matchNum(matchNum)
{
	face.setFillColor(sf::Color::Black); // to be removed
}

void Card::input(sf::Vector2f mousePos)
{
	if (!faceUp && face.getGlobalBounds().contains(mousePos))
	{
		// flip
	}
}

void Card::draw(sf::RenderWindow & window)
{
	window.draw(face);
}
