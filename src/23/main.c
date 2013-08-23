#include <stdio.h>
#include <string.h>
#include <math.h>

#define BUFLEN 7500
int Primes[30000];
int Abundants[BUFLEN];

//void getprimes() //Fast trial division
//{
//	Primes[0] = 2;
//	int a = 3;
//	int j = 0;
//	int pos = 1;
//
//	for(pos = 1; pos < BUFLEN; a++)
//	{
//		for(j = 0; j < pos ; j++)
//			if(a % Primes[j] == 0)
//				break;
//
//		if(j == pos)
//			Primes[pos++] = a;
//	}
//}

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

int getdivisorsum(int n)
{
	int a, p, i;
	int sum = 1;

	while(n != 1)
	{
		for(i = 0; ; i++)
			if(n % Primes[i] == 0)
				break;

		p = a = Primes[i];
		while(n % p == 0)
		{
			a *= p;
			n /= Primes[i];
		}

		sum *= (a-1)/(p-1);
	}

	return sum;
}

void getabundants()
{
	int i, n;

	memset(Abundants, 0, BUFLEN * sizeof(int));

	for(i = 0, n = 2; n < 28124; n++)
	{
		if(getdivisorsum(n)-n > n)
				Abundants[i++] = n;
	}
}

int issum(int num)
{
	int a, i, j;

	for(i = 0; Abundants[i] < num; i++)
	{
		a = num - Abundants[i];
		for(j = 0; j <= i ; j++)
		{
			if(a == Abundants[j])
				return 1;
		}
	}

	return 0;		
}

//A faster way is to compute all possible sums in an array,
//then compare all ints 1-28123 to the array.
//If it doesn't appear, it is not an amicable sum.

int main(int argc, char * argv[])
{
	int i;
	int sum = 0;

	getprimes(30000);
	getabundants();

	for(i = 0; i < 28124; i++)
		if(!issum(i))
			sum += i;

	printf("%d\n", sum);

	return 0;
}
