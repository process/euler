#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
double count[25];

int main(int argc, char * argv[])
{
	printf("PE12\n\n");
	double trianglenum = 3;
	unsigned int i = 3;
	double temp;
	int divisors = 1;

	while(divisors < 501)
	{
		divisors = 1;
		trianglenum += i;
		i++;

		temp = trianglenum;

		for(int j = 0; j < 25; j++)
		{
			while(!fmod(temp, primes[j]))
			{
				temp /= primes[j];
				if(!count[j]) count[j]++;
				count[j]++;
			}
		}

		for(int j = 0; j < 25; j++)
		{
			if(count[j])
				divisors *= count[j];
			count[j] = 0;
		}
	}

	printf("The answer is %f\n", trianglenum);

	return 0;
}
