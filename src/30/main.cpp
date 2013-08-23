#include <stdio.h>

int powers[] = {0, 1, 32, 243, 1024, 3125, 7776, 16807, 32768, 59049};

//max bound can be detemined by x * 9^5 < 10^(x-1)
//where x is the number of digits
//7 * 9^5 is less than 1000000, so the maximum number must be
//below 1000000

int main()
{
	int a, s, n, sum = 0;

	for(n = 2; n < 1000000; n++)
	{
		s = 0;
		a = n;

		while(a > 0)
		{
			s += powers[a % 10];
			a /= 10;
		}

		if(s == n)
			sum += n;
	}

	printf("%d\n", sum);

	return 0;
}
