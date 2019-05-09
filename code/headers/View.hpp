#pragma once

#include "Camera.hpp"
#include "Skybox.hpp"
#include "Model.hpp"

#include <vector>

namespace example
{
	class View
	{
	private:

		Camera * camera;
		Skybox * skybox;

		unsigned width;
		unsigned height;

		//std::vector<std::shared_ptr<Model>> models;

	public:
		View(Camera & camera, unsigned width, unsigned height);

	public:

		void update(float deltaTime);
		void render();
	};
}
