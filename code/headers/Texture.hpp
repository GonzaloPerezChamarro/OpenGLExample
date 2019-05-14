#ifndef TEXTURE_HEADER
#define TEXTURE_HEADER

#include "OpenGL.hpp"
#include "SFML/Graphics.hpp"
#include "Color_Rgba8888.hpp"

#include <string>
#include <vector>

namespace example
{
	class Texture
	{
	public:
		enum Parameter 
		{
			//WRAP PARAMETERS
			REPEAT = GL_REPEAT,
			MIRRORED = GL_MIRRORED_REPEAT,
			CLAMP_TO_EDGE = GL_CLAMP_TO_EDGE,
			CLAMP_TO_BORDER = GL_CLAMP_TO_BORDER,

			//FILTER PARAMETERS
			NEAR_PIXEL_FILTER = GL_NEAREST,
			LINEAR_FILTER = GL_LINEAR,
			MIPMAP_NEAR_PIXEL_FILTER = GL_LINEAR_MIPMAP_NEAREST,
			MIPMAP_LINEAR_FILTER = GL_LINEAR_MIPMAP_LINEAR
		};


	protected:
		typedef Color_RGBA8888 Color;

		GLenum id;
		GLenum error;

		bool success;

		std::vector <Color_RGBA8888> texture_buffer;
		Color color;

		size_t width;
		size_t height;

	public:
		Texture() = default;
		Texture(size_t width, size_t height)
			:width(width), height(height), success(true), texture_buffer(width*height)
		{}

		

		virtual ~Texture()
		{
			//glDeleteTextures(1, &id);
		}

	public:

		virtual std::shared_ptr<Texture> load_texture(const std::string & path, Parameter w, Parameter f) { return std::shared_ptr<Texture>(); }

		virtual void bind() {}

		virtual void unbind() {}

		virtual void set_wrap(Parameter p) {}

		virtual void set_filter(Parameter p) {}

		bool is_ready() { return success; }

		size_t get_size() { texture_buffer.size(); }

		GLenum get_id()const { return id; }

	public:

		Color * colors()			{return (&texture_buffer.front());}

		const Color * colors() const{return (&texture_buffer.front());}

		int bits_per_color() const	{return (sizeof(Color) * 8);}

		size_t size() const			{return (texture_buffer.size());}


		void set_color(int r, int g, int b)
		{
			color.data.component.r = uint8_t(r < 0 ? 0 : r > 255 ? 255 : r);
			color.data.component.g = uint8_t(g < 0 ? 0 : g > 255 ? 255 : g);
			color.data.component.b = uint8_t(b < 0 ? 0 : b > 255 ? 255 : b);
			color.data.component.a = 0xFF;
		}

		void set_color(const Color & new_color){color = new_color;}

		void set_pixel(size_t offset){texture_buffer[offset] = color;}

		void set_pixel(int x, int y){texture_buffer[y * width + x] = color;}


		void gl_draw_pixels(int raster_x, int raster_y) const
		{
			//glRasterPos2i(raster_x, raster_y);
			//glDrawPixels(width, height, GL_RGBA, GL_UNSIGNED_BYTE, colors());
		}

		size_t get_width()const { return width; }
		size_t get_height()const { return height; }

	};
}
#endif
