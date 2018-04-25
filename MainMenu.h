#ifndef BRUGLESCO_MEMORY_MAINMENU_H
#define BRUGLESCO_MEMORY_MAINMENU_H

#include <SFML\Graphics.hpp>

class MainMenu
{
public:
	MainMenu();
private:
	sf::RectangleShape playButton;
	sf::RectangleShape sixPairs;
	sf::RectangleShape eightPairs;
	sf::RectangleShape twelvePairs;
	sf::RectangleShape sixteenPairs;
};

#endif // !BRUGLESCO_MEMORY_MAINMENU_H
