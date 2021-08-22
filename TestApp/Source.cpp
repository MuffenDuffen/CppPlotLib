#include <iostream>

#include "CppPlotLibReMZ.h"

int main()
{
	const CppP::ChartData data("Test Window", CppP::Int2{ 960, 540 });

	CppP::ShowWindow(data);

	return 0;
}
