#pragma once

#include <memory>
#include <chrono>

#include "Window.hpp"
#include "View.hpp"

namespace example
{
	class Kernel
	{
	private:
		typedef std::chrono::high_resolution_clock Clock;
		typedef std::chrono::time_point<Clock> Clock_Point;
		typedef std::chrono::duration<double> Time;

	private:

		Clock_Point time;
		Clock_Point last_time;
		Time deltaTime;

		View view;
		Window window;

		bool running;

	public:
		Kernel(const char * title, unsigned width, unsigned height);

		void execute();

	private:

		void handler();
	};
}
