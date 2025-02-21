/**
 * @file Fragment_Shader.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class of a fragment shader
 * @version 1.0
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef FRAGMENT_SHADER_HEADER
#define FRAGMENT_SHADER_HEADER

#include "Shader.h"

namespace example
{
	class Fragment_Shader :public Shader
	{
	public:
		/* Constructor */
		Fragment_Shader(const Source_Code& source_code)
			:Shader(source_code, GL_FRAGMENT_SHADER)
		{}
	};
}
#endif
