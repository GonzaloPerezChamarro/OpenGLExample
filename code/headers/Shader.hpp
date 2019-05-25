/**
 * @file Shader.hpp
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase padre de un shader
 * @version 0.1
 * @date 2019-05-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef SHADER_HEADER
#define SHADER_HEADER

#include <string>

#include "OpenGL.hpp"

namespace example
{
	class Shader
	{
	public:
		/**
		 * @brief Clase que recoge el codigo de un shader 
		 * 
		 */
		class Source_Code
		{
		private:
			/**
			 * @brief Codigo del sahder
			 * 
			 */
			std::string string;

		public:
			/**
			 * @brief Devuelve un objeto Source_Code a partir de un string
			 * 
			 * @param code_string 
			 * @return Source_Code 
			 */
			static Source_Code from_string(const std::string & code_string)
			{
				return (Source_Code(code_string));
			}

			/**
			 * @brief Devuelve un objeto Source_Code a partir de un archivo
			 * 
			 * @param file_path 
			 * @return Source_Code 
			 */
			static Source_Code from_file(const std::string & file_path);

		private:
			/**
			 * @brief Constructor de Source_Code por defecto
			 * 
			 */
			Source_Code() {}

			/**
			 * @brief Constructor de Source_Code a partir de un string
			 * 
			 * @param source_code_string 
			 */
			Source_Code(const std::string & source_code_string)
				:string(source_code_string)
			{}


		public:

			size_t size() const { return (string.size()); }
			bool   is_empty() const { return (string.empty()); }
			bool   is_not_empty() const { return (!string.empty()); }

		public:

			operator const std::string & () const
			{
				return (Source_Code::string);
			}

			operator const char * () const
			{
				return (Source_Code::string.c_str());
			}


		};

	private:

		/**
		 * @brief Id del shader
		 * 
		 */
		GLuint      id;

		/**
		 * @brief Texto de log de error
		 * 
		 */
		std::string log_string;

	protected:

		/**
		 * @brief Constructor de Shader
		 * 
		 * @param source_code Objeto Source Code
		 * @param shader_type Tipo de shader (Vertex o fragment)
		 */
		Shader(const Source_Code & source_code, GLenum shader_type);

		/**
		 * @brief Destructor de Shader
		 * 
		 */
		virtual ~Shader();

	public:

		bool is_compiled() const
		{
			return (id != 0);
		}

		bool compilation_failed() const
		{
			return (id == 0);
		}

		const std::string & log() const
		{
			return (log_string);
		}

		operator GLuint () const
		{
			return (id);
		}

	};
}

#endif
