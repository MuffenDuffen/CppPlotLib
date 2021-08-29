#pragma once

#include "GLEW/glew.h"
#include "GLFW/glfw3.h"
#include <string>
#include <vector>

void GLAPIENTRY
MessageCallback( GLenum source,
				GLenum type,
				GLuint id,
				GLenum severity,
				GLsizei length,
				const GLchar* message,
				const void* userParam )
{
	std::cout << "---------------------opengl-callback-start------------" << std::endl;
	std::cout << "message: "<< message << std::endl;
	std::cout << "type: ";
	switch (type) {
	case GL_DEBUG_TYPE_ERROR:
		std::cout << "ERROR";
		break;
	case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
		std::cout << "DEPRECATED_BEHAVIOR";
		break;
	case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
		std::cout << "UNDEFINED_BEHAVIOR";
		break;
	case GL_DEBUG_TYPE_PORTABILITY:
		std::cout << "PORTABILITY";
		break;
	case GL_DEBUG_TYPE_PERFORMANCE:
		std::cout << "PERFORMANCE";
		break;
	case GL_DEBUG_TYPE_OTHER:
		std::cout << "OTHER";
		break;
	}
	std::cout << std::endl;
 
	std::cout << "id: " << id << std::endl;
	std::cout << "severity: ";
	switch (severity){
	case GL_DEBUG_SEVERITY_LOW:
		std::cout << "LOW";
		break;
	case GL_DEBUG_SEVERITY_MEDIUM:
		std::cout << "MEDIUM";
		break;
	case GL_DEBUG_SEVERITY_HIGH:
		std::cout << "HIGH";
		break;
	default:
		std::cout << "HINT";
		break;
	}
	std::cout << std::endl;
	std::cout << "---------------------opengl-callback-end--------------" << std::endl;
}

namespace CppP
{
	#pragma region Miscellaneous
	inline int Highest(std::vector<int>& numbers)
	{
		int max = numbers[0];
		for (int i = 1; i < numbers.size(); i++)
		{
			if(numbers[i]>max)
			{
				max = numbers[i];
			}
		}
		return max;
	}

	inline float CalculatePosition(const int max, const int number)
	{
		const double pos = static_cast<double>(number) / max;
		return pos * 2 - 1;
	}
	#pragma endregion

	#pragma region Types
	struct Int2
	{
		int X, Y;
	};

	struct ChartData
	{
		std::string WinName;
		Int2 WinSize;

		std::vector<int> Numbers;

		ChartData(const std::string win_name, const Int2& win_size, std::vector<int>& numbers)
		{
			WinName = win_name;
			WinSize = win_size;
			Numbers = numbers;
		}
	};
	#pragma endregion

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

		if (glewInit() != GLEW_OK)
		{
			std::cout << "GLEW error on init";
			exit(EXIT_FAILURE);
		}
		#if _DEBUG
		if(glDebugMessageCallback){
			std::cout << "Register OpenGL debug callback " << std::endl;
			glEnable(GL_DEBUG_OUTPUT);
			glDebugMessageCallback(MessageCallback, nullptr);
			GLuint unusedIds = 0;
			glDebugMessageControl(GL_DONT_CARE,
				GL_DONT_CARE,
				GL_DONT_CARE,
				0,
				&unusedIds,
				true);
		}
		else
			std::cout << "glDebugMessageCallback not available" << std::endl;
		#endif

		std::vector<float> positions;
		positions.reserve(data.Numbers.size() * 2);
		const int max = Highest(data.Numbers);
		for (int i = 0; i < data.Numbers.size(); i++)
		{
			positions.push_back(CalculatePosition(data.Numbers.size() - 1, i));
			positions.push_back(CalculatePosition(max, data.Numbers[i]));
		}

		unsigned int vbo; // Vertex Object Buffer, in this case it is the ID of the buffer
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, positions.size() * sizeof(float), &positions[0], GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);

		int viewX;
		int viewY;
		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window))
		{
			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT);

			glDrawArrays(GL_LINE_STRIP, 0, data.Numbers.size());

			glfwGetWindowSize(window, &viewX, &viewY);
			glViewport(0, 0, viewX, viewY);

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		}

		glfwTerminate();
		return 0;
	}
}
