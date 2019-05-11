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
