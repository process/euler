#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

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

char isPrime(int * PrimeList, int n)
{
	return PrimeList[n] ? 1 : 0;
}

int main()
{
	int answer = 0, longestsequence = 0, tempsum;
	int i, j;

	int * PrimeBools = (int*)malloc(1000000*sizeof(int));
	int * Primes = (int*)malloc(1000000*sizeof(int));

	SieveOfEratosthenes(PrimeBools, 1000000);
	memcpy(Primes, PrimeBools, 1000000*sizeof(int));
	OrderPrimeList(Primes, 1000000);

	for(i=0; Primes[i]; i++)
	{
		for(j=i, tempsum=0; tempsum+Primes[j] < 1000000 && Primes[j]; j++)
		{
			tempsum+=Primes[j];
			if(tempsum < 0)
				int dwrer = 2;
			if(isPrime(PrimeBools, tempsum) && j-i > longestsequence)
			{
				answer = tempsum;
				longestsequence = j-i;
			}
		}
	}

	printf("%d\n", answer);

	free(PrimeBools);
	free(Primes);

	return 0;
}
