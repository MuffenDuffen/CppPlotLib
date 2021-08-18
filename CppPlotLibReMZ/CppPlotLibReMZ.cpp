#include "pch.h"
#include "framework.h"

#include "CppPlotLibReMZ.h"

#include <vector>

namespace CppP
{
	struct DataStruct
	{
		std::string Title;

		std::string TitleXAxis;
		std::string TitleYAxis;

		std::vector<unsigned long long> Nums = {};

		DataStruct(std::vector<unsigned long long>& nums, const std::string& title, std::string& titleX, std::string& titleY)
		{
			Nums = nums;
			Title = title;
			TitleXAxis = titleX;
			TitleYAxis = titleY;
		}
	};

	int showDiagram()
	{
		GLFWwindow* window;

		/* Initialize the library */
		if (!glfwInit())
			return -1;

		/* Create a windowed mode window and its OpenGL context */
		window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
		if (!window)
		{
			glfwTerminate();
			return -1;
		}

		/* Make the window's context current */
		glfwMakeContextCurrent(window);

		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window))
		{
			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT);

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		}

		glfwTerminate();
		return 0;
	}
}
