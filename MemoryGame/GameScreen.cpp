#include "GameScreen.h"

GameScreen::GameScreen()
{
	//gameBackground.loadFromFile("");
	pause.setPosition(pause_x, 0);
	pause.setFillColor(sf::Color::Black); // to be removed
	returnToMain.setPosition(reset_x, 0);
	returnToMain.setFillColor(sf::Color::Black); // to be removed
}

bool GameScreen::getDeactivation() const
{
	return quit;
}

void GameScreen::reset()
{
	paused = false;
	quit = false;
	activePlayer = nullptr;
}

void GameScreen::play(const DeckSize& size)
{
	players.clear();
	for (unsigned i = 0; i < numPlayers; ++i)
	{
		players.push_back(Player(i));
	}
	activePlayer = &players[0];
	dealDeck(size);
	// distribute deck
}

void GameScreen::input(const sf::Vector2f& mousePos)
{
	if (pause.getGlobalBounds().contains(mousePos))
	{
		paused = !paused;
	}
	else if (returnToMain.getGlobalBounds().contains(mousePos))
	{
		quit = true;
	}
	deck.input(mousePos);
}

void GameScreen::update()
{
	if (deck.checkCards(activePlayer->getPile().x, activePlayer->getPile().y) == CardState::matched)
	{
		activePlayer->shiftPile();
		// inc score
	}
	else if (deck.checkCards(activePlayer->getPile().x, activePlayer->getPile().y) == CardState::matched)
	{
		// wait before resetting
		// change turns
	}
}

void GameScreen::draw(sf::RenderWindow& window)
{
	window.draw(backgroundSprite);
	window.draw(pause);
	window.draw(returnToMain);
	hud.draw(window);
	deck.draw(window);
}

void GameScreen::dealDeck(const DeckSize& size)
{
	deck.set(size);
}
