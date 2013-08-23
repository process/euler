#include <stdio.h>

#define MAX 1000000

long long TriangleNums[MAX];
long long PentagonalNums[MAX];
long long HexagonalNums[MAX];

//Triangle numbers don't need to be tested,
//because all triangle numbers are also
//hexagonal numbers

void gettriangles(int limit)
{
	long long n;
	for(n = 0; n < limit; n++)
		TriangleNums[n] = n*(n+1)/2;
}

void getpentagonals(int limit)
{
	long long n;
	for(n = 0; n < limit; n++)
		PentagonalNums[n] = n*(3*n-1)/2;
}

void gethexagonals(int limit)
{
	long long n;
	for(n = 0; n < limit; n++)
		HexagonalNums[n] = n*(2*n-1);
}

int main()
{
	unsigned int n, i, success = 0;

	gettriangles(MAX);
	getpentagonals(MAX);
	gethexagonals(MAX);

	for(n = 286; n < MAX; n++)
	{
		for(i = 166; i < MAX; i++)
		{
			if(TriangleNums[n] == PentagonalNums[i])
				for(i = 144; i < MAX; i++)
				{
					if(TriangleNums[n] == HexagonalNums[i])
						success = 1;
				}
		}

		if(success)
			break;
	}

	printf("%lld\n", TriangleNums[n]);

	return 0;
}
