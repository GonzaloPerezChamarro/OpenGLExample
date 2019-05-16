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
		mat4 local_transform;

		bool updated;

		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;

		Transform * parent = nullptr;

	public:
		Transform() : transform(mat4()) {}
		Transform(glm::vec3 position, glm::vec3 euler_angles, glm::vec3 scale);

		const glm::mat4 & get_matrix();

		glm::vec3 get_position();
		glm::vec3 get_rotation();
		glm::vec3 get_scale();

		void translate(const glm::vec3 position);
		void rotate(glm::vec3 euler_angles);
		void to_scale(glm::vec3 scale);

		void update() { updated = false; }

		void set_parent(Transform * tr) { parent = tr; }

	public:

		glm::mat4 & operator = (glm::mat4 other)
		{
			return local_transform = other;
		}

	};
}


#endif // TRANSFORM_HEADER


