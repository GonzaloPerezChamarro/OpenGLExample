/**
 * @file Kernel.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Kernel base de funcionamiento
 * @version 0.1
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */

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

		/**
		 * @brief Ventana de la aplicacion
		 * 
		 */
		Window window;

		/**
		 * @brief Camara principal
		 * 
		 */
		Camera camera;

		/**
		 * @brief Escena 
		 * 
		 */
		View view;


		/**
		 * @brief Booleano que indica si la aplicacion esta corriendo
		 * 
		 */
		bool running;

	public:
		/**
		 * @brief Constructor de Kernel
		 * 
		 * @param title Nombre de titulo de la ventana
		 * @param width ancho de la ventana
		 * @param height alto de la ventana
		 */
		Kernel(const char * title, unsigned width, unsigned height);

		/**
		 * @brief Inicia la aplicacion
		 * 
		 */
		void execute();

		/**
		 * @brief Renderiza la escena
		 * 
		 */
		void render();


	private:
		/**
		 * @brief Gestiona los eventos
		 * 
		 */
		void handler();
	};
}

#endif // KERNEL_HEADER
