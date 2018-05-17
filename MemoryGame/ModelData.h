#ifndef BRUGLESCO_MEMORY_MODELDATA_H
#define BRUGLESCO_MEMORY_MODELDATA_H

#include "Deck.h"
#include "Expressions.h"
#include "Player.h"

class ModelData
{
public:
	bool isMenu() const;

	bool isOver() const;

	void setSize(const DeckSize& size);

	void resetTurnCards();

	std::vector<Card>& getDeck();

	std::vector<unsigned>& getFailedCards();

	std::vector<unsigned>& getMatchedCards();

	Player* getPlayer();

	bool playerOneTurn() const;

	void play();

	void quit();

	void update();
private:
	bool menu{ true };
	unsigned numPlayers{ 2 };
	Player playerOne{ 1 };
	Player playerTwo{ 2 };
	Player* activePlayer{ &playerOne };
	Deck deck;
	DeckSize deckSize{ DeckSize::six };
	winState winner{ winState::none };
	bool p1Turn{ true };
	bool ended{ false };

	void dealDeck();
};

#endif // !BRUGLESCO_MEMORY_MODELDATA_H
