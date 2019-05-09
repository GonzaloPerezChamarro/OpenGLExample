
#include "View.hpp"
#include <SFML/OpenGL.hpp>

namespace example
{
	View::View(Camera & camera, unsigned width, unsigned height)
		:camera(&camera), width(width), height(height),
		skybox(new Skybox("../../assets/skybox1/"))
	{
		glDisable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);// BackFace Culling
		glCullFace(GL_BACK);

		//AA
		/*glEnable(GL_BLEND);
		glEnable(GL_LINE_SMOOTH);
		glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);*/
	}

	void View::update(float deltaTime)
	{
		//Update models ....
	}

	void View::render()
	{
		glClearColor(0, 1, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		skybox->render(*camera);

		//Render models....
		//Lights...
	}


}