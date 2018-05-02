#include "Card.h"

Card::Card(unsigned matchNum) :
	matchNum(matchNum)
{
	face.setFillColor(sf::Color::Black); // to be removed
}

void Card::setPosition(float x, float y)
{
	face.setPosition(x, y);
}

void Card::passTexture(const sf::Texture& texture)
{
	face.setTexture(&texture);
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
