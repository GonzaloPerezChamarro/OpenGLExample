/**
 * @file Light.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class that represents a light object
 * @version 1.0
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef LIGHT_HEADER
#define LIGHT_HEADER


#include "Transform.h"
#include "Camera.h"

namespace example
{
	class Light
	{
	public:
		/**
		 * @brief Constructor
		 * @param vector Direction of the light
		 * @param color Color of the light
		 * @param i Intensity
		 * @param ambiental Ambiental intensity
		 */
		Light(glm::vec3 vector, glm::vec3 color, float i = 1.f, float ambiental = .25f)
			:transform(Transform()), intensity(i), ambient_intensity(ambiental), light_color(color)
		{
			position = vector;
			transform.translate(vector);
		}

	public:
		void set_direction(const glm::vec3& vector) { transform.translate(vector); }
		void set_color(const glm::vec3& color) { light_color = color; }
		void set_ambient_intensity(float a) { ambient_intensity = a; }
		void set_intensity(float i) { intensity = i; }

		glm::vec3 get_color() const { return light_color; }
		float get_intensity() const { return intensity; }
		float get_ambient_intensity() const { return ambient_intensity; }

		/* Updates the light values for the render */
		void render(Camera& camera);

	public:
		/* Transform of the light */
		Transform transform;

	private:
		/* Light intensity */
		float intensity;

		/* Light ambiental intensity*/
		float ambient_intensity;

		/* Color of the light */
		glm::vec3 light_color;

		/* Position/direction of the light */
		glm::vec3 position;
	};
}
#endif
