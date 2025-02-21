

#include "Cubemap.h"

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
			texture_sides[index] = load_texture(path +"cubemap_"+ char('0' + index) + ".tga");

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

		// front, left, back, right, top, bottom
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

	std::shared_ptr<Texture> Cubemap::load_texture(const std::string & path)
	{
		tga_image image;
		std::shared_ptr<Texture> texture;

		const char * path_file = path.c_str();

		if (tga_read(&image, path_file) == TGA_NOERR)
		{
			texture.reset(new Texture(image.width, image.height));
			tga_convert_depth(&image, texture->bits_per_color());
			tga_swap_red_blue(&image);

			Texture::Color* pixels_begin = reinterpret_cast<Texture::Color*>(image.image_data);
			Texture::Color* pixels_end = pixels_begin + image.width * image.height;
			Texture::Color* buffer = texture->colors();

			while (pixels_begin < pixels_end)
			{
				*buffer++ = *pixels_begin++;
			}

			tga_free_buffers(&image);
		}

		return texture;
	}
}
