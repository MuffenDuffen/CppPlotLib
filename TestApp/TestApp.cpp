#include <iostream>
#include "CppPlotLibReMZ.h"

int main()
{
    std::cout << "Hello World!\n";

    std::vector<unsigned long long> nums = { 1,2,3,4,5,4,3,2,1 };

    const CppP::DataStruct dataRemZ(nums, "Test Window", "XAxis", "YAxis");

    CppP::showDiagram(dataRemZ);
}