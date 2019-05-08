

#ifndef FRAGMENT_SHADER_HEADER
#define FRAGMENT_SHADER_HEADER

#include "Shader.hpp"

namespace example
{
	class Fragment_Shader :public Shader
	{
	public:
		Fragment_Shader(const Source_Code & source_code)
			:Shader(source_code, GL_FRAGMENT_SHADER)
		{}
	};
}
#endif
