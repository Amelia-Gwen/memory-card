#include "Player.h"

Player::Player(unsigned player) :
	turn{ player }
{}

void Player::scorePoint()
{
	++score;
}

unsigned Player::getScore() const
{
	return score;
}

unsigned Player::getTurn() const
{
	return turn;
}
