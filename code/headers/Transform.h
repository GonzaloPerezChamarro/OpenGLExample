/**
 * @file Transform.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class Trasform
 * @version 1.0
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2025
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
		/* World transform matrix */
		mutable mat4 transform;

		/* Local transform matrix */
		mat4 local_transform;

		/* FLag that indicates if the transform is updated */
		mutable bool updated;
		
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;

		/* Pointer to parent transform (if any) */
		Transform * parent = nullptr;

	public:
		/* Constructor by default */
		Transform() : transform(mat4()), updated(false) {}

		/* Constructor with params */
		Transform(glm::vec3 position, glm::vec3 euler_angles, glm::vec3 scale);

		/* Returns the matrix transform (world) */
		const glm::mat4 & get_matrix() const;

		glm::vec3 get_position() const;
		glm::vec3 get_rotation() const;
		glm::vec3 get_scale() const;

		/**
		 * @brief Traslada el transform el desplazamiento recibido
		 * @brief Moves the transform
		 * @param position vector to add to current position
		 */
		void translate(const glm::vec3 position);

		/**
		 * @brief Rotates the transform specific angles
		 * @param euler_angles 
		 */
		void rotate(glm::vec3 euler_angles);

		/**
		 * @brief Scales the transform
		 * @param scale to multiply current scale
		 */
		void to_scale(glm::vec3 scale);

		/* Updates the transform */
		void update() { updated = false; }

		/**
		 * @brief Modifies the parent value
		 * @param tr new parent
		 */
		void set_parent(Transform * tr) { parent = tr; }

	public:
		/* Overloading of operator = for comparing with a matrix (local)*/
		glm::mat4 & operator= (glm::mat4 other)
		{
			return local_transform = other;
		}
	};
}

#endif // TRANSFORM_HEADER


