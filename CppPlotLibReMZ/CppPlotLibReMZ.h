#pragma once

#include <vector>
#include "GLFW/glfw3.h"
#include "imgui.h"

namespace CppP
{
	struct DataStruct
	{
		std::string Title;

		std::string TitleXAxis;
		std::string TitleYAxis;

		std::vector<unsigned long long> Nums = {};

		DataStruct(std::vector<unsigned long long>& nums, std::string title, std::string titleX, std::string titleY)
		{
			Nums = nums;
			Title = title;
			TitleXAxis = std::move(titleX);
			TitleYAxis = std::move(titleY);
		}
	};

	int showDiagram(const DataStruct& data)
	{
		GLFWwindow* window;

		/* Initialize the library */
		if (!glfwInit())
			return -1;

		//String to const char*
		const char* ConstCharPtr = data.Title.c_str();

		/* Create a windowed mode window and its OpenGL context */
		window = glfwCreateWindow(960, 540, ConstCharPtr, nullptr, nullptr);

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
