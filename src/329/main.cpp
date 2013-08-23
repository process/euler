#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include "bignum.h"

//////////Approximation: 7086/1000000000

/*95 primes less than 500

ideal results of 1500 trials:

landed on P:
190 say P
95 say N

landed on N:
405 say P
810 say N

(190+405)/(190+405+95+810)=
119/300
^ Probability frog will say "P"

=================================================
P(landed on p given it said P) = 38/119 = (190)/(190+405)
P(landed on n given it said P) = 81/119 = (405)/(190+405)

P(landed on p given it said N) = 19/181 = (95)/(95+810)
P(landed on n given it said N) = 162/181 = (810)/(95+810)


if on P, probability it will jump to P is:
1/95 = 81/7695

if on N, probability it will jump to P is:
19/81 = 1805/7695



if on P, probability it will jump to N is:
94/95 = 7614/7695

if on N, probability it will jump to N is:
62/81 = 5890/7695



probability will jump on P:
(38/119)(1/95)+(81/119)(19/81) = 97/595

probability will jump on N:
(38/119)(94/95)+(81/119)(62/81) = 498/595

Land on P:
194 P
97 N

Land on N:
498 P
996 N

(194+498)/(194+97+498+996)=
692/1785

(692/1785)(119/300)=

173/1125
^ Probability frog will say "PP"
^ wrong?
*/

int Primes[1000];

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

void RunSimulations()
{
	int successes=0;
	int trials=0;
	int i, pos;

	char croaks[16];
	croaks[15] = '\0';
	croaks[1] = '\0';

	srand(time(NULL));

	for(trials = 0; trials <= 1000000000; trials++)
	{
		pos = 1+(rand()%500);
		for(i = 0; i < 1; i++)
		{
			if(isPrime(Primes, pos))
			{
				if(rand() % 3 > 0) //1 or 2. 2/3 chance 
					croaks[i] = 'P';
				else 
					croaks[i] = 'N';
			}

			else
			{
				if(rand() % 3 > 0)
					croaks[i] = 'N';
				else 
					croaks[i] = 'P';
			}

			if(pos == 500)
				pos = 499;
			else if(pos == 1)
				pos = 2;
			else
			{
				if(rand() % 2)
					pos++;
				else
					pos--;
			}
		}

		if(strcmp(croaks, "P") == 0)
			successes++;

		if(trials % 1000000 == 0)
			printf("%d/%d ... %f\n", successes, trials, (double)successes/trials);
	}
}

int main()
{
	SieveOfEratosthenes(Primes, 1000);

	srand(time(NULL));

	char croaks[] = "PPPPNNPPPNPPNPN";

	RunSimulations();

	bignum numerator;
	bigset(numerator, 119);

	bignum denominator;
	bigset(denominator, 300);

	bignum temp1;
	bigset(temp1, 190);

	bignum temp2;
	bigset(temp2, 405);

	bignum temp3;
	biginit(temp3);

	bignum temp4;
	biginit(temp4);

	bignum temp5;
	biginit(temp5);

	int i;

	for(i = 1; i < 15; i++)
	{
		bigmulint(temp3,bigadd(temp3, temp1, temp2), 7695);

		bigsetbig(temp4, temp1);
		bigsetbig(temp5, temp2);

		bigadd(temp1, bigmulint(temp1, temp1, 81), bigmulint(temp5, temp5, 1805));
		bigadd(temp2, bigmulint(temp2, temp2, 5890), bigmulint(temp4, temp4, 7614));

		if(croaks[i] == 'P')
			bigmulint(temp1, temp1, 2);

		else
			bigmulint(temp2, temp2, 2);
			
		bigmul(numerator, numerator, bigadd(temp4, temp1, temp2));
		bigmul(denominator, denominator, bigmulint(temp3,temp3,3));

		char string1[1000];
		char string2[1000];
		biggetstr(string1, numerator);
		biggetstr(string2, denominator);
		printf("%s/%s\n", string1, string2);
	}

	char string1[1000];
	char string2[1000];
	biggetstr(string1, numerator);
	biggetstr(string2, denominator);
	printf("%s/%s\n", string1, string2);

	return 0;
}
