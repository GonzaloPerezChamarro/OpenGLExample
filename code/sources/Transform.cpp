

#include "Transform.hpp"

namespace example
{
	glm::vec3 Transform::get_position() const
	{
		return glm::vec3(transform[3].x, transform[3].y, transform[3].z);

	}
	glm::vec3 Transform::get_rotation() const
	{
		return glm::vec3(transform[0].x, transform[1].y, transform[2].z);

	}
	glm::vec3 Transform::get_scale() const
	{
		return glm::vec3(transform[0].x, transform[1].y, transform[2].z);

	}
	void Transform::translate(const glm::vec3 position)
	{
		transform = glm::translate(transform, position);

	}
	void Transform::rotate(float angle, const glm::vec3 & axis)
	{
		transform = glm::rotate(transform, glm::radians(angle), axis);
	}
	void Transform::scale(float scaleX, float scaleY, float scaleZ)
	{
		transform = glm::scale(transform, glm::vec3(scaleX, scaleY, scaleZ));
	}
}