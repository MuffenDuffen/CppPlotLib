#pragma once

#include "GLFW/glfw3.h"
#include "imgui.h"
#include "implot.h"
#include <string>

namespace CppP
{
	struct Int2
	{
		int X, Y;
	};

	struct ChartData
	{
		std::string WinName;
		Int2 WinSize;

		int* Numbers;
		int Length;

		ChartData(std::string winName, const Int2& winSize, void* numbers, const int length)
		{
			WinName = winName;
			WinSize = winSize;
			Numbers = static_cast<int*>(numbers);
			Length = length;
		}
	};

	inline int ShowWindow(CppP::ChartData data)
	{
		GLFWwindow* window;

		/* Initialize the library */
		if (!glfwInit())
			return -1;

		const char* str = data.WinName.c_str();

		/* Create a windowed mode window and its OpenGL context */
		window = glfwCreateWindow(data.WinSize.X, data.WinSize.Y, str, nullptr, nullptr);
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