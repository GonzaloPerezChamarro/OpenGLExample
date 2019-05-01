


#include "Kernel.hpp"
#include <iostream>

using namespace std;

namespace example
{
	
	Kernel::Kernel(const char * title, unsigned width, unsigned height)
		:window(title, width, height, 4), view(nullptr, width, height)
	{

	}

	void Kernel::execute()
	{
		int frames = 0;

		do 
		{
			time = Clock::now();
			++frames;

			if (deltaTime.count() >= 1.0f)
			{
				frames = 0;
			}

			handler();

			deltaTime = Time(time - last_time);
			last_time = time;

		} while (running);
	}

	void Kernel::handler()
	{
		/*
		SDL_Event e;
		while (window.poll_events(e))
		{
			view.input(e);

			switch (e.type)
			{
			case SDL_KEYDOWN:
				if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					running = false;
				break;
			case SDL_QUIT:
				running = false;
				break;
			}
		}
		*/
	}

}