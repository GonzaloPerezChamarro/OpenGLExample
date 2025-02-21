


#include "Kernel.h"
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
		unsigned fps = 60;
		const sf::Time update = sf::seconds(1.f / float(fps));
		sf::Clock timer;

		auto last_time = sf::Time::Zero;
		auto now = timer.getElapsedTime();
		auto deltaTime = now - last_time;

		// Gameflow
		do 
		{
			now = timer.getElapsedTime();

			handler();
			view.update(float(deltaTime.asSeconds()));
			window.clear_display();
			render();

			deltaTime = now - last_time;
			last_time = now;

			window.swap_buffers();
		} 
		while (running);
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
			view.handler(e);

			switch (e.type)
			{
			case sf::Event::Closed:
				running = false;
				break;

			case sf::Event::KeyPressed:
				switch (e.key.code)
				{
				case sf::Keyboard::Escape:
					running = false;
					break;
				}
				break;
			}
		}
	}
}