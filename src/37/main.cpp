#include <stdio.h>
#include <math.h>

int Primes[1000000];

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
	getprimes(1000000);

	int p, q, r, f;
	int sum = 0;

	for(p = 4; Primes[p]; p++) //skip 2,3,5,7
	{
		q = Primes[p];
		f=0;

		do
			if(!isPrime(q)) f=1;
		while(q/=10);

		if(f==1) continue;

		q = Primes[p];
		r = 1;

		do
		{
			if(!isPrime(q)) f=1;
			r *= 10;
		}
		while(q%=(1000000/r));

		if(f==1) continue;

		sum += Primes[p];
		printf("%d is a truncatable prime.\n", Primes[p]);
	}

	printf("%d\n", sum);

	return 0;
}
