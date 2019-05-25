/**
 * @file Transform.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase Trasform
 * @version 0.1
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef TRANSFORM_HEADER
#define TRANSFORM_HEADER


#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

namespace example
{
	using namespace glm;

	class Transform
	{
	private:
		/**
		 * @brief matriz de trasformacion global
		 * 
		 */
		mat4 transform;

		/**
		 * @brief matriz de transformacion local
		 * 
		 */
		mat4 local_transform;

		/**
		 * @brief indica si el transform ha sido actualizado
		 * 
		 */
		bool updated;

		/**
		 * @brief posicion del transform
		 * 
		 */
		glm::vec3 position;

		/**
		 * @brief Rotacion del transform
		 * 
		 */
		glm::vec3 rotation;

		/**
		 * @brief Escala del transform
		 * 
		 */
		glm::vec3 scale;

		/**
		 * @brief puntero al transform padre
		 * 
		 */
		Transform * parent = nullptr;

	public:
		/**
		 * @brief Constructor de Transform por defecto
		 * 
		 */
		Transform() : transform(mat4()) {}

		/**
		 * @brief Constructor de Transform
		 * 
		 * @param position Posicion inicial
		 * @param euler_angles Rotacion inicial
		 * @param scale Escala global
		 */
		Transform(glm::vec3 position, glm::vec3 euler_angles, glm::vec3 scale);

		/**
		 * @brief Devuelve la matriz de transform
		 * 
		 * @return const glm::mat4& 
		 */
		const glm::mat4 & get_matrix();

		glm::vec3 get_position();
		glm::vec3 get_rotation();
		glm::vec3 get_scale();

		/**
		 * @brief Traslada el transform el desplazamiento recibido
		 * 
		 * @param position 
		 */
		void translate(const glm::vec3 position);

		/**
		 * @brief Rota el transform los angulos recibidos
		 * 
		 * @param euler_angles 
		 */
		void rotate(glm::vec3 euler_angles);

		/**
		 * @brief Escala el transform
		 * 
		 * @param scale 
		 */
		void to_scale(glm::vec3 scale);

		/**
		 * @brief Actualiza el transform
		 * 
		 */
		void update() { updated = false; }

		/**
		 * @brief Modifica el valor de parent 
		 * 
		 * @param tr 
		 */
		void set_parent(Transform * tr) { parent = tr; }

	public:
		/**
		 * @brief Sobrecarga del operador =
		 * 
		 * @param other 
		 * @return glm::mat4& 
		 */
		glm::mat4 & operator = (glm::mat4 other)
		{
			return local_transform = other;
		}

	};
}


#endif // TRANSFORM_HEADER


