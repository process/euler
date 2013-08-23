#include "stdio.h"
#include "math.h"

int main()
{
	double a, b, c;
	int p, maxp;
	int count = 0, maxcount = 0;

	for(p = 12; p <= 1000; p++, count = 0)
	{
		for(a = 1; a < p; a++)
		{
			for(b = a; a + b < p; b++)
			{
				c = sqrt(a*a + b*b);
				if(c - (int)c == 0 && a+b+c == p)
					count++;
			}
		}

		if(count > maxcount)
		{
			maxcount = count;
			maxp = p;
		}
	}

	printf("%d\n", maxp);

	return 0;
}
