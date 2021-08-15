#pragma once

#include <iostream>

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

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
			TitleXAxis = titleX;
			TitleYAxis = titleY;
		}
    };
    void showWin(DataStruct data)
    {
		sf::RenderWindow window;
		auto windowColor = sf::Color(255, 255, 255, 255);

		window.create(sf::VideoMode(960, 540), "Test Window");
		window.setFramerateLimit(60);

    	// Rectangle
		sf::RectangleShape rS;
    	rS.setPosition(sf::Vector2f(80, 45));
		rS.setSize(sf::Vector2f(800, 450));
		rS.setFillColor(sf::Color(0, 0, 0));
    	sf::RectangleShape rS2;
    	rS2.setPosition(sf::Vector2f(80, 45));
    	rS2.setSize(sf::Vector2f(400, 450));
    	rS2.setFillColor(sf::Color(0, 255, 0));

		#pragma region Font loading
		sf::Font font;
		if (!font.loadFromFile("JetBrainsMono-Medium.ttf"))
		{
			std::cout << "Failed to load font file\n";
			exit(EXIT_FAILURE);
		}
		#pragma endregion

    	// Texts
    	sf::Text title, titleX, titleY;
    	title.setString(data.Title);
    	titleX.setString(data.TitleXAxis);
    	titleY.setString(data.TitleYAxis);
    	title.setFont(font);
    	title.setFillColor(sf::Color(0, 0, 0));
    	title.setPosition((window.getSize().x / 2) - title.getLocalBounds().width / 2, 10);

    	

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
					window.clear(windowColor);
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

		#pragma region Rendering

			window.clear(windowColor);

			window.draw(rS);
			window.draw(rS2);

			window.draw(title);
			window.draw(titleX);
			window.draw(titleY);

			window.display();

#pragma endregion 
		}
    }
}