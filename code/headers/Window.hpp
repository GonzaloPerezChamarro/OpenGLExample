/**
 * @file Window.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase de la ventana de la aplicacion
 * @version 0.1
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2019
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
		/**
		 * @brief Ventana de SFML
		 * 
		 */
		sf::Window * window;

		/**
		 * @brief Ancho de la ventana
		 * 
		 */
		unsigned width;

		/**
		 * @brief Alto de la ventana
		 * 
		 */
		unsigned height;

	public:
		/**
		 * @brief Constructor de Window
		 * 
		 * @param title Titulo de la ventana
		 * @param width ancho de la ventana
		 * @param height alto de la ventana
		 * @param flags flags de la ventana
		 */
		Window(const char * title, unsigned width, unsigned height, int flags);
		
		/**
		 * @brief Destructor de Window
		 * 
		 */
		~Window() { delete window; }

	public:
		unsigned get_width() { return width; }
		unsigned get_height() { return height; }


	public:
		/**
		 * @brief sf::Window::display()
		 * 
		 */
		void swap_buffers();

		/**
		 * @brief Modifica el valor del tamaño de viewport 
		 * 
		 * @param w 
		 * @param h 
		 */
		void set_viewport(unsigned w, unsigned h);

		/**
		 * @brief Limpia la pantalla con el color recibido
		 * 
		 * @param r 
		 * @param g 
		 * @param b 
		 * @param a 
		 */
		void clear_color(float r, float g, float b, float a);

		/**
		 * @brief Limpia la pantalla
		 * 
		 */
		void clear_display();

		/**
		 * @brief Activa/desactiva la sincronizacion vertical
		 * 
		 * @param active 
		 */
		void active_VSync(bool active);

		/**
		 * @brief Gestiona os eventos de ventana de sfml
		 * 
		 * @param e 
		 * @return true 
		 * @return false 
		 */
		bool poll_events(sf::Event & e)
		{
			return window->pollEvent(e);
		}
			   
	};
}
#endif // !WINDOW_HEADER
