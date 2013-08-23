#include "bignum.h"

bignum_ * bigmulint(bignum ret, bignum mul1, int mul2)
{
	bignum temp;
	bigset(temp, mul2);

	return bigmul(ret, mul1, temp);
}

bignum_ * bigmul(bignum ret, bignum mul1, bignum mul2)
{
	bignum temp;
	int i, j, carry = 0, base = mul1->base;

	biginit(temp); //num must be zeroed

	for(i = 0; i < mul1->pos; ++i)
	{
		for(j = 0; j < mul2->pos; ++j)
		{
			temp->num[j+i] += mul1->num[i] * mul2->num[j] + carry;
			carry = temp->num[j+i] / base;
			temp->num[j+i] %= base;
		}

		while(carry)
		{
			temp->num[j+i] = carry % base;
			carry /= base;
			++j;
		}
		
		if(i+j > temp->pos) //pos should be farthest position
			temp->pos = i+j;
	}

	temp->base = base;
	return bigsetbig(ret, temp);
}

bignum_ * bigshiftright(bignum n)
{
	memcpy(n->num, (n->num)+1, DIGITS);
	return n;
}

bignum_ * bigdiv(bignum ret, bignum dividend, bignum divisor)
{
	//Only works for exact division with whole number quotients
	//Uses base 7 for division

	char InvModsBase7[] = {-1, 1, 4, 5, 2, 3, 6};
	int Qd = 0, DDd = 0, DVd = 0;
	int ModInv;

	int DivisionBase = 7;

	bignum Temp;
	biginit(Temp);
	bigconvertbase10toB(Temp, DivisionBase);
	
	bignum DigitOffset;
	bigset(DigitOffset, 1);
	bigconvertbase10toB(DigitOffset, DivisionBase);

	bignum Quotient;
	biginit(Quotient);
	Quotient->base = 7;

	bignum dividendTemp;
	bigsetbig(dividendTemp, dividend);

	bignum divisorTemp;
	bigsetbig(divisorTemp, divisor);

	bigconvertbase10toB(dividendTemp, 7);
	bigconvertbase10toB(divisorTemp, 7);

	while(divisorTemp->num[0] == 0)
	{
		bigshiftright(dividendTemp);
		bigshiftright(divisorTemp);
	}

	ModInv = InvModsBase7[divisorTemp->num[0]];

	while(!isZero(dividendTemp))
	{
		Quotient->num[Qd] = (dividendTemp->num[DDd] * ModInv) % DivisionBase;
		bigmulint(Temp, divisorTemp, Quotient->num[Qd]);
		bigmul(Temp, Temp, DigitOffset);
		bigsubtract(dividendTemp, dividendTemp, Temp);

		Qd++; DDd++; bigmulint(DigitOffset, DigitOffset, 10);
	}

	Quotient->pos = Qd;
	bigconvertbaseBto10(Quotient);
	return bigsetbig(ret, Quotient);
}

bignum_ * bigpow(bignum ret, bignum base, int exponent)
{
	bignum result;
	bigset(result, 1);

	for(exponent; exponent; exponent--)
		bigmul(result, result, base);

	return bigsetbig(ret, result);
}

bignum_ * bigaddint(bignum ret, bignum add1, int add2)
{
	bignum temp;
	bigset(temp, add2);

	return bigadd(ret, add1, temp);
}

bignum_ * bigadd(bignum ret, bignum add1, bignum add2)
{
	int i, temp, carry = 0, base = add1->base;
	
	int max = (add1->pos > add2->pos) ? add1->pos : add2->pos;
	
	for(i = 0; i < max; ++i)
	{
		temp = add1->num[i] + add2->num[i] + carry;
		ret->num[i] = temp % base;
		carry = temp / base;
	}
	
	while(carry > 0)
	{
		ret->num[i] += carry % base;
		carry /= base;
		++i;
	}
	
	ret->pos = i;

	return ret;
}

bignum_ * bigsubtractint(bignum ret, bignum subtract1, int subtract2)
{
	bignum temp;
	bigset(temp, subtract2);

	return bigsubtract(ret, subtract1, temp);
}

void borrow(bignum num, int pos)
{
	if(num->num[pos+1] == 0)
		borrow(num, pos+1);

	num->num[pos] += num->base;
	num->num[pos+1]--;

	if(num->num[num->pos-1] == 0)
		num->pos--;
}

bignum_ * bigsubtract(bignum ret, bignum subtract1, bignum subtract2)
{
	int i;
	int temp;

	bignum subtemp;
	bigsetbig(subtemp, subtract1);

	bignum difference;
	biginit(difference);
	
	for(i = 0; i < subtemp->pos; ++i)
	{
		if(subtemp->num[i] < subtract2->num[i])
			borrow(subtemp, i);

		temp = subtemp->num[i] - subtract2->num[i];
		 
		difference->num[i] = temp;
	}

	while(difference->num[--i] == 0 && i != 0);
	difference->pos = i+1;
	difference->base = subtract1->base;

	return bigsetbig(ret, difference);
}


bignum_ * biginit(bignum ret)
{
	ret->pos = 1;
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

bignum_ * bigsetstr(bignum ret, char * num)
{
	int i;

	biginit(ret);

	int len = strlen(num)-1;

	for(i = 0 ; i <= len; ++i)
		ret->num[i] = num[len-i] - '0';

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
	ret->pos = num->pos;
	memcpy(ret->num, num->num, num->pos);

	return ret;
}

char biggreaterthan(bignum a, bignum b)
{
	int p = a->pos-1;

	if(a->pos > b->pos) return 1;
	else if(a->pos < b->pos) return 0;
	
	while(a->num[p] == b->num[p] && p>=0)
		p--;

	if(p<0) return 0;

	return (a->num[p] > b->num[p]) ? 1 : 0;
}

char biggreaterthanorequal(bignum a, bignum b)
{
	int p = a->pos-1;

	if(a->pos > b->pos) return 1;
	else if(a->pos < b->pos) return 0;
	
	while(a->num[p] == b->num[p] && p>=0)
		p--;

	if(p<0) return 1;

	return (a->num[p] > b->num[p]) ? 1 : 0;
}

char isZero(bignum n)
{
	return (n->pos == 1 && n->num[0] == 0) ? 1 : 0;
}

int biglength(bignum b)
{
	return b->pos;
}

bignum_ * bigconvertbaseBto10(bignum num)
{
	bignum place;
	bigset(place, 1);

	bignum result;
	biginit(result);
	
	bignum temp;
	biginit(temp);

	int i;
	for(i = 0; i < num->pos; i++)
	{
		bigset(temp, num->num[i]);
		bigadd(result, result, bigmul(temp, temp, place));

		bigmulint(place, place, num->base);
	}

	result->base = 10;
	return bigsetbig(num, result);
}

bignum_ * bigconvertbase10toB(bignum num, int base)
{
	bignum temp, bigbase, result;

	if(num->base == base) return num;

	bigset(bigbase, base);
	biginit(result);
	int exponent = 0, count;

	do
	{
		bigpow(temp, bigbase, exponent);
		exponent++;
	}
	while(biggreaterthanorequal(num, temp));

	exponent--;
	result->pos = exponent;
	exponent--;

	if(exponent < 0) return biginit(num);

	while(exponent >= 0)
	{
		bigpow(temp, bigbase, exponent);
		count = 0;
		while(biggreaterthanorequal(num, temp))
		{
			bigsubtract(num, num, temp);
			count++;
		}

		result->num[exponent] = count;

		exponent--;
	}

	result->base = base;
	return bigsetbig(num, result);;
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
