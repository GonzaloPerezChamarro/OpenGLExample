/**
 * @file View.hpp
 * @author Gonzalo Perez Chamarro
 * @brief Class that represent a game scene
 * @version 1.0
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef VIEW_HEADER
#define VIEW_HEADER

#include "Camera.h"
#include "Skybox.h"
#include "Model.h"
#include "Cube.h"
#include "Light.h"
#include "Framebuffer.h"


#include <vector>
#include <map>

namespace example
{
	class View
	{
	private:
		/* Pointer to main camera */
		Camera* camera;

		/* Pointer to scene skybox */
		Skybox* skybox;
		
		/* Pointer to main scene light */
		Light* light;

		/* Pointer to the postprocess framebuffer */
		Framebuffer* framebuffer;

		/* Flag that indicates if the post process is active*/
		bool postprocess_active = false;

		/* Window's width */
		unsigned width;

		/* Window's height */
		unsigned height;

		/* Map of all models of the scene, sort by name */
		std::map<std::string, std::shared_ptr<Model>> models_map;

		/* Map of all models with transparency of the scene, sort by name */
		std::map<std::string, std::shared_ptr<Model>> tr_models_map;

		/* Camera movement each tick */
		glm::vec2 camera_direction;

	private:
		/* Camera view matrix */
		glm::mat4 model_view_matrix;

		/* Camera projection matrix */
		glm::mat4 projection_matrix;

	public:
		/**
		 * @brief Constructor
		 * @param camera Main camera
		 * @param width Window's height
		 * @param height Window's height
		 */
		View(Camera & camera, unsigned width, unsigned height);

	public:
		/**
		 * @brief Updates the scene state
		 * @param deltaTime Delta time
		 */
		void update(float deltaTime);

		/* Renders the scene*/
		void render();

		/**
		 * @brief Handle scene events
		 * @param e Event
		 */
		void handler(sf::Event& e);

	private:
		/* Creates the scene */
		void create_scene();
	};
}
#endif // !VIEW_HEADER

