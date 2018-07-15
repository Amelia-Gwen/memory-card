#include "Player.h"

namespace memory {

	Player::Player(unsigned identity) :
		identity{ identity }
	{
	}

	void Player::scorePoint()
	{
		++score;
	}

	void Player::reset()
	{
		score = 0;
	}

	unsigned Player::getIdentity() const
	{
		return identity;
	}

	unsigned Player::getScore() const
	{
		return score;
	}

}
