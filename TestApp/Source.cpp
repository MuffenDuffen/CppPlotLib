#include <iostream>

#include "CppPlotLibReMZ.h"

int main()
{
	std::vector<int> numbers = { 0,1,3,3,4,5,4,3,2,1 };

	void* lol = &numbers;

	const CppP::ChartData data("Test Window", CppP::Int2{ 960, 540 }, numbers);

	CppP::ShowWindow(data);

	return 0;
}
