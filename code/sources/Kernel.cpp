


#include "Kernel.hpp"
#include <iostream>

using namespace std;

namespace example
{
	
	Kernel::Kernel(const char * title, unsigned width, unsigned height)
		:window(title, width, height, 4),camera(Camera()), view(camera, width,height)
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
			handler();


			view.update(float(deltaTime.count()));

			render();
			window.clear_display();


			deltaTime = Time(time - last_time);
			last_time = time;

		} while (running);
	}

	void Kernel::render()
	{
		view.render();
	}

	void Kernel::handler()
	{

		sf::Event e;
		while (window.poll_events(e))
		{
			switch (e.type)
			{
			case sf::Event::Closed:
				running = false;
			}
		}


	}

}