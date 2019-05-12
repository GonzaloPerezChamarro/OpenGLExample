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
		mat4 transform;

	public:
		Transform() : transform(mat4()) {}

		const glm::mat4 & get_matrix() const
		{
			return transform;
		}

		glm::vec3 get_position() const;
		glm::vec3 get_rotation() const;
		glm::vec3 get_scale() const;

		void translate(const glm::vec3 position);
		void rotate(float angle, const glm::vec3 & axis);
		void scale(float scaleX, float scaleY, float scaleZ);

	public:

		glm::mat4 & operator = (glm::mat4 other)
		{
			return transform = other;
		}

	};
}


#endif // TRANSFORM_HEADER


