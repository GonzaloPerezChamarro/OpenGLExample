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

		Camera * camera;
		Skybox * skybox;
		Cube * cube;
		Light * light;
		Framebuffer* framebuffer;

		bool postprocess_active = false;

		unsigned width;
		unsigned height;

		std::map<std::string, std::shared_ptr<Model>> models_map;

		glm::vec2 camera_direction;

	private:
		glm::mat4 model_view_matrix;
		glm::mat4 projection_matrix;

	public:
		View(Camera & camera, unsigned width, unsigned height);

	public:

		void update(float deltaTime);
		void render();

		void handler(sf::Event & e);

	private:

		void create_scene();
	};
}
