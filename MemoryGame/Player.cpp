#include "Player.h"

Player::Player(unsigned player) :
	index{ player }
{}

void Player::scorePoint()
{
	++score;
}

unsigned Player::getScore() const
{
	return score;
}

unsigned Player::getIndex() const
{
	return index;
}
