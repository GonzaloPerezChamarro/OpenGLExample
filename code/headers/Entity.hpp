#pragma once

#include "Transform.hpp"


namespace example
{
	class Entity
	{
	private:

		Transform transform;

	public:
		Entity();

		void update(float deltaTime);
		void render();
	};
}
