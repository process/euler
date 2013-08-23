#include <stdio.h>
#include <math.h>

#define MAX 5000

long long PentagonalNums[MAX];

void getpentagonals(int limit)
{
	long long n;
	for(n = 1; n < limit; n++)
		PentagonalNums[n-1] = n*(3*n-1)/2;
}

//old method (by me)
//char isPentagonal(int n)
//{
//	int i;
//	for(i = 0; i < MAX; i++)
//		if(PentagonalNums[i] == n) return 1;
//
//	return 0;
//}

//better method (ripped from PE forum) (comes from quadratic formula):
char isPentagonal(int n)
{
	double f;
	f = ((1 + sqrt((double)1+24*n))/3);
	if (f - int(f) == 0)
		return 1;
	else
		return 0;
}

int main()
{
	getpentagonals(MAX);

	int i,j;
	int answer = 0;

	for(i = 0; i < MAX; i++)
	{
		for(j = i+1; j < MAX; j++)
		{
			if(isPentagonal(PentagonalNums[i] + PentagonalNums[j]) &&
				isPentagonal(PentagonalNums[j] - PentagonalNums[i]))
			{
				answer = PentagonalNums[j] - PentagonalNums[i];
				break;
			}
		}

		if(answer) break;
	}

	printf("%d\n", answer);

	return 0;
}
