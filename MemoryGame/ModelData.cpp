#include "ModelData.h"

void ModelData::setSize(const bruglesco::DeckSize& size)
{
	deckSize = size;
}

Player& ModelData::getPlayer()
{
	if (p1Turn)
	{
		return players[0];
	}
	else
	{
		return players[1];
	}
}

std::vector<Card>& ModelData::getDeck()
{
	return deck.getCards();
}

std::vector<unsigned>& ModelData::getFailedCards()
{
	return deck.getFailedCards();
}

std::vector<unsigned>& ModelData::getMatchedCards()
{
	return deck.getMatchedCards();
}

bool ModelData::isMenu() const
{
	return menu;
}

bool ModelData::isOver() const
{
	return ended;
}

bool ModelData::playerOneTurn() const
{
	return p1Turn;
}

void ModelData::resetDeck()
{
	deck.reset();
}

void ModelData::play()
{
	dealDeck();
	menu = false;
}

void ModelData::quit()
{
	players[0].reset();
	players[1].reset();
	deck.clear();
	menu = true;
	p1Turn = true;
	ended = false;
}

void ModelData::update()
{
	bruglesco::CardState deckState = deck.checkCards();
	if (deckState == bruglesco::CardState::matched)
	{
		getPlayer().scorePoint();
	}
	else if (deckState == bruglesco::CardState::unmatched)
	{
		p1Turn = !p1Turn;
	}
	else if (deck.checkWin() && !ended)
	{
		ended = true;
	}
}

void ModelData::dealDeck()
{
	deck.set(deckSize);
}
