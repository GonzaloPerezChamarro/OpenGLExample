
#include "Kernel.hpp"
#include <memory>

namespace example
{
	int main()
	{
		Kernel * kernel = new Kernel("OpenGL Example", 800, 600);

		kernel->execute();
		
		return 0;
	}
}

