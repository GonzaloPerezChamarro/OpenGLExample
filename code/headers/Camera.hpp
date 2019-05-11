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
		float last_mouse_x;
		float last_mouse_y;
		bool first_time = true;

		float sensitivity = 1.f;
		
	public:
		Camera(vec3 pos, vec3 direction, float near_plane = 0.1f, float far_plane = 1000.f, float fov =90.f, float ratio = 1.f)
			: position(pos),direction(direction),up(vec3(0.f,1.f,0.f)), front(vec3(0.f,0.f,-1.f)),
			  yaw(-90.f), pitch(0.f), roll(0.f), near_plane(near_plane), far_plane(far_plane), fov(fov), ratio(ratio)
		{}

		Camera(float near_plane = 0.1f, float far_plane = 1000.f, float fov = 90.f, float ratio = 1.f)
			: position(0.f, 0.f, 0.f), direction(0.f,0.f,-1.f), up(vec3(0.f, 1.f, 0.f)), front(vec3(0.f, 0.f, -1.f)),
			yaw(-90.f), pitch(0.f), roll(0.f), near_plane(near_plane), far_plane(far_plane), fov(fov), ratio(ratio)
		{
			
		}


		void rotate(float mouse_x, float mouse_y);
		void move(glm::vec3 dir, float speed);

		mat4 get_view() const { return glm::lookAt(position, position + front, up); }

		mat4 get_projection() const { return glm::perspective(fov, ratio, near_plane, far_plane); }

		vec3 get_position() const{ return position; }

		vec3 get_camera_front() const { return front; }

		vec3 get_camera_up() const { return up; }

		float get_camera_fov() const { return fov; }


	};
}


#endif


