#include <stdio.h>

int main()
{
	int i = 1;
	int sum = 1;
	int gap = 2;
	int count = 0;

	while(i < 1001*1001)
	{
		i+=gap;
		sum+=i;
		count++;
		if(count == 4)
		{
			gap+=2;
			count=0;
		}
	}

	printf("%d\n", sum);

	return 0;
}
