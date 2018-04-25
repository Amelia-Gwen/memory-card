#include "Memory.h"

Memory::Memory() :
	playing(false)
{

}

void Memory::run()
{
	while (window.isOpen())
	{
		input();
		update();
		draw();
	}
}
