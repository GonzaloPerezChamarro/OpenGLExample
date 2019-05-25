/**
 * @file Camera.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase que representa a un objeto camara
 * @version 0.1
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2019
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
		float last_mouse_x;
		float last_mouse_y;
		bool first_time = true;

		float sensitivity = 0.5f;
		
	public:
		/**
		 * @brief Constructor de Camera
		 * 
		 * @param pos Posicion inicial de la camaa
		 * @param direction direccion a la que mira
		 * @param near_plane plano renderizado minimo
		 * @param far_plane plano de renderizado maximo
		 * @param fov punto de vista
		 * @param ratio ratio
		 */
		Camera(vec3 pos, vec3 direction, float near_plane = 0.1f, float far_plane = 1000.f, float fov =90.f, float ratio = 1.f)
			: position(pos),direction(direction),up(vec3(0.f,1.f,0.f)), front(vec3(0.f,0.f,-1.f)),
			  yaw(-90.f), pitch(0.f), roll(0.f), near_plane(near_plane), far_plane(far_plane), fov(fov), ratio(ratio)
		{}

		/**
		 * @brief Constructor por defecto
		 * 
		 * @param near_plane 
		 * @param far_plane 
		 * @param fov 
		 * @param ratio 
		 */
		Camera(float near_plane = 0.1f, float far_plane = 1000.f, float fov = 90.f, float ratio = 1.f)
			: position(0.f, 0.f, 0.f), direction(0.f,0.f,-1.f), up(vec3(0.f, 1.f, 0.f)), front(vec3(0.f, 0.f, -1.f)),
			yaw(-90.f), pitch(0.f), roll(0.f), near_plane(near_plane), far_plane(far_plane), fov(fov), ratio(ratio)
		{
			
		}

		/**
		 * @brief Rota la camara en funcion del raton
		 * 
		 * @param mouse_x 
		 * @param mouse_y 
		 */
		void rotate(float mouse_x, float mouse_y);

		/**
		 * @brief Movimiento de la camara en una direccion y una velocidad
		 * 
		 * @param dir Direccion
		 * @param speed Velocidad
		 */
		void move(glm::vec3 dir, float speed);

		/**
		 * @brief Devuelve la matriz de vista
		 * 
		 * @return mat4 
		 */
		mat4 get_view() const { return glm::lookAt(position, position + front, up); }

		/**
		 * @brief Devuelve la matriz de proyeccion
		 * 
		 * @return mat4 
		 */
		mat4 get_projection() const { return glm::perspective(fov, ratio, near_plane, far_plane); }

		/**
		 * @brief Devuelve la posicion de la camara
		 * 
		 * @return vec3 
		 */
		vec3 get_position() const{ return position; }

		/**
		 * @brief Devuelve camera front
		 * 
		 * @return vec3 
		 */
		vec3 get_camera_front() const { return front; }

		/**
		 * @brief Devuelve camera up 
		 * 
		 * @return vec3 
		 */
		vec3 get_camera_up() const { return up; }

		/**
		 * @brief Devuelve camera field of view
		 * 
		 * @return float 
		 */
		float get_camera_fov() const { return fov; }


	};
}


#endif


