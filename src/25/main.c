#include <stdio.h>
#include "bignum.h"

int main()
{
	bignum x;
	bignum y;
	bignum temp;

	bigset(x, 1);
	bigset(y, 1);

	int i;
	for(i = 3; ; i++)
	{
		bigsetbig(temp, x);
		bigadd(x, x, y);
		bigsetbig(y, temp);

		if(biglength(x) == 1000)
			break;
	}

	printf("%d\n", i);

	return 0;
}
