#ifndef BRUGLESCO_MEMORY_MODELDATA_H
#define BRUGLESCO_MEMORY_MODELDATA_H

/// The Model represents the core data for the application.
/// Interface changes should still be compatible with this class.

#include "Deck.h"
#include "Expressions.h"
#include "Player.h"

namespace memory {

	class ModelData
	{
	public:
		/// setter to change the size of the game - should only be used outside of normal play and before starting a new game.
		void setSize(const DeckSize& size);

		Player& getPlayer();

		std::vector<Card>& getDeck();

		///returns 2 unsigned ints that represent the indices in the deck of cards
		std::vector<unsigned>& getFailedCards();

		///returns 2 unsigned ints that represent the indices in the deck of cards
		std::vector<unsigned>& getMatchedCards();

		winState whoWon() const;

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
		DeckSize deckSize{ DeckSize::six };
		winState winner{ winState::none };
		bool p1Turn{ true };
		bool ended{ false };

		void dealDeck();

		winState pickWinner() const;
	};

}

#endif // !BRUGLESCO_MEMORY_MODELDATA_H
