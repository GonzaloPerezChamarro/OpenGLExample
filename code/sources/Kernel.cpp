


#include "Kernel.hpp"
#include <iostream>

using namespace std;

namespace example
{
	
	Kernel::Kernel(const char * title, unsigned width, unsigned height)
		:window(title, width, height, 4)
	{

	}

	void Kernel::execute()
	{
		unsigned fps = 0;
		
		do 
		{
			time = Clock::now();
			++fps;

			if (deltaTime.count() >= 1.0f)
			{
				fps = 0;
			}

			render();
			window.clear_display();

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