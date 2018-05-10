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
	view.update();
}

void Memory::draw()
{
	view.draw();
}
