#ifndef BRUGLESCO_MEMORY_VIEWPORT_H
#define BRUGLESCO_MEMORY_VIEWPORT_H

#include "Expressions.h"
#include "GameScreen.h"
#include "MenuScreen.h"
#include "ModelData.h"

#include <SFML\Graphics.hpp>

class Viewport
{
public:
	Viewport(ModelData& data);

	bool isOpen() const;

	void input();

	void update();

	void draw();
private:
	sf::RenderWindow window{ sf::VideoMode(screen_width, screen_height), "Memory" };
	ModelData& data;
	sf::Font font;
	GameScreen game{ data, font };
	MenuScreen menu{ data, game, font };
	sf::RectangleShape background{ sf::Vector2f(static_cast<float>(screen_width), static_cast<float>(screen_height)) };
};

#endif // !BRUGLESCO_MEMORY_VIEWPORT_H
