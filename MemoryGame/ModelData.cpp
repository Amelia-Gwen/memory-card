#include "ModelData.h"

bool ModelData::isMenu() const
{
	return menu;
}

void ModelData::setSize(const DeckSize& size)
{
	deckSize = size;
}

void ModelData::resetFail()
{
	deck.resetFail();
}

std::vector<Card>& ModelData::getDeck()
{
	return deck.getCards();
}

std::vector<unsigned>& ModelData::getFailedCards()
{
	return deck.getFailedCards();
}

Player* ModelData::getPlayer()
{
	return activePlayer;
}

bool ModelData::playerOneTurn() const
{
	return p1Turn;
}

void ModelData::play()
{
	dealDeck();
	menu = false;
}

void ModelData::quit()
{
	playerOne.reset();
	playerTwo.reset();
	activePlayer = &playerOne;
	deck.clear();
	menu = true;
	p1Turn = true;
	ended = false;
	winner = winState::none;
}

void ModelData::update()
{
	CardState deckState = deck.checkCards();
	if (deck.checkWin() && !ended)
	{
		if (playerOne.getScore() == playerTwo.getScore())
		{
			ended = true;
			winner = winState::draw;

		}
		else if (playerOne.getScore() > playerTwo.getScore())
		{
			ended = true;
			winner = winState::playerOne;
		}
		else
		{
			ended = true;
			winner = winState::playerTwo;
		}
	}
	else if (deckState == CardState::matched)
	{
		// player takes card
		activePlayer->scorePoint();
	}
	else if (deckState == CardState::unmatched)
	{
		if (p1Turn)
		{
			activePlayer = &playerTwo;
		}
		else
		{
			activePlayer = &playerOne;
		}
		p1Turn = !p1Turn;
	}
}

void ModelData::dealDeck()
{
	deck.set(deckSize);
}
