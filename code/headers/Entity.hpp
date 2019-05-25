/**
 * @file Entity.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase padre entidad
 * @version 0.1
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once

#include "Transform.hpp"


namespace example
{
	class Entity
	{
	private:
		/**
		 * @brief Trasform de la entidad
		 * 
		 */
		Transform transform;

	public:
		/**
		 * @brief Constructor de la entidad
		 * 
		 */
		Entity();

		/**
		 * @brief actualiza lo necesario de la entidad
		 * 
		 * @param deltaTime 
		 */
		void update(float deltaTime);

		/**
		 * @brief renderiza la entidad
		 * 
		 */
		void render();
	};
}
