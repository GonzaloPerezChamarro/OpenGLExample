#ifndef CAMERA_HEADER
#define CAMERA_HEADER

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

namespace example
{
	using namespace glm;

	class Camera
	{
	private:

		float near;
		float far;

		float yaw;
		float pitch;
		float roll;



		float fov;

		vec3 position;

		vec3 up;
		vec3 front;

	private:
		float last_mouse_x;
		float last_mouse_y;

		float sensitivity = 1.f;
		
	public:
		Camera(vec3 pos, float field_of_view = 90.f)
			: position(pos),up(vec3(0.f,1.f,0.f)), front(vec3(0.f,0.f,-1.f)),
			  yaw(-90.f), pitch(0.f), roll(0.f)
		{}

		void rotate(float mouse_x, float mouse_y);
		void move(glm::vec3 dir, float speed);

		mat4 get_view() const { return glm::lookAt(position, position + front, up); }

		vec3 get_position() const{ return position; }

		vec3 get_camera_front() const { return front; }

		vec3 get_camera_up() const { return up; }

		float get_camera_fov() const { return fov; }


	};
}


#endif


