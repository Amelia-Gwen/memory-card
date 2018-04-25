#ifndef BRUGLESCO_MEMORY_MEMORY_H
#define BRUGLESCO_MEMORY_MEMORY_H

#include "GameScreen.h"
#include "MainMenu.h"

#include <SFML\Graphics.hpp>

class Memory
{
public:
	Memory();

	void run();
private:
	sf::RenderWindow window;
	MainMenu mainMenu;
	GameScreen gameScreen;
	bool playing;

	void input();

	void update();

	void draw();
};

#endif // !BRUGLESCO_MEMORY_MEMORY_H
