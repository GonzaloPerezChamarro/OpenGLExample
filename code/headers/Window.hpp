#ifndef WINDOW_HEADER
#define WINDOW_HEADER


#include <SFML/Graphics.hpp>


namespace example
{
	class Window
	{
	private:
		sf::Window * window;

		unsigned width;
		unsigned height;

	public:
		Window(const char * title, unsigned width, unsigned height, int flags);
		
		~Window() { delete window; }

	public:
		unsigned get_width() { return width; }
		unsigned get_height() { return height; }


	public:
		void swap_buffers();
		void set_viewport(unsigned w, unsigned h);
		void clear_color(float r, float g, float b, float a);
		void clear_display();
		void active_VSync(bool active);

		bool poll_events(sf::Event & e)
		{
			return window->pollEvent(e);
		}
			   
	};
}
#endif // !WINDOW_HEADER
