#include <stdio.h>

int main()
{
	int prod = 1, currentint = 0, digit = 1, totaldigits = 0; 
	int a, b; //temp vars

	while(digit <= 1000000)
	{
		for( ; totaldigits < digit; )
		{
			a = ++currentint;
			do {totaldigits++;} while(a /= 10);
		}

		b = 1;
		for(a = totaldigits-digit; a > 0; a--)
			b*=10;

		prod *= (currentint/b)%10;
		digit *= 10;
	}

	printf("%d\n", prod);

	return 0;
}
