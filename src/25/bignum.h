#include <string.h>

#define DIGITS 1000

typedef struct 
{
	char num[DIGITS];
	int pos;
	int base;
} bignum_;
	
typedef bignum_ bignum[1];

bignum_ * biginit(bignum ret);
bignum_ * bigset(bignum ret, int num);
bignum_ * bigsetbig(bignum ret, bignum num);
char * biggetstr(char * ret, bignum num);
int biglength(bignum b);
bignum_ * bigmul(bignum ret, bignum mul1, bignum mul2);
bignum_ * bigadd(bignum ret, bignum add1, bignum add2);	
