#include <math.h>
#include <stdio.h>

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

int rotateright(int num)
{
	int LSD = num % 10;
	int temp = num;
	int pow = 1;

	while(temp/=10)
		pow*=10;

	num /= 10;

	num += LSD * pow;

	return num;
}

char isprime(int n)
{
	int i;
	for(i = 0; Primes[i]; i++)
	{
		if(Primes[i] == n)
			return 1;
	}

	return 0;
}

int main()
{
	getprimes();

	int i, temp, count = 0;
	for(i = 0; Primes[i]; i++)
	{
		temp = Primes[i];
		do
		{
			if(!isprime(temp = rotateright(temp)))
				break;
		}while (temp != Primes[i]);

		if(temp == Primes[i])
			count++;
	}

	printf("%d\n", count);

	return 0;
}

