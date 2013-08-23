#include <stdio.h>
#include "bignum.h"

void fac(bignum num, int factor)
{
	int i;
	bignum temp;

	for(i = 2; i <= factor; i++)
	{
		bigset(temp, i, 10);
		bigmul(num, num, temp);
	}
}

void adddigits(bignum ret, bignum num)
{
	int i;
	bignum temp;

	for(i = 0; i < num->pos; i++)
	{
		bigset(temp, num->num[i], 10);
		bigadd(ret, ret, temp);
	}
}

int main(int argc, char * argv[])
{
	bignum num;
	bignum digitsum;
	char text[1000];

	bigset(num, 1, 10);
	bigset(digitsum, 0, 10);

	fac(num, 100);
	adddigits(digitsum, num);

	biggetstr(text, digitsum);
	printf("%s\n", text);

	return 0;
}
