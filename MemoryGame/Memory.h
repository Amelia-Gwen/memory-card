#ifndef BRUGLESCO_MEMORY_MEMORY_H
#define BRUGLESCO_MEMORY_MEMORY_H

#include "Expressions.h"
#include "ModelData.h"
#include "Viewport.h"

#include <SFML\Graphics.hpp>

class Memory
{
public:
	void run();
private:
	ModelData data;
	Viewport view{ data };
	bool playing{ true };

	void input();

	void update();

	void draw();
};

#endif // !BRUGLESCO_MEMORY_MEMORY_H
