/**
 * @file View.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase que recoge los elementos de la escena
 * @version 0.1
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once

#include "Camera.hpp"
#include "Skybox.hpp"
#include "Model.hpp"
#include "Cube.hpp"
#include "Light.hpp"
#include "Framebuffer.hpp"


#include <vector>
#include <map>

namespace example
{
	class View
	{
	private:
		/**
		 * @brief Puntero a la camara principal
		 * 
		 */
		Camera * camera;
		/**
		 * @brief Puntero al skybox de la escena
		 * 
		 */
		Skybox * skybox;
		/**
		 * @brief puntero a la luz principal
		 * 
		 */
		Light * light;

		/**
		 * @brief Puntero al Framebuffer de postprocesado
		 * 
		 */
		Framebuffer* framebuffer;

		/**
		 * @brief Indica si el postprocesado esta activo
		 * 
		 */
		bool postprocess_active = false;

		/**
		 * @brief Ancho de la pantalla
		 * 
		 */
		unsigned width;

		/**
		 * @brief alto de la pantalla
		 * 
		 */
		unsigned height;

		/**
		 * @brief Mapa de todos los modelos de la escena ordenados por su nombre
		 * 
		 */
		std::map<std::string, std::shared_ptr<Model>> models_map;

		/**
		 * @brief Mapa de todos los modelos con transparencia de la escena ordenados por su nombre
		 * 
		 */
		std::map<std::string, std::shared_ptr<Model>> tr_models_map;

		/**
		 * @brief Movimiento de la camara en cada frame
		 * 
		 */
		glm::vec2 camera_direction;

	private:
		/**
		 * @brief Matrix de vista de la camara
		 * 
		 */
		glm::mat4 model_view_matrix;

		/**
		 * @brief Matriz de proyeccion de la camara
		 * 
		 */
		glm::mat4 projection_matrix;

	public:
	/**
	 * @brief Constructor de View
	 * 
	 * @param camera Camara principal
	 * @param width Ancho de la ventana
	 * @param height Altoo de la ventana
	 */
		View(Camera & camera, unsigned width, unsigned height);

	public:
		/**
		 * @brief Actualiza el estado de la escena
		 * 
		 * @param deltaTime 
		 */
		void update(float deltaTime);

		/**
		 * @brief Renderiza la escena
		 * 
		 */
		void render();

		/**
		 * @brief Gestiona los eventos relacionados con la escena
		 * 
		 * @param e 
		 */
		void handler(sf::Event & e);

	private:
		/**
		 * @brief Crea la escena
		 * 
		 */
		void create_scene();
	};
}
