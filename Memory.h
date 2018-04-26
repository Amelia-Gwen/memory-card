#ifndef BRUGLESCO_MEMORY_MEMORY_H
#define BRUGLESCO_MEMORY_MEMORY_H

#include "Expressions.h"
#include "GameScreen.h"
#include "InputHandler.h"
#include "MainMenu.h"

#include <SFML\Graphics.hpp>

class Memory
{
public:
	Memory();

	void run();
private:
	sf::RenderWindow window{ sf::VideoMode(window_width, window_height), "Memory" };
	InputHandler inputHandler;
	MainMenu mainMenu{ inputHandler };
	GameScreen gameScreen{ inputHandler };
	bool playing{ false };
	bool paused{ false };
	DeckSize deckSize{ DeckSize::six };

	void input();

	void update();

	void draw();
};

#endif // !BRUGLESCO_MEMORY_MEMORY_H
