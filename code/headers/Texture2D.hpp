

#ifndef TEXTURE_2D_HEADER
#define TEXTURE_2D_HEADER


#include "Texture.hpp"
#include "OpenGL.hpp"

#include <map>

namespace example
{
	class Texture2D : public Texture
	{
	private:

		std::map<std::string, std::shared_ptr<Texture>> texture_buffer;

	public:
		Texture2D(const std::string & path, Parameter w = Parameter::CLAMP_TO_EDGE, Parameter f = Parameter::MIPMAP_LINEAR_FILTER)
		{
			load_texture(path, w, f);
		}

		~Texture2D();

	public:
		void bind() override
		{
			glBindTexture(GL_TEXTURE_2D, id);
		}

		void unbind() override
		{
			glBindTexture(GL_TEXTURE_2D, 0);
		}

		void set_wrap(Parameter parameter) override
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, parameter);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, parameter);
		}

		void set_filter(Parameter parameter) override
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, parameter);

			if (parameter == NEAR_PIXEL_FILTER || parameter == MIPMAP_NEAR_PIXEL_FILTER)
			{
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, NEAR_PIXEL_FILTER);
			}
			else if (parameter == LINEAR_FILTER || parameter == MIPMAP_LINEAR_FILTER)
			{
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, LINEAR_FILTER);
			}

			if (parameter == MIPMAP_LINEAR_FILTER || parameter == MIPMAP_NEAR_PIXEL_FILTER)
			{
				glGenerateMipmap(GL_TEXTURE_2D);
			}
		}

		std::auto_ptr<Texture> load_texture(const std::string & path, Parameter w, Parameter f) override;

	};

}
#endif