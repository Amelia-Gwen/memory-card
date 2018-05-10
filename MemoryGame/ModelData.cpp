#include "ModelData.h"

bool ModelData::isMenu() const
{
	return menu;
}

void ModelData::setSize(const DeckSize & size)
{
	deckSize = size;
}

std::vector<Card>& ModelData::getDeck()
{
	return deck.getCards();
}

std::vector<Player>& ModelData::getPlayers()
{
	return players;
}

void ModelData::play()
{
	players.clear();
	for (unsigned i = 0; i < numPlayers; ++i)
	{
		players.push_back(Player(i));
	}
	activePlayer = &players[0];
	dealDeck();
	menu = false;
}

void ModelData::quit()
{
	activePlayer = nullptr;
	players.clear();
	deck.clear();
	menu = true;
}

void ModelData::update()
{
	if (deck.checkWin())
	{
		if (players[0].getScore() == players[1].getScore())
		{
			// draw
		}
		else if (players[0].getScore() > players[1].getScore())
		{
			// player 1 wins
		}
		else
		{
			// player 2 wins
		}
	}
	else if (deck.checkCards() == CardState::matched)
	{
		// player takes card
		activePlayer->scorePoint();
	}
	else if (deck.checkCards() == CardState::unmatched)
	{
		// wait before resetting
		if (activePlayer->getIndex() < players.size() - 1)
		{
			activePlayer = &players[activePlayer->getIndex() + 1];
		}
		else
		{
			activePlayer = &players[0];
		}
	}
}

void ModelData::dealDeck()
{
	deck.set(deckSize);
}
