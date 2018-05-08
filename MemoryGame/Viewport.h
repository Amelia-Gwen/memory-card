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
	GameScreen game{ data };
	MenuScreen menu{ data, game };
};

#endif // !BRUGLESCO_MEMORY_VIEWPORT_H
