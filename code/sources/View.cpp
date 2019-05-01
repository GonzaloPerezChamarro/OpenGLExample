
#include "View.hpp"
#include <SFML/OpenGL.hpp>

namespace example
{
	View::View(Camera * camera, unsigned width, unsigned height)
	{
		glEnable(GL_CULL_FACE);// BackFace Culling
		glEnable(GL_LIGHTING);// Lightning
		glEnable(GL_LIGHT0);                
		glShadeModel(GL_FLAT);// Eliminae el difuminado en los poligonos

		glPolygonMode(GL_FRONT, GL_LINE);

		//AA
		glEnable(GL_BLEND);
		glEnable(GL_LINE_SMOOTH);
		glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	void View::update(float deltaTime)
	{
		//Update models ....
	}

	void View::render()
	{
		glLoadIdentity();
		glTranslatef(0.f, 0.f, -10.f);

		//Render models....
	}


}