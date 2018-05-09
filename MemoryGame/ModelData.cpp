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
	if (deck.checkCards() == CardState::matched)
	{
		// player takes card
		// inc score
	}
	else if (deck.checkCards() == CardState::unmatched)
	{
		// wait before resetting
		// change turns
	}
}

void ModelData::dealDeck()
{
	deck.set(deckSize);
}
