/**
 * @file Camera.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class that represents a camera object
 * @version 1.0
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef CAMERA_HEADER
#define CAMERA_HEADER

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

namespace example
{
	using namespace glm;

	class Camera
	{
	private:

		float near_plane;
		float far_plane;

		float yaw;
		float pitch;
		float roll;

		float fov;
		float ratio;

		vec3 position;
		vec3 direction;

		vec3 up;
		vec3 front;

	private:
		float last_mouse_x = 0.f;
		float last_mouse_y = 0.f;
		bool first_time = true;

		float sensitivity = 0.5f;
		
	public:
		/**
		 * @brief Constructor
		 * @param pos Initial position 
		 * @param direction Forward direction of the view
		 * @param near_plane Minimal render plane
		 * @param far_plane Maximum render plane
		 * @param fov Field of view
		 * @param ratio View ratio
		 */
		Camera(vec3 pos, vec3 direction, float near_plane = 0.1f, float far_plane = 1000.f, float fov =90.f, float ratio = 1.f)
			: position(pos),direction(direction),up(vec3(0.f,1.f,0.f)), front(vec3(0.f,0.f,-1.f)),
			  yaw(-90.f), pitch(0.f), roll(0.f), near_plane(near_plane), far_plane(far_plane), fov(fov), ratio(ratio)
		{}

		/* Constructor by default */
		Camera(float near_plane = 0.1f, float far_plane = 1000.f, float fov = 90.f, float ratio = 1.f)
			: position(0.f, 0.f, 0.f), direction(0.f,0.f,-1.f), up(vec3(0.f, 1.f, 0.f)), front(vec3(0.f, 0.f, -1.f)),
			yaw(-90.f), pitch(0.f), roll(0.f), near_plane(near_plane), far_plane(far_plane), fov(fov), ratio(ratio)
		{
			
		}

		/* Rotates the camera with the mouse location */
		void rotate(float mouse_x, float mouse_y);

		/* Moves the camera into a direction with a speed */
		void move(glm::vec3 dir, float speed);

		/* Returns the view matrix */
		mat4 get_view() const { return glm::lookAt(position, position + front, up); }

		/* Returns the projection matrix */
		mat4 get_projection() const { return glm::perspective(fov, ratio, near_plane, far_plane); }

		/* Returns the camera position */
		vec3 get_position() const{ return position; }

		/* Returns the camera forward vector */
		vec3 get_camera_front() const { return front; }

		/* Returns the camera up vector */
		vec3 get_camera_up() const { return up; }

		/* Returns the camera field of view */
		float get_camera_fov() const { return fov; }
	};
}


#endif


