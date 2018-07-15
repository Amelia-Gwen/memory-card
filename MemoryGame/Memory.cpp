#include "Memory.h"

namespace memory {

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
		data.update();
		view.update();
	}

	void Memory::draw()
	{
		view.draw();
	}

}