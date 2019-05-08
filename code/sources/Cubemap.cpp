

#include "Cubemap.hpp"

extern "C"
{
#include <targa.h>
}

namespace example
{
	Cubemap::Cubemap(const std::string & path)
	{
		success = false;

		std::vector < std::shared_ptr<Texture>> texture_sides(6);
		for (size_t index = 0; index < 6; index++)
		{
			texture_sides[index] = load_texture(path + char('0' + index) + ".tga");

			if (!texture_sides[index]) return;
		}

		glEnable(GL_TEXTURE_CUBE_MAP);

		glGenTextures(1, &id);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_CUBE_MAP, id);

		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

		//front, left, back, right, top, bottom
		static const GLenum texture_target[] =
		{
			GL_TEXTURE_CUBE_MAP_NEGATIVE_Z,
			GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
			GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
			GL_TEXTURE_CUBE_MAP_POSITIVE_X,
			GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
			GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
		};

		for (size_t texture_index = 0; texture_index < 6; texture_index++)
		{
			Texture & texture = *texture_sides[texture_index];

			glTexImage2D
			(
				texture_target[texture_index],
				0,
				GL_RGBA,
				texture.get_width(),
				texture.get_height(),
				0,
				GL_RGBA,
				GL_UNSIGNED_BYTE,
				texture.colors()
			);
		}
		success = true;
	}

	Cubemap::~Cubemap()
	{
		if (success)
		{
			glDeleteTextures(1, &id);
		}
	}

	bool Cubemap::load_texture(const std::string & path, Parameter w, Parameter f)
	{
		return false;
	}
}