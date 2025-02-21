/**
 * @file Color_Rgba8888.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Class of a rgba color (32bits)
 * @version 1.0
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef COLOR_RGBA8888_HEADER
#define COLOR_RGBA8888_HEADER

#include <stdint.h>     

namespace example
{
	class Color_RGBA8888
	{
	public:
		union Data
		{
			struct
			{
				uint8_t r;
				uint8_t g;
				uint8_t b;
				uint8_t a;
			}
			component;

			uint32_t value;
		};

		Data data;

		void set(int r, int g, int b, int a = 255)
		{
			data.component.r = r;
			data.component.g = g;
			data.component.b = b;
			data.component.a = a;
		}

		Color_RGBA8888& operator= (const int& value)
		{
			data.value = uint32_t(value);
			return (*this);
		}

		static Color_RGBA8888& red()
		{
			Color_RGBA8888 c;
			c.data.component.r = 255;
			c.data.component.g = 0;
			c.data.component.b = 0;
			c.data.component.a = 255;
			return c;
		}

		static Color_RGBA8888& blue()
		{
			Color_RGBA8888 c;
			c.data.component.r = 0;
			c.data.component.g = 0;
			c.data.component.b = 255;
			c.data.component.a = 255;
			return c;
		}

		static Color_RGBA8888& green()
		{
			Color_RGBA8888 c;
			c.data.component.r = 0;
			c.data.component.g = 255;
			c.data.component.b = 0;
			c.data.component.a = 255;
			return c;
		}
		
		//More default colors....
	};
}
#endif
