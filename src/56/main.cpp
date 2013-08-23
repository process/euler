#include <stdio.h>
#include "bignum.h"

int main()
{
	int base;
	int exponent;
	int sum;
	int maxsum = 0;

	bignum temp;
	bignum sumtemp;

	for(base = 2; base < 100; base++)
	{
		bigset(temp, 1);
		for(exponent = 1; exponent < 100; exponent++)
		{
			bigmulint(temp, temp, base);
			bigdigitsum(sumtemp, temp);
			sum = biggetint(sumtemp);

			if(sum > maxsum)
				maxsum = sum;
		}
	}

	printf("%d\n", maxsum);

	return 0;
}
