#include "stdio.h"
#include "math.h"

#define PRIMEAMT 1000
int Primes[PRIMEAMT];

void getprimes() //Generates given number of primes
{
	Primes[0] = 2;
	int a = 3;
	int j = 0;
	int pos = 1;

	for(pos = 1; pos < PRIMEAMT; a++)
	{
		for(j = 0; j < pos ; j++)
			if(a % Primes[j] == 0)
				break;

		if(j == pos)
			Primes[pos++] = a;
	}
}

char isPrime(int n)
{
	int i;
	for(i = 0; Primes[i] <= n; i++)
		if(Primes[i] == n)
			return 1;

	return 0;
}

int main()
{
	getprimes();

	int n, i, j, temp;
	char found = 0;

	for(n = 35; ; n+=2, found = 0)
	{
		if(isPrime(n))
			continue;

		for(i = 0; Primes[i] < n;  i++)
		{
			for(j = 1; (temp=Primes[i]+2*j*j) <= n; j++)
			{
				if(temp == n)
				{
					found = 1;
					break;
				}
			}

			if(found)
				break;
		}

		if(!found)
			break;
	}

	printf("%d\n", n);

	return 0;
}
