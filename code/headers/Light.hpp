#ifndef LIGHT_HEADER
#define LIGHT_HEADER


#include "Transform.hpp"

namespace example
{
	class Light
	{
	public:

		Transform transform;
	private:
		float intensity;
		float ambient_intensity;

		glm::vec3 light_color;

	public:

		Light(glm::vec3 vector, glm::vec3 color, float i = 1.f, float ambiental = .25f)
			:transform(Transform()), intensity(i), ambient_intensity(ambiental), light_color(color)
		{
			transform.translate(vector);
		}

	public:

		void set_direction			(glm::vec3 & vector)	{ transform.translate(vector); }
		void set_color				(glm::vec3 & color)		{ light_color = color; }
		void set_ambient_intensity	(float a)				{ ambient_intensity = a; }
		void set_intensity			(float i)				{ intensity = i; }

		glm::vec3 & get_color() { return light_color; }
		float get_intensity() { return intensity; }
		float get_ambient_intensity() { return ambient_intensity; }
		
	};
}
#endif
