

#include "Texture2D.hpp"

extern "C" 
{
#include <targa.h>
}

namespace example
{
	Texture2D::~Texture2D()
	{
		for (auto iterator = texture_buffer.begin(), end = texture_buffer.end();
			iterator != end;
			++iterator)
		{
			delete &iterator->second;
		}
	}
	std::shared_ptr<Texture> Texture2D::load_texture(const std::string & path, Parameter w, Parameter f)
	{
		tga_image image;

		std::shared_ptr<Texture> texture;

		const char * path_file = path.c_str();

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