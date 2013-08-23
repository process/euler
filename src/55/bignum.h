#include <string.h>
#include <math.h>

#define DIGITS 1000

typedef struct 
{
	char num[DIGITS];
	int pos;
	int base;
} bignum_;
	
typedef bignum_ bignum[1];

bignum_ * biginit(bignum ret);
char biggreaterthan(bignum a, bignum b);
char biggreaterthanorequal(bignum a, bignum b);
char isZero(bignum n);
bignum_ * bigset(bignum ret, int num);
bignum_ * bigsetstr(bignum ret, char * num); 
bignum_ * bigsetbig(bignum ret, bignum num); 
char * biggetstr(char * ret, bignum num); 
int biggetint(bignum num);
int biglength(bignum b); 
bignum_ * bigconvertbase10toB(bignum num, int base);
bignum_ * bigconvertbaseBto10(bignum num);
bignum_ * bigmul(bignum ret, bignum mul1, bignum mul2); 
bignum_ * bigmulint(bignum ret, bignum mul1, int mul2); 
bignum_ * bigpow(bignum ret, bignum base, int exponent);
bignum_ * bigshiftright(bignum n);
bignum_ * bigdiv(bignum ret, bignum dividend, bignum divisor);
bignum_ * bigadd(bignum ret, bignum add1, bignum add2); 
bignum_ * bigaddint(bignum ret, bignum add1, int add2);
bignum_ * bigdigitsum(bignum ret, bignum num);
bignum_ * bigsubtract(bignum ret, bignum subtract1, bignum subtract2); 
bignum_ * bigsubtractint(bignum ret, bignum subtract1, int subtract2);
