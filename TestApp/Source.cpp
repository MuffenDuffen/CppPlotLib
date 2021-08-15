#include "CppPlotLib.h"
#include <vector>
#include <iostream>

int main()
{
	sf::RenderWindow window;
	auto windowColor = sf::Color(0, 0, 0, 255);
	window.create(sf::VideoMode(800, 600), "Test Window");
	window.setFramerateLimit(60);

	#pragma region Font loading
	sf::Font font;
	if (!font.loadFromFile("JetBrainsMono-Medium.ttf"))
	{
		std::cout << "Failed to load font file\n";
		exit(EXIT_FAILURE);
	}
	#pragma endregion 

	while (window.isOpen())
	{
		#pragma region Events

		sf::Event event{};
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::Resized:
				{
					sf::FloatRect visibleArea(0, 0, (event.size.width), (event.size.height));
					window.setView(sf::View(visibleArea));
						break;
				}
				case sf::Event::LostFocus: 
					break;
				case sf::Event::GainedFocus: 
					break;
				case sf::Event::TextEntered: 
					break;
				case sf::Event::KeyPressed:
					break;
				case sf::Event::KeyReleased:
					break;
				case sf::Event::MouseWheelMoved: 
					break;
				case sf::Event::MouseWheelScrolled: 
					break;
				case sf::Event::MouseButtonPressed:
					break;
				case sf::Event::MouseButtonReleased:
					break;
				case sf::Event::MouseMoved: 
					break;
				case sf::Event::MouseEntered: 
					break;
				case sf::Event::MouseLeft: 
					break;
				case sf::Event::JoystickButtonPressed: 
					break;
				case sf::Event::JoystickButtonReleased: 
					break;
				case sf::Event::JoystickMoved: 
					break;
				case sf::Event::JoystickConnected: 
					break;
				case sf::Event::JoystickDisconnected: 
					break;
				case sf::Event::TouchBegan: 
					break;
				case sf::Event::TouchMoved: 
					break;
				case sf::Event::TouchEnded: 
					break;
				case sf::Event::SensorChanged: 
					break;
				case sf::Event::Count: 
					break;
			}
		}

		#pragma endregion
		
		#pragma region Changes

		#pragma endregion
		
		#pragma region Rendering

		window.clear(windowColor);
		
		window.display();
		
		#pragma endregion 
	}
	
	return 0;
}