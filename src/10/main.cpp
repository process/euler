#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

void sieveOfEratosthenes(int * NumberList, int len)
{
	int i,j;

	for(i = 0; i<len; i++)
		NumberList[i] = i;
	
	NumberList[0] = 0;
	NumberList[1] = 0;

	for(i = 2; i<(int)sqrt((double)len); i++)
		if(NumberList[i])
			for(j = i+NumberList[i]; j < len; j+=NumberList[i])
				NumberList[j] = 0;
}

bool isPrime(int n, int * primeList)
{
    return primeList[n];
}

int main()
{
	long long unsigned total=0;
  int * primes = new int[2000000]; 

  sieveOfEratosthenes(primes, 2000000);

	for (int i = 2; i < 2000000; i++) // Check each number under 2 million...
	{ 
		if (isPrime(i, primes)) // ... to see if its prime
		{
			total += i;
		}
	}

	cout << "The end total is " << total << endl;

	return 0;
}
