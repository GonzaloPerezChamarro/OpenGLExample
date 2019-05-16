

#include "Transform.hpp"

namespace example
{
	Transform::Transform(glm::vec3 position, glm::vec3 euler_angles, glm::vec3 scale)
		:position(position), rotation(euler_angles), scale(scale), updated(false),
		transform(glm::mat4(1.f)), local_transform(glm::mat4(1.f))
	{
		local_transform = glm::translate(glm::mat4(), position);
		local_transform = glm::scale(local_transform, scale);
		local_transform = glm::rotate(local_transform, rotation.x, glm::vec3(1.f, 0.f, 0.f));
		local_transform = glm::rotate(local_transform, rotation.y, glm::vec3(0.f, 1.f, 0.f));
		local_transform = glm::rotate(local_transform, rotation.z, glm::vec3(0.f, 0.f, 1.f));

	}

	const glm::mat4 & Transform::get_matrix()
	{
		if (updated) return transform;

		if (parent != nullptr)
		{
			transform = parent->get_matrix() * local_transform;
		}
		else
		{
			transform = local_transform;
		}

		updated = true;

		return transform;
	}

	glm::vec3 Transform::get_position()
	{
		return glm::vec3(get_matrix()[3].x, get_matrix()[3].y, get_matrix()[3].z);

	}
	glm::vec3 Transform::get_rotation()
	{
		return glm::vec3(get_matrix()[0].x, get_matrix()[1].y, get_matrix()[2].z);

	}
	glm::vec3 Transform::get_scale()
	{
		return glm::vec3(get_matrix()[0].x, get_matrix()[1].y, get_matrix()[2].z);

	}
	void Transform::translate(const glm::vec3 movement)
	{
		this->position += position;
		local_transform = glm::translate(local_transform, movement);
	}

	void Transform::rotate(glm::vec3 euler_angles)
	{
		rotation += euler_angles;
		local_transform = glm::rotate(local_transform, euler_angles.x, glm::vec3(1.f, 0.f, 0.f));
		local_transform = glm::rotate(local_transform, euler_angles.y, glm::vec3(0.f, 1.f, 0.f));
		local_transform = glm::rotate(local_transform, euler_angles.z, glm::vec3(0.f, 0.f, 1.f));

	}

	void Transform::to_scale(glm::vec3 scale)
	{
		this->scale *= scale;
		local_transform = glm::scale(local_transform, scale);
	}
}