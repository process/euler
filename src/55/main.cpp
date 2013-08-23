#include <stdio.h>
#include "bignum.h"

//unsigned long long ReverseAdd(unsigned long long n)
//{
//	unsigned long long ret = 0;
//	unsigned long long div = 1, mod = 10, moddiv = 1;
//
//	while(n / div) div *= 10;
//	div /= 10;
//
//	while(div)
//	{
//		ret += (((n/div)%10)+((n%mod)/moddiv))*moddiv;
//		div /= 10;
//		mod *= 10;
//		moddiv *= 10;
//	}
//
//	return ret;
//}

void ReverseAdd(bignum n)
{
	bignum ret;
	biginit(ret);

	bignum mul;
	bigset(mul, 1);

	bignum temp;
	biginit(temp);

	int i;
	for(i = 0; i < n->pos; i++, bigmulint(mul, mul, 10))
		bigadd(ret, ret, bigmulint(temp, mul, n->num[i] + n->num[n->pos-(i+1)]));

	bigsetbig(n, ret);
}

int isPalindrome(bignum n)
{
	int i;
	for(i = 0; i < n->pos/2; i++)
		if(n->num[i] != n->num[n->pos-i-1])
			return 0;

	return 1;
}

int main()
{
	int n, i, count = 0;

	bignum num;

	for(n = 10; n < 10000; n++)
	{
		bigset(num, n);

		for(i = 0; i < 50; i++)
		{
			ReverseAdd(num);
			if(isPalindrome(num))
				break;
		}

		if(i == 50)
			count++;
	}

	printf("%d\n", count);

	return 0;
}
