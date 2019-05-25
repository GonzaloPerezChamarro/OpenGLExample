/**
 * @file VertexShader.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase Vertex Shadder. Hija de Shader
 * @version 0.1
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef VERTEX_SHADER_HEADER
#define VERTEX_SHADER_HEADER

#include "Shader.hpp"

namespace example
{
	class Vertex_Shader:public Shader
	{
	public:
		/**
		 * @brief Constructor de Vertex_Shader
		 * 
		 * @param source_code 
		 */
		Vertex_Shader(const Source_Code & source_code)
			:Shader(source_code, GL_VERTEX_SHADER)
		{}
	};
}
#endif
