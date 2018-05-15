#include "Player.h"

void Player::scorePoint()
{
	++score;
}

void Player::reset()
{
	score = 0;
}

unsigned Player::getScore() const
{
	return score;
}
