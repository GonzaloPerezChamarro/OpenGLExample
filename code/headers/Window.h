/**
 * @file Window.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase de la ventana de la aplicacion
 * @version 1.0
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef WINDOW_HEADER
#define WINDOW_HEADER


#include <SFML/Graphics.hpp>


namespace example
{
	class Window
	{
	private:
		/* Pointer to SFML window */
		sf::Window * window;

		/* Window's width */
		unsigned width;

		/* Window's height */
		unsigned height;

	public:
		/**
		 * @brief Constructor
		 * @param title Title of the window
		 * @param width Window's width
		 * @param height Window's height
		 * @param flags Flags mask of the window
		 */
		Window(const char * title, unsigned width, unsigned height, int flags);
		
		/* Destructor */
		~Window() { delete window; }

	public:
		unsigned get_width() const { return width; }
		unsigned get_height() const { return height; }

		/* sf::Window::display() */
		void swap_buffers();

		/* Modifies the viewport size */
		void set_viewport(unsigned w, unsigned h);

		/* Clear the window with the received color */
		void clear_color(float r, float g, float b, float a);

		/* Clear the window */
		void clear_display();

		/* Enables/disables the vertical sync */
		void active_VSync(bool active);

		/**
		 * @brief Manages the events of the window
		 * @param e Event
		 * @return True if an event was returned, or false if the event queue was empty
		 */
		bool poll_events(sf::Event & e)
		{
			return window->pollEvent(e);
		}  
	};
}
#endif // !WINDOW_HEADER
