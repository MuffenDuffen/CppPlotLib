#include "CppPlotLib.h"
#include <vector>
#include <iostream>

int main()
{
	std::vector<unsigned long long> numbers;
	
	CppP::showWin(CppP::DataStruct(numbers, "Test", "X", "Y"));
	
	return 0;
}