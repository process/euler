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
	long long ans;

	ans = pow_10d(2, 7830457);
	ans *= 28433;
	ans += 1;
	ans %= 10000000000;

	printf("%lld\n", ans);

	return 0;
}
