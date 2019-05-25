/**
 * @file Texture.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase base de textura
 * @version 0.1
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */

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
	/**
	 * @brief Enumeracion que recoge los tipos de parametro
	 * 
	 */
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

		/**
		 * @brief Id de la textura
		 * 
		 */
		GLenum id;

		/**
		 * @brief Error de la textura
		 * 
		 */
		GLenum error;

		/**
		 * @brief Indica si la carga de la textura ha sido correcta
		 * 
		 */
		bool success;

		/**
		 * @brief Buffer de la textura
		 * 
		 */
		std::vector <Color_RGBA8888> texture_buffer;

		/**
		 * @brief color
		 * 
		 */
		Color color;

		/**
		 * @brief Ancho de la textura
		 * 
		 */
		size_t width;

		/**
		 * @brief Alto de la textura
		 * 
		 */
		size_t height;

	public:
		/**
		 * @brief Constructor de Texture por defecto
		 * 
		 */
		Texture() = default;
		/**
		 * @brief Constructor de Texture
		 * 
		 * @param width ancho
		 * @param height alto
		 */
		Texture(size_t width, size_t height)
			:width(width), height(height), success(true), texture_buffer(width*height)
		{}

		

		virtual ~Texture()
		{
			//glDeleteTextures(1, &id);
		}

	public:

		/**
		 * @brief Metodo virtual de carga de textura
		 * 
		 * @param path 
		 * @param w 
		 * @param f 
		 * @return std::shared_ptr<Texture> 
		 */
		virtual std::shared_ptr<Texture> load_texture(const std::string & path, Parameter w, Parameter f) { return std::shared_ptr<Texture>(); }

		virtual void bind() {}

		virtual void unbind() {}

		virtual void set_wrap(Parameter p) {}

		virtual void set_filter(Parameter p) {}

		bool is_ready() { return success; }

		size_t get_size() { texture_buffer.size(); }

		GLenum get_id()const { return id; }

	public:
		/**
		 * @brief Devuelve un puntero al buffer de textura
		 * 
		 * @return Color* 
		 */
		Color * colors()			{return (&texture_buffer.front());}
		/**
		 * @brief Devuelve un puntero al buffer de textura
		 * 
		 * @return Color* 
		 */
		const Color * colors() const{return (&texture_buffer.front());}

		/**
		 * @brief Devuelve el tamaño de color
		 * 
		 * @return int 
		 */
		int bits_per_color() const	{return (sizeof(Color) * 8);}

		/**
		 * @brief Tamaño de la textura
		 * 
		 * @return size_t 
		 */
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
