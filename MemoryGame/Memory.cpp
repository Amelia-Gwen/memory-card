#include "Memory.h"

void Memory::run()
{
	while (playing)
	{
		input();
		update();
		draw();
	}
}

void Memory::input()
{
	view.input();
}

void Memory::update()
{
	playing = view.isOpen();
}

void Memory::draw()
{
	view.draw();
}
