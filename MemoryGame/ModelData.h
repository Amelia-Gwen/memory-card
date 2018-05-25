#ifndef BRUGLESCO_MEMORY_MODELDATA_H
#define BRUGLESCO_MEMORY_MODELDATA_H

#include "Deck.h"
#include "Expressions.h"
#include "Player.h"

class ModelData
{
public:
	void setSize(const bruglesco::DeckSize& size);

	Player& getPlayer();

	std::vector<Card>& getDeck();

	std::vector<unsigned>& getFailedCards();

	std::vector<unsigned>& getMatchedCards();

	bool isMenu() const;

	bool isOver() const;

	bool playerOneTurn() const;

	void resetTurnCards();

	void play();

	void quit();

	void update();
private:
	bool menu{ true };
	std::vector<Player> players{ 1, 2 };
	Deck deck;
	bruglesco::DeckSize deckSize{ bruglesco::DeckSize::six };
	bruglesco::winState winner{ bruglesco::winState::none };
	bool p1Turn{ true };
	bool ended{ false };

	void dealDeck();

	bruglesco::winState pickWinner();
};

#endif // !BRUGLESCO_MEMORY_MODELDATA_H
