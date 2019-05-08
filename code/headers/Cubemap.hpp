

#ifndef CUBEMAP_HEADER
#define CUBEMAP_HEADER

#include "Texture.hpp"

namespace example
{
	class Cubemap :public Texture
	{
	public:
		Cubemap(const std::string & path);
		~Cubemap();

	public:

		std::auto_ptr<Texture> load_texture(const std::string & path);

		void bind() override 
		{
			glBindTexture(GL_TEXTURE_CUBE_MAP, id);
		}

		void unbind() override 
		{
			glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
		}


	};
}
#endif