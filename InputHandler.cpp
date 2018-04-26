#include "InputHandler.h"

void InputHandler::play()
{
	m_play = true;
}

void InputHandler::six()
{
	deckSize = DeckSize::six;
}

void InputHandler::eight()
{
	deckSize = DeckSize::eight;
}

void InputHandler::twelve()
{
	deckSize = DeckSize::twelve;
}

void InputHandler::sixteen()
{
	deckSize = DeckSize::sixteen;
}

void InputHandler::pause()
{
	m_paused = true;
}

void InputHandler::resetGameState()
{
	m_reset = true;
}

void InputHandler::switchOff()
{
	m_play = false;
	m_paused = false;
	m_reset = false;
}

bool InputHandler::readPlay() const
{
	return m_play;
}

bool InputHandler::readPause() const
{
	return m_paused;
}

bool InputHandler::readReset() const
{
	return m_reset;
}

DeckSize InputHandler::readSize() const
{
	return deckSize;
}
