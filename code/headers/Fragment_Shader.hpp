/**
 * @file Fragment_Shader.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase fragment shader
 * @version 0.1
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef FRAGMENT_SHADER_HEADER
#define FRAGMENT_SHADER_HEADER

#include "Shader.hpp"

namespace example
{
	class Fragment_Shader :public Shader
	{
	public:
		/**
		 * @brief Constructor de Fragment_Shader
		 * 
		 * @param source_code 
		 */
		Fragment_Shader(const Source_Code & source_code)
			:Shader(source_code, GL_FRAGMENT_SHADER)
		{}
	};
}
#endif
