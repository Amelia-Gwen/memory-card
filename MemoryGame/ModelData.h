#ifndef BRUGLESCO_MEMORY_MODELDATA_H
#define BRUGLESCO_MEMORY_MODELDATA_H

#include "Deck.h"
#include "Expressions.h"
#include "Player.h"

class ModelData
{
public:
	bool isMenu() const;

	void setSize(const DeckSize& size);

	std::vector<Card> getDeck() const;

	void play();

	void quit();

	void update();
private:
	bool menu{ true };
	unsigned numPlayers{ 2 };
	std::vector<Player> players;
	Player* activePlayer{ nullptr };
	DeckSize deckSize{ DeckSize::six };
	Deck deck;

	void dealDeck();
};

#endif // !BRUGLESCO_MEMORY_MODELDATA_H
