#include <iostream>
#include <cmath>
using namespace std;

double target = 600851475143;
double maxResult = 0;

bool PrimeCheck(double p)
{
	int notPrime = 0;

	for (double d = 2; d <= p/2; d++)
	{
		if(p/d == floor(p/d))
		{
			notPrime = 1;
		}
	}

	if (notPrime == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int PrimeFactors(double num)
{
	for(float i=2;i <= num; i++)
	{
		if(PrimeCheck(i))
		{
			if(num/i == floor(num/i))
			{
				return i;
			}
		}
	}
}

int main()
{
	while (target !=1)
	{
		double factor = PrimeFactors(target);
		target = target/factor;
		if (factor > maxResult)
		{
			maxResult = factor;
		}
	}

	cout << "The largest prime factor is " << maxResult << endl;

	return 0;
}
