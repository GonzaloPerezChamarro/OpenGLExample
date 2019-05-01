
#include "Window.hpp"
#include "glad/glad.h"

#include <cassert>


namespace example
{
	Window::Window(const char * title, unsigned width, unsigned height, int flags)
		:width(width), height(height)
	{
		config();
		/*
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 4);
	
		SDL_GLContext context = SDL_GL_CreateContext(window);
		*/
		activeVSync(true);

		clear_color(0.f, 0.f, 0.f, 1.f);
		glViewport(0, 0, width, height);
	}
	Window::~Window()
	{
		//SDL_DestroyWindow(window);
	}
	void Window::swap_buffers()
	{
	}
	void Window::set_viewport(unsigned w, unsigned h)
	{
		width = w;
		height = h;
	}

	void Window::clear_color(float r, float g, float b, float a)
	{
		glClearColor(r, g, b, a);
	}

	void Window::clear_display()
	{
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	}

	void Window::activeVSync(bool active)
	{
		//SDL_GL_SetSwapInterval(active);
	}

	/*
	int Window::poll_events(SDL_Event & e)
	{
		return SDL_PollEvent(&e);
	}
	*/
	void Window::config()
	{
		//assert(!SDL_VideoInit(nullptr));

		//assert(!SDL_GL_LoadLibrary(nullptr));

		//assert(!SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1));

		//assert(!SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3));
		//assert(!SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3));

		//assert(!SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1));

		//assert(!SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8));
		//assert(!SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8));
		//assert(!SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8));
		//assert(!SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8));

		//assert(!SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32));

		//assert(!SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24));
	}
}