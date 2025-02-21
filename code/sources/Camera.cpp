

#include "Camera.h"

namespace example
{
	void Camera::rotate(float mouse_x, float mouse_y)
	{
		// FIx initial mouse location
		if (first_time)
		{
			first_time = false;
			last_mouse_x = mouse_x;
			last_mouse_y = mouse_y;
		}

		float xoffset = float(mouse_x) - last_mouse_x;
		float yoffset = last_mouse_y - float(mouse_y);

		last_mouse_x = mouse_x;
		last_mouse_y = mouse_y;

		xoffset *= sensitivity;
		yoffset *= sensitivity;

		yaw += xoffset;
		pitch += yoffset;

		if (pitch > 89.f)
			pitch = 89.f;
		if (pitch < -89.f)
			pitch = -89.f;

		front.x = cos(radians(pitch)) * cos(radians(yaw));
		front.y = sin(radians(pitch));
		front.z = cos(radians(pitch)) * sin(radians(yaw));

		front = normalize(front);
	}

	void Camera::move(vec3 dir, float speed)
	{
		position += dir * speed;
	}
}