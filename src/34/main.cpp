#include <stdio.h>

int factorials[10] =
{
	1,
	1,
	1*2,
	1*2*3,
	1*2*3*4,
	1*2*3*4*5,
	1*2*3*4*5*6,
	1*2*3*4*5*6*7,
	1*2*3*4*5*6*7*8,
	1*2*3*4*5*6*7*8*9,
};

int main()
{
	int total = 0;
	int i,n,ntotal;

	for(i = 11; i < 1000000; i++)
	{
		n = i;
		ntotal = 0;

		while(n>0)
		{
			ntotal += factorials[n%10];
			n/=10;
		}

		if(ntotal == i)
			total+=i;
	}

	printf("%d\n", total);
	return 0;
}
