#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

void OrderPrimeList(int * PrimeList, int len)
{
	int i, j;

	for(i = 0, j = 0; i < len; i++)
	{
		if(PrimeList[i])
			PrimeList[j++] = PrimeList[i];
	}

	PrimeList[j] = 0;
}

void SieveOfEratosthenes(int * NumberList, int len)
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

char isPrime(int n, int * PrimeList)
{
	return PrimeList[n] ? 1 : 0;
}

int totient(int n, int * PrimeList)
{
	int product = n;
	int i = 0, p;

	while(n != 1)
	{
		if(n % (p=PrimeList[i]) == 0)
		{
			product -= product/p;
			do {
				n /= p;
			} while (n % p == 0);
		}
		i++;
	}


	return product;
}

int main()
{
	int i;
	long long count = 0;

	const int limit = 1000001;

	int * Primes = (int*) malloc(limit*sizeof(int));
	int * OrderedPrimes = (int *) malloc(limit*sizeof(int));
	SieveOfEratosthenes(Primes, limit);
	memcpy(OrderedPrimes, Primes, limit*sizeof(int));
	OrderPrimeList(OrderedPrimes, limit);

	for(i = 2; i < limit; i++)
	{
		if(isPrime(i, Primes)) count += i-1;
		else count += totient(i, OrderedPrimes);
	}

	printf("%lld\n", count);

	free(Primes);
	free(OrderedPrimes);
	return 0;
}
