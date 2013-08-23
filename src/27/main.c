#include <stdio.h>
#include <math.h>

int Primes[100000];
void getprimes(int limit) //Sieve of Eratosthenes
{
	int i,j;
	for(i = 0; i<limit; i++)
		Primes[i] = i+2;

	for(i = 0; i<(int)sqrt((double)limit); i++)
	{
		if(Primes[i])
			for(j = i+Primes[i]; j < limit; j+=Primes[i])
				Primes[j] = 0;
	}

	for(i = 0, j = 0; i < limit; i++)
	{
		if(Primes[i])
			Primes[j++] = Primes[i];
	}

	Primes[j] = 0;
}

int isprime(int n)
{
	int i;
	for(i = 0; Primes[i]; i++)
		if(n == Primes[i]) return 1;

	return 0;
}

int main()
{
	getprimes(100000);

	int a, b, n;
	int max = 0;
	int product;

	for(a = -999; a < 1000; a++)
	{
		for(b = 0; Primes[b] < 1000; b++)
		{
			for(n = 0; ; n++)
				if(!isprime((n*n)+(n*a)+Primes[b]))	break;

			if(n > max)
			{
				max = n;
				product = a * Primes[b];
			}
		}
	}

	printf("%d\n", product);

	return 0;
}
