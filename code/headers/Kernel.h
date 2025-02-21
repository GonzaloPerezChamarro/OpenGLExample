/**
 * @file Kernel.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Class of the kernel base
 * @version 1.0
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef KERNEL_HEADER
#define KERNEL_HEADER


#include <memory>
#include <chrono>

#include "Window.h"
#include "View.h"

namespace example
{
	class Kernel
	{
	private:

		/* Main application window */
		Window window;

		/* Main camera */
		Camera camera;

		/* Scene */
		View view;

		/* Flag that indicates if kernel is running */
		bool running;

	public:
		/**
		 * @brief Constructor
		 * @param title Title name of the window
		 * @param width window's width
		 * @param height window's height
		 */
		Kernel(const char * title, unsigned width, unsigned height);

		/* Starts the kernel */
		void execute();

		/* Renders the scene */
		void render();

	private:
		/* Manages events */
		void handler();
	};
}

#endif // KERNEL_HEADER
