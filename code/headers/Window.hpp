#pragma once


namespace example
{
	class Window
	{
	public:
		//static const int opengl = SDL_WINDOW_OPENGL;
		//static const int shown = SDL_WINDOW_SHOWN;

	private:
		//SDL_Window * window;

		unsigned width;
		unsigned height;

	public:
		Window(const char * title, unsigned width, unsigned height, int flags);
		
		~Window();

	public:
		unsigned get_width() { return width; }
		unsigned get_height() { return height; }

		//SDL_Window * get_window() { return window; }

	public:
		void swap_buffers();
		void set_viewport(unsigned w, unsigned h);
		void clear_color(float r, float g, float b, float a);
		void clear_display();
		void activeVSync(bool active);

		//int poll_events(SDL_Event & e);

	private:
		void config();


	};
}