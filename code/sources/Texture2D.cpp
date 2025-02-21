

#include "Texture2D.h"


extern "C" 
{
#include <targa.h>
}

namespace example
{
	std::map<std::string, std::shared_ptr<Texture>> Texture2D::factory;

	std::shared_ptr<Texture> Texture2D::get_texture(const std::string & path, Parameter wrap, Parameter filter)
	{
		// Checking Factory
		if (factory.count(path) > 0)
			return factory[path];

		// Creating a new one
		std::shared_ptr<Texture> texture(new Texture2D(path, wrap, filter));

		if (!texture->is_ready())
		{
			texture.reset();
		}
		else
		{
			factory[path] = texture;
		}

		return texture;
	}

	Texture2D::~Texture2D()
	{

	}

	std::shared_ptr<Texture> Texture2D::load_texture(const std::string & path, Parameter w, Parameter f)
	{
		tga_image image;

		std::shared_ptr<Texture> texture;

		const char * path_file = path.c_str();

		//Lectura del .tga
		if (tga_read(&image, path_file) == TGA_NOERR)
		{
			texture.reset(new Texture(image.width, image.height));
			tga_convert_depth(&image, texture->bits_per_color());
			tga_swap_red_blue(&image);

			Texture::Color * pixels_begin = reinterpret_cast<Texture::Color*>(image.image_data);
			Texture::Color * pixels_end = pixels_begin + image.width * image.height;
			Texture::Color * buffer = texture->colors();

			while (pixels_begin < pixels_end)
			{
				*buffer++ = *pixels_begin++;
			}

			tga_free_buffers(&image);

		}

		return texture;
	}
}
