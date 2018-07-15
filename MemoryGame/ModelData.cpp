#include "ModelData.h"

namespace memory {

	void ModelData::setSize(const DeckSize& size)
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

	winState ModelData::whoWon() const
	{
		return winner;
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
		CardState deckState = deck.checkCards();
		if (deckState == CardState::matched)
		{
			getPlayer().scorePoint();
		}
		else if (deckState == CardState::unmatched)
		{
			p1Turn = !p1Turn;
		}
		else if (deck.checkWin() && !ended)
		{
			winner = pickWinner();
			ended = true;
		}
	}

	void ModelData::dealDeck()
	{
		deck.set(deckSize);
	}

	winState ModelData::pickWinner()
	{
		if (players[0].getScore() == players[1].getScore())
		{
			return winState::draw;
		}
		else if (players[0].getScore() > players[1].getScore())
		{
			return winState::playerOne;
		}
		else
		{
			return winState::playerTwo;
		}
	}

}
