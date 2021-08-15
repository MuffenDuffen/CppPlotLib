#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

namespace CppP
{
    struct dataStruct
    {
        std::string title;

        std::string titleXAxis;
        std::string titleYAxis;

        std::vector<unsigned long long> nums = {};
        std::vector<unsigned long long> coords = {};
    };
}