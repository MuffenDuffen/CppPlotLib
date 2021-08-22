#include <iostream>

#include "CppPlotLibReMZ.h"

int main()
{
	int numbers[9] = { 1,2,3,4,5,4,3,2,1 };

	void* lol = &numbers;

	const CppP::ChartData data("Test Window", CppP::Int2{ 960, 540 }, &numbers, 9);

	CppP::ShowWindow(data);

	return 0;
}
