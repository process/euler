#include <stdio.h>

long long pow_10d(long long a, int x) //return last 10 digits of a^x as long long.
{
	long long result = 1;

	for(x; x > 0; x--)
	{
		result *= a;
		result %= 10000000000;
	}

	return result;
}

int main()
{
	long long result = 0;

	int a;
	for(a = 1; a < 1001; a++)
		result += pow_10d(a,a);

	printf("%lld\n", result % 10000000000);
	     
	return 0;
}
