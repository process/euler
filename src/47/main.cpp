#include <stdio.h>
#include <math.h>

#define MAXPRIMES 1000000

int Primes[MAXPRIMES];
void getprimes() //Sieve of Eratosthenes
{
	int i,j;
	for(i = 0; i<MAXPRIMES; i++)
		Primes[i] = i+2;

	for(i = 0; i<(int)sqrt((double)MAXPRIMES); i++)
	{
		if(Primes[i])
			for(j = i+Primes[i]; j < MAXPRIMES; j+=Primes[i])
				Primes[j] = 0;
	}

	for(i = 0, j = 0; i < MAXPRIMES; i++)
	{
		if(Primes[i])
			Primes[j++] = Primes[i];
	}

	Primes[j] = 0;
}

int GetDivisors(int n)
{
	int i, count = 0;
	
	for(i = 0; i < 1000 && n != 1; i++)
	{
		if(n % Primes[i] == 0)
		{
			count++;
			while(n % Primes[i] == 0)
				n /= Primes[i];
		}
	}

	return count;
}

int main()
{
	int i, count;

	getprimes();

	for(i = 16; ; i++)
	{
		if(GetDivisors(i) == 4)
			count++;
		else count = 0;

		if(count == 4)
			break;
	}

	printf("%d\n", i-3);

	return 0;
}
