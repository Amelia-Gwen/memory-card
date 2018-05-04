#include "Player.h"

Player::Player(unsigned player) :
	matchPile{player_card_x, player_card_y + player_card_y_offset * player}
{
}

void Player::shiftPile()
{
	matchPile.x += player_card_x_offset;
}

sf::Vector2f Player::getPile() const
{
	return matchPile;
}
