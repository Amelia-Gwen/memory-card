#include "GameScreen.h"

GameScreen::GameScreen(InputHandler& inputHandler) :
	m_inputHandler(inputHandler)
{
	//gameBackground.loadFromFile("");
	pause.setPosition(pause_x, 0);
	reset.setPosition(reset_x, 0);
}

void GameScreen::input(sf::Vector2f mousePos)
{
	if (pause.getGlobalBounds().contains(mousePos))
	{
		m_inputHandler.pause();
	}
	else if (reset.getGlobalBounds().contains(mousePos))
	{
		m_inputHandler.resetGameState();
	}
}

void GameScreen::draw(sf::RenderWindow& window)
{
	window.draw(backgroundSprite);
	window.draw(pause);
	window.draw(reset);
	hud.draw(window);
}
