#ifndef KERNEL_HEADER
#define KERNEL_HEADER


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

		Window window;
		Camera camera;
		View view;

		bool running;

	public:
		Kernel(const char * title, unsigned width, unsigned height);

		void execute();

		void render();


	private:

		void handler();
	};
}

#endif // KERNEL_HEADER
