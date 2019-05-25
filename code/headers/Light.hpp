/**
 * @file Light.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase que representa la luz
 * @version 0.1
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef LIGHT_HEADER
#define LIGHT_HEADER


#include "Transform.hpp"
#include "Camera.hpp"

namespace example
{
	class Light
	{
	public:
		/**
		 * @brief Transform de la luz
		 * 
		 */
		Transform transform;
	private:
		/**
		 * @brief Intensidad de la luz
		 * 
		 */
		float intensity;

		/**
		 * @brief Intensidad ambiental
		 * 
		 */
		float ambient_intensity;

		/**
		 * @brief Color de la luz
		 * 
		 */
		glm::vec3 light_color;

		/**
		 * @brief Posicion/direccion de la luz
		 * 
		 */
		glm::vec3 position;

	public:
		/**
		 * @brief Constructor
		 * 
		 * @param vector vector de direccion
		 * @param color color de la luz
		 * @param i Intensidad
		 * @param ambiental Intensidad ambiental
		 */
		Light(glm::vec3 vector, glm::vec3 color, float i = 1.f, float ambiental = .25f)
			:transform(Transform()), intensity(i), ambient_intensity(ambiental), light_color(color)
		{
			position = vector;
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

		/**
		 * @brief Actualiza los valores de la luz para el renderizado de modelos
		 * 
		 * @param camera 
		 */
		void render(Camera & camera);
		
	};
}
#endif
