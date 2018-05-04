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

CardState Card::checkState() const
{
	return cardState;
}

unsigned Card::getMatch() const
{
	return matchNum;
}

void Card::match(float x, float y)
{
	cardState = CardState::matched;
	face.setPosition(x, y);
}

void Card::reset()
{
	cardState = CardState::unmatched;
	faceUp = false;
}

void Card::input(const sf::Vector2f& mousePos)
{
	if (!faceUp && face.getGlobalBounds().contains(mousePos))
	{
		cardState = CardState::checking;
		faceUp = true;
	}
}

void Card::draw(sf::RenderWindow & window)
{
	window.draw(face);
}
