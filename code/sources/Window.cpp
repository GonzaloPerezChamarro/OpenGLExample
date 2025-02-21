
#include "Window.h"

#include <cassert>
#include "OpenGL.h"


namespace example
{
	Window::Window(const char * title, unsigned width, unsigned height, int flags)
		:width(width), height(height)
	{
		window = new sf::Window(sf::VideoMode(width, height),title, sf::Style::Titlebar | sf::Style::Close, sf::ContextSettings(32));
		
		// Init Open GL
		if (!init_opengl_extensions()) exit(-1);

		active_VSync(true);

		clear_color(0.f, 0.f, 0.f, 1.f);
		glViewport(0, 0, width, height);

		// Keep the mouse on the window
		window->setMouseCursorGrabbed(true);
		window->setMouseCursorVisible(true);

		// Set the mouse in the middle
		sf::Mouse::setPosition(window->getPosition() + sf::Vector2i(width * 0.5, height * 0.5));
	}

	void Window::swap_buffers()
	{
		window->display();
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

	void Window::active_VSync(bool active)
	{
		window->setVerticalSyncEnabled(active);
	}

}