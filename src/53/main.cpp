#include <stdio.h>

#include "bignum.h"

//According to euler, an efficient way to solve this
//is to just generate the first 100 rows of 
//pascal's triangle

bignum factorials[101];

bignum_ * bigfactorial(int n, bignum ret)
{
	if(biglength(factorials[n]) > 0)
		return bigsetbig(ret, factorials[n]);

	return bigsetbig(ret, bigmulint(factorials[n], bigfactorial(n-1, factorials[n]), n));
}

void UpdateProgress(int count)
{
	printf("\rProgress: %d%%", count);
}

int main()
{
	printf("PE 53\n");

	memset(factorials, 0, sizeof(bignum)*101);
	bigset(factorials[0], 1);
	bigset(factorials[1], 1);
	bigset(factorials[2], 2);

	char numstring[200];

	int count = 0;
	int percentCount = 0;

	int n;
	int r;

	bignum numerator;
	bignum denominator;
	bignum temp;

	for(n = 1; n <= 100; n++)
	{
		for(r = 2; r <= n; r++)
		{
			bigfactorial(n, numerator);
			bigfactorial(r, denominator);
			bigfactorial(n-r, temp);
			bigmul(denominator, denominator, temp);
			bigdiv(temp, numerator, denominator);
			if(biglength(temp) > 6)
				count++;
		}

		UpdateProgress(++percentCount);
	}

	printf("\nAnswer: %d\n", count);

	return 0;
}
