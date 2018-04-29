#include "Card.h"

Card::Card(unsigned matchNum) :
	matchNum(matchNum)
{}

bool Card::input(sf::Vector2f mousePos)
{
	if (!faceUp && face.getGlobalBounds().contains(mousePos))
	{
		// flip
	}
	else { return false; }
}

void Card::draw(sf::RenderWindow & window)
{
	window.draw(face);
}
