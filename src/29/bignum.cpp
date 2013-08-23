#include "bignum.h"

bignum_ * bigmul(bignum ret, bignum mul1, bignum mul2)
{
	bignum temp;
	int i, j, carry = 0;

	biginit(temp); //num must be zeroed

	for(i = 0; i < mul1->pos; ++i)
	{
		for(j = 0; j < mul2->pos; ++j)
		{
			temp->num[j+i] += mul1->num[i] * mul2->num[j] + carry;
			carry = temp->num[j+i] / 10;
			temp->num[j+i] %= 10;
		}

		while(carry)
		{
			temp->num[j+i] = carry % 10;
			carry /= 10;
			++j;
		}
		
		if(i+j > temp->pos) //pos should be farthest position
			temp->pos = i+j;
	}

	bigsetbig(ret, temp);
	return ret;
}

bignum_ * bigpow(bignum ret, bignum base, int exponent)
{
	bignum result;
	bigset(result, 1);

	for(exponent; exponent; exponent--)
		bigmul(result, result, base);

	bigsetbig(ret, result);
	return ret;
}

bignum_ * bigadd(bignum ret, bignum add1, bignum add2)
{
	int i;
	int temp;
	int carry = 0;
	
	int max = (add1->pos > add2->pos) ? add1->pos : add2->pos;
	
	for(i = 0; i < max; ++i)
	{
		temp = add1->num[i] + add2->num[i] + carry;
		ret->num[i] = temp % 10;
		carry = temp / 10;
	}
	
	while(carry > 0)
	{
		ret->num[i] += carry % 10;
		carry /= 10;
		++i;
	}
	
	ret->pos = i;

	return ret;
}

bignum_ * biginit(bignum ret)
{
	ret->pos = 0;
	ret->base = 10;
	memset(ret->num, 0, DIGITS);

	return ret;
}

bignum_ * bigset(bignum ret, int num)
{
	int i;

	biginit(ret);

	for(i = 0 ; num > 0; ++i)
	{
		ret->num[i] = num % 10;
		num /= 10;	
	}

	if(i == 0)
		i = 1;
	
	ret->pos = i; //after last digit
	ret->base = 10;
	
	return ret;
}

bignum_ * bigsetbig(bignum ret, bignum num)
{
	biginit(ret);

	ret->base = num->base;
	ret->pos = num ->pos;
	memcpy(ret->num, num->num, num->pos);

	return ret;
}

int biglength(bignum b)
{
	return b->pos;
}

char * biggetstr(char * ret, bignum num)
{
	int i;
	int j;
	for(i=num->pos-1, j=0; i >= 0; --i, ++j)
		ret[j] = num->num[i]+'0';
	
	ret[num->pos] = 0;
	
	return ret;
}
