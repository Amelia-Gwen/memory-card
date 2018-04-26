#ifndef BRUGLESCO_MEMORY_INPUTHANDLER_H
#define BRUGLESCO_MEMORY_INPUTHANDLER_H

#include "Expressions.h"

#include <SFML\Graphics.hpp>

class InputHandler
{
public:
	void play();

	void six();

	void eight();

	void twelve();

	void sixteen();

	void pause();

	void resetGameState();

	void switchOff();

	bool readPlay() const;

	DeckSize readSize() const;

	bool readPause() const;

	bool readReset() const;
private:
	bool m_play{ false };
	DeckSize deckSize{ DeckSize::six };
	bool m_paused{ false };
	bool m_reset{ false };
};

#endif // !BRUGLESCO_MEMORY_INPUTHANDLER_H
