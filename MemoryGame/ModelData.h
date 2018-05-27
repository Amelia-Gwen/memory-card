#ifndef BRUGLESCO_MEMORY_MODELDATA_H
#define BRUGLESCO_MEMORY_MODELDATA_H

/// The Model represents the core data for the application.
/// Interface changes should still be compatible with this class.

#include "Deck.h"
#include "Expressions.h"
#include "Player.h"

class ModelData
{
public:
	/// setter to change the size of the game - should only be used outside of normal play and before starting a new game.
	void setSize(const bruglesco::DeckSize& size);

	Player& getPlayer();

	std::vector<Card>& getDeck();

	///returns 2 unsigned ints that represent the indices in the deck of cards
	std::vector<unsigned>& getFailedCards();

	///returns 2 unsigned ints that represent the indices in the deck of cards
	std::vector<unsigned>& getMatchedCards();

	bruglesco::winState whoWon() const;

	bool isMenu() const;

	bool isOver() const;

	bool playerOneTurn() const;

	void resetDeck();

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
