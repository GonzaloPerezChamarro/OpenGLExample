

#ifndef MATERIAL_HEADER
#define MATERIAL_HEADER

#include "Texture2D.hpp"
#include "ShaderProgram.hpp"
#include "Variant.hpp"
#include <map>
#include <string>

namespace example
{
	class Material
	{
	private:
		Shader_Program shader;
		
		std::string id;
		std::map<std::string, Variant> variables;

	public:

		Material();
	};
}


#endif
