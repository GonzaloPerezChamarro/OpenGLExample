/**
 * @file VertexShader.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Child class of shader that represents a vertex shader
 * @version 1.0
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef VERTEX_SHADER_HEADER
#define VERTEX_SHADER_HEADER

#include "Shader.h"

namespace example
{
	class Vertex_Shader:public Shader
	{
	public:
		/* Constructor */
		Vertex_Shader(const Source_Code & source_code)
			: Shader(source_code, GL_VERTEX_SHADER)
		{}
	};
}
#endif
