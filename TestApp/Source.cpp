#include <iostream>

#include "CppPlotLibReMZ.h"

int main()
{
	const int until = 100000;
	
	std::vector<int> numbers;
	numbers.reserve(until);

	// Sieve
	std::vector<int> primes;
	primes.reserve(until);
	std::vector<bool> sieve;
	sieve.resize(until, true);

	for(unsigned int b = 2; b < until; b++)
	{
		if(sieve[b])
		{
			primes.push_back(b);
			for (unsigned long long c = b * b; c < until; c+=b)
			{
				sieve[c] = false;
			}
		}
	}

	for(int a = 10; a < until; a++) // Start at 10 so we dont pass negative values
	{
		const int approximate = a / log(a - 1);

		int actual = 0;
		for(int b = 0; b < primes.size(); b++)
		{
			if(primes[b] < a)
			{
				actual++;
			}
			else
			{
				break;
			}
		}
		
		numbers.push_back(actual - approximate);
	}
	const CppP::ChartData data("Test Window", CppP::Int2{ 960, 540 }, numbers);

	CppP::ShowWindow(data);

	return 0;
}
